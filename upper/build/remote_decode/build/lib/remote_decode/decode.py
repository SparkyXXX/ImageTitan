#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import pygame
import sys

class PS2ControllerNode(Node):
    def __init__(self):
        super().__init__('ps2_controller_node')

        # 发布到 /joy 话题，消息类型为 sensor_msgs/Joy，话题名为 'joy'
        self.publisher_ = self.create_publisher(Joy, 'joy', 10)

        pygame.init()
        pygame.joystick.init()
        joystick_count = pygame.joystick.get_count()
        if joystick_count == 0:
            self.get_logger().error('未检测到PS2手柄,请检查手柄是否连接')
            sys.exit(1)
        self.joystick = pygame.joystick.Joystick(0) # 只连接一个手柄
        self.joystick.init()
        self.get_logger().info(f"检测到手柄: {self.joystick.get_name()}")

        # 创建定时器，用于持续读取手柄数据并发布，频率为10Hz
        self.timer = self.create_timer(0.1, self.publish_joy_data)

    def publish_joy_data(self):
        try:
            pygame.event.pump()
            axes = [self.joystick.get_axis(i) for i in range(self.joystick.get_numaxes())]
            buttons = [self.joystick.get_button(i) for i in range(self.joystick.get_numbuttons())]

            # 创建 Joy 消息对象并填充数据
            joy_msg = Joy()
            joy_msg.header.stamp = self.get_clock().now().to_msg()
            joy_msg.axes = axes
            joy_msg.buttons = buttons

            self.publisher_.publish(joy_msg)
            # self.get_logger().info(f"Axes (摇杆): {axes[0], axes[1], axes[3], axes[4]}")
            # self.get_logger().info(f"Buttons (按键): {buttons[0], buttons[1], buttons[2], buttons[3], buttons[4], buttons[5]}")
        except Exception as e:
            self.get_logger().error(f"读取手柄数据时出错: {e}")

def main(args=None):
    rclpy.init(args=args)
    node = PS2ControllerNode()

    try:    
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
