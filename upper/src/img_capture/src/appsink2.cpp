// 图像获取
#include "common_config/config.h"
#include "../include/img_capture/image_capture.hpp"

#define CAMERA_DEVICE "/dev/video2"
#define CAMERA_NUM "camera2_"

static GMainLoop *loop = nullptr;
static void signal_handler(int signum);

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    auto node = rclcpp::Node::make_shared(CAMERA_NUM + std::to_string(server_port) + "_publisher");
    auto publisher = node->create_publisher<sensor_msgs::msg::Image>(CAMERA_NUM + std::to_string(server_port) + "_image", 10);
    if (!publisher) {
        g_printerr("Error: Failed to create publisher\n");
        return -1;
    }
    signal(SIGINT, signal_handler);
    gst_init(&argc, &argv);
    loop = g_main_loop_new(NULL, FALSE);
    run_camera_stream(CAMERA_DEVICE, std::string(CAMERA_NUM) + "topic", loop, publisher);
    return 0;
}

// 接收到信号时退出主循环
static void signal_handler(int signum)
{
    if (loop != nullptr) {
        g_main_loop_quit(loop);
    }
}

