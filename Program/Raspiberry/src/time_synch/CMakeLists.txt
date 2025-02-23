cmake_minimum_required(VERSION 3.5)
project(time_synch)

# 寻找依赖的包
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(message_filters REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(CURL REQUIRED)
find_package(OpenCV REQUIRED)
find_package(common_config REQUIRED)

# 添加包含文件路径
include_directories(
  include
  ${rclcpp_INCLUDE_DIRS}
  ${sensor_msgs_INCLUDE_DIRS}
  ${message_filters_INCLUDE_DIRS}
  ${cv_bridge_INCLUDE_DIRS}
  ${CURL_INCLUDE_DIRS}
  ${common_config_INCLUDE_DIRS}
)

# 创建可执行文件
add_executable(timestamp_synch src/timestamp_synch.cpp)

# 链接依赖的库
ament_target_dependencies(timestamp_synch
  rclcpp
  sensor_msgs
  message_filters
  cv_bridge
  OpenCV
)

target_link_libraries(timestamp_synch
  ${OpenCV_LIBRARIES}
  ${CURL_LIBRARIES}
)

# 安装可执行文件
install(TARGETS
  timestamp_synch
  DESTINATION lib/${PROJECT_NAME}
)

# 声明 ROS 2 软件包
ament_package()
