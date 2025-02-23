#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
from std_msgs.msg import Bool
import serial
import struct

class SerialSenderNode(Node):
    def __init__(self):
        super().__init__('serial_sender_node')
        
        self.subscription = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        self.get_logger().info("Joystick Subscriber Node 已启动，正在等待数据...")
        self.serial_port = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
        self.get_logger().info("串口已打开: /dev/ttyUSB0")

        # 初始化 pc_flag 和 img_flag
        self.pc_flag = False
        self.img_flag = False
        self.pc_flag_subscriber = self.create_subscription(Bool, 'pc_flag', self.pc_flag_callback, 10)
        self.img_flag_subscriber = self.create_subscription(Bool, 'img_flag', self.img_flag_callback, 10)

    def pc_flag_callback(self, msg):
        self.pc_flag = msg.data

    def img_flag_callback(self, msg):
        self.img_flag = msg.data

    def joy_callback(self, joy_msg):
        vel = joy_msg.axes[1]
        ang = joy_msg.axes[0]
        self.send_to_serial(vel, ang)

    def send_to_serial(self, vel, ang):
        header = 0xA5
        vel_bytes = struct.pack('<f', vel)  # 使用小端序存储 float
        ang_bytes = struct.pack('<f', ang)  # 使用小端序存储 float
        control_mode = 1  # 假设 control_mode 为 1
        flags = (self.pc_flag << 7) | (self.img_flag << 6) | (control_mode << 5)
        footer = 0x5A
        data = bytes([header]) + vel_bytes + ang_bytes + bytes([flags]) + bytes([footer])
        self.serial_port.write(data)

    def destroy_node(self):
        self.serial_port.close()
        self.get_logger().info("串口已关闭")
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = SerialSenderNode()

    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()
