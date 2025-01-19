// 时间同步与回传通信
#include "common_config/config.h"
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
#include <sensor_msgs/msg/joy.hpp>
#include <std_msgs/msg/bool.hpp>  // 导入 Bool 消息类型


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
        image_subscriber_ = this->create_subscription<sensor_msgs::msg::Image>(
            "camera1_10003_image", 10, std::bind(&CameraSyncNode::image_callback, this, std::placeholders::_1));
        capture_flag_subscriber_ = this->create_subscription<std_msgs::msg::Bool>(
            "capture_flag", 10, std::bind(&CameraSyncNode::capture_flag_callback, this, std::placeholders::_1));
        if (!std::filesystem::exists("saved_images"))
        {
            std::filesystem::create_directory("saved_images");
        }
    }

private:
    void capture_flag_callback(const std_msgs::msg::Bool::SharedPtr msg)
    {
        capture_flag_ = msg->data;  // 根据收到的 capture_flag 状态来控制采集
        if (capture_flag_)
        {
            RCLCPP_INFO(this->get_logger(), "Capture flag set to TRUE - Start image capture");
        }
        else
        {
            RCLCPP_INFO(this->get_logger(), "Capture flag set to FALSE - Stop image capture");
        }
    }

    // 同步回调函数，用于处理同步后的图像
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg)
    {
        if (capture_flag_)
        {
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
            std::string filename = "saved_images/image_" + std::to_string(image_count_) + ".jpg";
            cv::imwrite(filename, cv_ptr->image);
            RCLCPP_INFO(this->get_logger(), "Saved image %d to %s", image_count_, filename.c_str());
            image_count_++;  // 更新保存图像计数
        }
    }
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr image_subscriber_;  // 订阅图像数据
    rclcpp::Subscription<std_msgs::msg::Bool>::SharedPtr capture_flag_subscriber_;  // 订阅 capture_flag 状态
    bool capture_flag_;
    int image_count_;
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<CameraSyncNode>());
    rclcpp::shutdown();
    return 0;
}
