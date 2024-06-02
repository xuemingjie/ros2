from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    t1 = Node(package="xiaomi",executable="xiaomi_use",name="t1")
    t2 = Node(package="xiaomi",executable="xiaomi_sub",name="t2")

    
    return LaunchDescription([t1,t2])