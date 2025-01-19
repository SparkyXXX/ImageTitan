from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='img_capture',
            executable='appsink1',
        ),
        Node(
            package='img_capture',
            executable='appsink2',
        ),
        Node(
            package='img_capture',
            executable='appsink3',
        ),
        Node(
            package='img_capture',
            executable='appsink4',
        ),
        # Node(
        #     package='img_capture',
        #     executable='synch_img',
        # ),
    ])
