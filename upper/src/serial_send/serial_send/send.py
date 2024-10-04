#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import rclpy
from rclpy.node import Node
from sensor_msgs.msg import Joy
import serial

wheel_spd_coed = -1.5

class SerialSenderNode(Node):
    def __init__(self):
        super().__init__('serial_sender_node')

        # 创建订阅者，订阅 /joy 话题
        self.subscription = self.create_subscription(Joy, 'joy', self.joy_callback, 10)
        self.get_logger().info("Joystick Subscriber Node 已启动，正在等待数据...")
        self.serial_port = serial.Serial('/dev/ttyUSB0', 115200, timeout=1)
        self.get_logger().info("串口已打开: /dev/ttyUSB0")

    def joy_callback(self, joy_msg):
        wheel_spd = joy_msg.axes[1] * wheel_spd_coed
        servo_pos = joy_msg.axes[0] * -30.0 + 90.0
        self.send_to_serial(wheel_spd, servo_pos)

    def send_to_serial(self, wheel_spd, servo_pos):
        data = f"H,{wheel_spd:.2f},{servo_pos:.2f},X"
        self.serial_port.write(data.encode())
        self.get_logger().info(f"发送数据到串口: {data.strip()}")

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
