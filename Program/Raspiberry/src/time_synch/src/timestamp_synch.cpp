// 时间同步与回传通信
#include "common_config/config.h"
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <sensor_msgs/msg/joy.hpp>
#include <std_msgs/msg/bool.hpp>
#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/approximate_time.h>
#include <opencv2/opencv.hpp>
#include <cv_bridge/cv_bridge.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <atomic>
#include <filesystem>
#include <fstream>

#define DEFAULT_SAVE_COUNT 20       // 默认保存图像数量
#define TIME_SYNCH_THERSOLD 20      // 时间同步阈值，单位为毫秒

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define CAMERA_TOPIC_NAME(x) "camera" #x "_" STR(server_port) "_image"

using namespace message_filters::sync_policies; // 同步策略
using namespace std::chrono_literals;           // 时间单位

class CameraSyncNode : public rclcpp::Node
{
public:
    CameraSyncNode() : Node("camera_sync_node"), capture_flag_(false), image_count_(0)
    {
        single_test_image_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "camera1_10003_image", 10, std::bind(&CameraSyncNode::single_test_image_callback, this, std::placeholders::_1));

        capture_flag_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "capture_flag", 10, std::bind(&CameraSyncNode::capture_flag_callback, this, std::placeholders::_1));
        pc_flag_publisher_ = this->create_publisher<std_msgs::msg::Bool>("pc_flag", 10);
        img_flag_publisher_ = this->create_publisher<std_msgs::msg::Bool>("img_flag", 10);

        // 声明并初始化参数
        this->declare_parameter("camera1_topic", CAMERA_TOPIC_NAME(1));
        this->declare_parameter("camera2_topic", CAMERA_TOPIC_NAME(2));
        this->declare_parameter("camera3_topic", CAMERA_TOPIC_NAME(3));
        this->declare_parameter("camera4_topic", CAMERA_TOPIC_NAME(4));
        this->declare_parameter("stitched_image_topic", "stitched_" STR(server_port) "_image");
        this->declare_parameter("save_directory", "./image");

        // 获取参数值
        camera1_topic_ = this->get_parameter("camera1_topic").as_string();
        camera2_topic_ = this->get_parameter("camera2_topic").as_string();
        camera3_topic_ = this->get_parameter("camera3_topic").as_string();
        camera4_topic_ = this->get_parameter("camera4_topic").as_string();
        stitched_image_topic_ = this->get_parameter("stitched_image_topic").as_string();
        save_directory_ = this->get_parameter("save_directory").as_string();

        // 订阅相机的图像话题
        sub1_.subscribe(this, camera1_topic_);
        sub2_.subscribe(this, camera2_topic_);
        sub3_.subscribe(this, camera3_topic_);
        sub4_.subscribe(this, camera4_topic_);
        stitched_image_publisher_ = this->create_publisher<sensor_msgs::msg::Image>(stitched_image_topic_, 10);

        // 设置消息同步器，并将同步后的回调函数注册
        sync_ = std::make_shared
        <message_filters::Synchronizer<ApproximateTime<
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image>>>(
            ApproximateTime<
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image, 
                sensor_msgs::msg::Image>(TIME_SYNCH_THERSOLD),
            sub1_, sub2_, sub3_, sub4_);
        sync_->registerCallback(&CameraSyncNode::syncCallback, this);

        if (!std::filesystem::exists(save_directory_))
        {
            std::filesystem::create_directories(save_directory_);
        }
        std::thread(&CameraSyncNode::connectToServer, this).detach();
    }

