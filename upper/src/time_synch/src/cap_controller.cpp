#include "common_config/config.h"
#include "sensor_msgs/msg/joy.hpp"
#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
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

#define DEFAULT_SAVE_COUNT 2        // 默认保存图像数量
#define TIME_SYNCH_THERSOLD 20      // 时间同步阈值，单位为毫秒

#define STR_HELPER(x) #x
#define STR(x) STR_HELPER(x)
#define CAMERA_TOPIC_NAME(x) "camera" #x "_" STR(server_port) "_image"

using namespace message_filters::sync_policies; // 同步策略
using namespace std::chrono_literals;           // 时间单位

int8_t start_flag;
int8_t stop_flag;
int8_t last_start_flag;
int8_t last_stop_flag;

class JoySubscriber : public rclcpp::Node
{
public:
    JoySubscriber() : Node("joy_subscriber_node")
    {
        subscription_ = this->create_subscription<sensor_msgs::msg::Joy>(
            "joy", 10, std::bind(&JoySubscriber::joy_callback, this, std::placeholders::_1));
        RCLCPP_INFO(this->get_logger(), "Joystick Subscriber Node 已启动，正在等待数据...");
    }
private:
    void joy_callback(const sensor_msgs::msg::Joy::SharedPtr msg)
    {
        last_start_flag = start_flag;
        last_stop_flag = stop_flag;
        start_flag = msg->buttons[4];
        stop_flag = msg->buttons[5];
        RCLCPP_INFO(this->get_logger(), "start_flag: %d, stop_flag: %d", start_flag, stop_flag);
    }

    rclcpp::Subscription<sensor_msgs::msg::Joy>::SharedPtr subscription_;
};

class CameraSyncNode : public rclcpp::Node
{
public:
    CameraSyncNode() : Node("camera_sync_node"), capture_flag_(false), image_count_(0), save_count_(DEFAULT_SAVE_COUNT)
    {
        // 声明并初始化参数
        this->declare_parameter("camera1_topic", CAMERA_TOPIC_NAME(1));
        this->declare_parameter("camera2_topic", CAMERA_TOPIC_NAME(2));
        this->declare_parameter("camera3_topic", CAMERA_TOPIC_NAME(3));
        this->declare_parameter("camera4_topic", CAMERA_TOPIC_NAME(4));
        this->declare_parameter("stitched_image_topic", "stitched_" STR(server_port) "_image");
        this->declare_parameter("save_directory", "./image");
        this->declare_parameter("save_count", DEFAULT_SAVE_COUNT);

        // 获取参数值
        camera1_topic_ = this->get_parameter("camera1_topic").as_string();
        camera2_topic_ = this->get_parameter("camera2_topic").as_string();
        camera3_topic_ = this->get_parameter("camera3_topic").as_string();
        camera4_topic_ = this->get_parameter("camera4_topic").as_string();
        stitched_image_topic_ = this->get_parameter("stitched_image_topic").as_string();
        save_directory_ = this->get_parameter("save_directory").as_string();
        save_count_ = this->get_parameter("save_count").as_int();

        // 订阅相机的图像话题
        sub1_.subscribe(this, camera1_topic_);
        sub2_.subscribe(this, camera2_topic_);
        sub3_.subscribe(this, camera3_topic_);
        sub4_.subscribe(this, camera4_topic_);

        // 创建用于发布拼接图像的发布器
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
    int save_count_;

    // 同步回调函数，用于处理同步后的图像
    void syncCallback(const sensor_msgs::msg::Image::ConstSharedPtr& image1,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image2,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image3,
                        const sensor_msgs::msg::Image::ConstSharedPtr& image4)
    {
        if (!capture_flag_) {
            return;
        }
        if (image_count_ >= save_count_) {
            capture_flag_ = false;
            return;
        }

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

    void connectToServer() {
        while (rclcpp::ok()) {
            // 对不同命令的处理
            while (rclcpp::ok()) {
                if (start_flag == 1){
                    RCLCPP_INFO(this->get_logger(), "Start!!!");
                    system("ros2 run img_capture appsink1 & echo $! > /tmp/appsink1.pid");
                    system("ros2 run img_capture appsink2 & echo $! > /tmp/appsink2.pid");
                    system("ros2 run img_capture appsink3 & echo $! > /tmp/appsink3.pid");
                    system("ros2 run img_capture appsink4 & echo $! > /tmp/appsink4.pid");
                    capture_flag_ = true;
                    image_count_ = 0;
                    std::this_thread::sleep_for(5s);
                }
                else if (stop_flag == 1)
                {
                    system("fuser -k /dev/video0");
                    system("fuser -k /dev/video2");
                    system("fuser -k /dev/video4");
                    system("fuser -k /dev/video6");
                    RCLCPP_INFO(this->get_logger(), "Camera stopped, ROS nodes terminated.");
                    capture_flag_ = false;
                }
            }
        }
    }

    rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr stitched_image_publisher_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub1_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub2_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub3_;
    message_filters::Subscriber<sensor_msgs::msg::Image> sub4_;
    std::shared_ptr<message_filters::
                    Synchronizer<ApproximateTime<sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image, 
                                                 sensor_msgs::msg::Image>>> sync_;

    int image_count_;
    std::atomic<bool> capture_flag_;
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
    rclcpp::spin(std::make_shared<JoySubscriber>());
    rclcpp::spin(std::make_shared<CameraSyncNode>());
    rclcpp::shutdown();
    return 0;
}