private:
    // 订阅 capture_flag 状态的回调函数
    void capture_flag_callback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        capture_flag_ = msg->data;
    }

    // 单摄像头测试
    void single_test_image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        std_msgs::msg::Bool pc_flag_msg;
        std_msgs::msg::Bool img_flag_msg;
        if (capture_flag_)
        {
            // 指示灯刷新
            pc_flag_msg.data = false;
            img_flag_msg.data = true;
            pc_flag_publisher_->publish(pc_flag_msg);
            img_flag_publisher_->publish(img_flag_msg);

            // 将 ROS 图像消息转换为 OpenCV 图像
            cv_bridge::CvImagePtr cv_ptr;
            try
            {
                cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
            }
            catch (cv_bridge::Exception& e)
            {
                RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
                return;
            }

            // 保存图像到本地
            std::string filename = save_directory_ + "/" + "image_" + std::to_string(image_count_) + ".jpg";
            cv::imwrite(filename, cv_ptr->image);
            RCLCPP_INFO(this->get_logger(), "Saved image %d to %s", image_count_, filename.c_str());
            image_count_++;  // 更新保存图像计数
        }
        else
        {
            // 指示灯刷新
            pc_flag_msg.data = true;
            img_flag_msg.data = false;
            pc_flag_publisher_->publish(pc_flag_msg);
            img_flag_publisher_->publish(img_flag_msg);       
        }
    }

    // 同步回调函数，用于处理同步后的图像
    void syncCallback(const sensor_msgs::msg::Image::ConstSharedPtr& image1,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image2,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image3,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image4)
    {
        std_msgs::msg::Bool pc_flag_msg;
        std_msgs::msg::Bool img_flag_msg;
        if (!capture_flag_) 
        {
            // 指示灯刷新
            pc_flag_msg.data = true;
            img_flag_msg.data = false;
            pc_flag_publisher_->publish(pc_flag_msg);
            img_flag_publisher_->publish(img_flag_msg);        
            // if (!save_directory_.empty()) 
            // {
            //     sendAllImagesToServer();
            //     deleteLocalImages();
            // }
            return;
        }

        // 指示灯刷新
        pc_flag_msg.data = false;
        img_flag_msg.data = true;
        pc_flag_publisher_->publish(pc_flag_msg);
        img_flag_publisher_->publish(img_flag_msg);

        // 计算时时间戳的平均值
        int64_t nanosec1 = image1->header.stamp.sec * 1000000000LL + image1->header.stamp.nanosec;
        int64_t nanosec2 = image2->header.stamp.sec * 1000000000LL + image2->header.stamp.nanosec;
        int64_t nanosec3 = image3->header.stamp.sec * 1000000000LL + image3->header.stamp.nanosec;
        int64_t nanosec4 = image4->header.stamp.sec * 1000000000LL + image4->header.stamp.nanosec;
        int64_t avg_nanosec = (nanosec1 + nanosec2 + nanosec3 + nanosec4) / 4;
        int64_t avg_sec = avg_nanosec / 1000000000LL;
        avg_nanosec = avg_nanosec % 1000000000LL;
        rclcpp::Time avg_time(avg_sec, avg_nanosec);
        std::string timestamp_str = std::to_string(avg_time.seconds());
        
        cv_bridge::CvImagePtr cv_ptr1, cv_ptr2, cv_ptr3, cv_ptr4;
        try
        {
            cv_ptr1 = cv_bridge::toCvCopy(image1, sensor_msgs::image_encodings::BGR8);
            cv_ptr2 = cv_bridge::toCvCopy(image2, sensor_msgs::image_encodings::BGR8);
            cv_ptr3 = cv_bridge::toCvCopy(image3, sensor_msgs::image_encodings::BGR8);
            cv_ptr4 = cv_bridge::toCvCopy(image4, sensor_msgs::image_encodings::BGR8);
        }
        catch (cv_bridge::Exception& e)
        {
            RCLCPP_ERROR(this->get_logger(), "cv_bridge exception: %s", e.what());
            return;
        }

        // 拼接图像并保存
        cv::Mat image1_cv = cv_ptr1->image;
        cv::Mat image2_cv = cv_ptr2->image;
        cv::Mat image3_cv = cv_ptr3->image;
        cv::Mat image4_cv = cv_ptr4->image;
        cv::Mat top_row, bottom_row, stitched_image;
        cv::hconcat(image1_cv, image2_cv, top_row);
        cv::hconcat(image3_cv, image4_cv, bottom_row);
        cv::vconcat(top_row, bottom_row, stitched_image);

        std::string file_name = save_directory_ + "/" STR(server_port) "_" +  timestamp_str + ".jpg";
        cv::imwrite(file_name, stitched_image);
        RCLCPP_INFO(this->get_logger(), "Saved image %d to %s", image_count_, file_name.c_str());
        image_count_++;
    }

    int sock;
    void connectToServer() {
        while (rclcpp::ok()) {
            struct sockaddr_in serv_addr;

            // 创建socket
            if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
                RCLCPP_ERROR(this->get_logger(), "Socket creation error");
                std::this_thread::sleep_for(5s);
                continue;
            }
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(server_port);
            // 将IP地址转换为二进制形式
            if (inet_pton(AF_INET, server_ip, &serv_addr.sin_addr) <= 0) {
                RCLCPP_ERROR(this->get_logger(), "Invalid address/ Address not supported");
                close(sock);
                std::this_thread::sleep_for(5s);
                continue;
            }
            // 尝试连接到服务器
            if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
                RCLCPP_ERROR(this->get_logger(), "Connection failed");
                close(sock);
                std::this_thread::sleep_for(5s);
                continue;
            }
            RCLCPP_INFO(this->get_logger(), "Successfully connected to server");

            // 对不同命令的处理
            while (rclcpp::ok()) {
                char buffer[1024] = {0};
                int valread = read(sock, buffer, 1024);
                if (valread > 0) {
                   ;
                } else {
                    RCLCPP_INFO(this->get_logger(), "Disconnected from server, reconnecting...");
                    close(sock);
                    break;
                }
            }
        }
    }

    // 发送单张图像
    void sendImageToServer(const std::string& img_path) {
        cv::Mat img = cv::imread(img_path, cv::IMREAD_COLOR);
        if (img.empty()) {
            RCLCPP_ERROR(this->get_logger(), "Failed to read image: %s", img_path.c_str());
            return;
        }

        // 发送文件名长度和文件名
        std::string filename = std::filesystem::path(img_path).filename().string();
        int filename_size = filename.size();
        std::string filename_length_str = std::to_string(filename_size);
        filename_length_str.insert(filename_length_str.begin(), 4 - filename_length_str.length(), ' ');
        if (send(sock, filename_length_str.c_str(), 4, 0) == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to send filename length for: %s", img_path.c_str());
            return;
        }
        if (send(sock, filename.c_str(), filename_size, 0) == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to send filename for: %s", img_path.c_str());
            return;
        }

        // 编码图像
        std::vector<uchar> img_encode;
        if (!cv::imencode(".jpg", img, img_encode)) {
            RCLCPP_ERROR(this->get_logger(), "Failed to encode image: %s", img_path.c_str());
            return;
        }

        // 发送图像大小
        int img_size = img_encode.size();
        const uchar* img_data = img_encode.data();
        std::string length_str = std::to_string(img_size);
        length_str.insert(length_str.begin(), 16 - length_str.length(), ' ');
        RCLCPP_INFO(this->get_logger(), "Sending image size: %d", img_size);
        if (send(sock, length_str.c_str(), 16, 0) == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to send image size for: %s", img_path.c_str());
            return;
        }

        // 发送图像数据，每次1024字节
        for (int i = 0; i < img_size; i += 1024) {
            int bytes_sent = send(sock, img_data + i, std::min(1024, img_size - i), 0);
            if (bytes_sent == -1) {
                RCLCPP_ERROR(this->get_logger(), "Failed to send image data for: %s", img_path.c_str());
                return;
            }
            // RCLCPP_INFO(this->get_logger(), "Sent %d bytes of image data", bytes_sent);
        }

        // 等待服务器确认接收到图像
        char buffer[1024] = {0};
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            RCLCPP_ERROR(this->get_logger(), "Failed to receive acknowledgment for: %s", img_path.c_str());
            return;
        }
        RCLCPP_INFO(this->get_logger(), "Received acknowledgment: %s", buffer);
        if (std::string(buffer).find("ok") != std::string::npos) {
            RCLCPP_INFO(this->get_logger(), "Sent image: %s successfully", img_path.c_str());
        } else {
            RCLCPP_ERROR(this->get_logger(), "Failed to send image: %s", img_path.c_str());
        }
    }

    // 发送目录下的所有图像
    void sendAllImagesToServer() {
        for (const auto &entry : std::filesystem::directory_iterator(save_directory_)) {
            if (entry.is_regular_file()) {
                std::string file_path = entry.path().string();
                RCLCPP_INFO(this->get_logger(), "Sending image: %s", file_path.c_str());
                sendImageToServer(file_path);
            } else {
                RCLCPP_WARN(this->get_logger(), "Skipped non-file entry: %s", entry.path().string().c_str());
            }
        }
    }

    // 删除本地保存的图像
    void deleteLocalImages() {
        if (std::filesystem::exists(save_directory_)) {
            for (const auto& entry : std::filesystem::directory_iterator(save_directory_)) {
                if (entry.is_regular_file()) {
                    try {
                        std::filesystem::remove(entry.path());
                        RCLCPP_INFO(this->get_logger(), "Deleted image: %s", entry.path().c_str());
                    } catch (const std::filesystem::filesystem_error& e) {
                        RCLCPP_ERROR(this->get_logger(), "Error deleting file %s: %s", entry.path().c_str(), e.what());
                    }
                }
            }
            RCLCPP_INFO(this->get_logger(), "All images deleted.");
        } else {
            RCLCPP_WARN(this->get_logger(), "Save directory does not exist: %s", save_directory_.c_str());
        }
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr stitched_image_publisher_;
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr single_test_image_subscriber_;
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr capture_flag_subscriber_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr pc_flag_publisher_;
    rclcpp::Publisher<std_msgs::msg::Bool>::SharedPtr img_flag_publisher_;

    message_filters::Subscriber<sensor_msgs::msg::Image> sub1_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub2_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub3_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub4_;
    std::shared_ptr<message_filters::
                    Synchronizer<ApproximateTime<sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image>>> sync_;

    bool capture_flag_;
    int image_count_;
    std::string save_directory_;
    std::string camera1_topic_;
    std::string camera2_topic_;
    std::string camera3_topic_;
    std::string camera4_topic_;
    std::string stitched_image_topic_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraSyncNode>());
    rclcpp::shutdown();
    return 0;
}
