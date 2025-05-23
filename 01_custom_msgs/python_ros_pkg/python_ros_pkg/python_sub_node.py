# python_ros_pkg/python_sub_node.py

import rclpy
from rclpy.node import Node
from my_msgs_pkg.msg import Sphere

class PythonSubNode(Node):
    def __init__(self):
        super().__init__('python_sub_node')
        self.subscription = self.create_subscription(
            Sphere,
            'sphere_topic',
            self.listener_callback,
            10
        )

    def listener_callback(self, msg):
        self.get_logger().info(
            f'Received Sphere Message:\n'
            f'  stamp = {msg.header.stamp.sec}.{msg.header.stamp.nanosec}\n'
            f'  frame_id = {msg.header.frame_id}\n'
            f'  center = ({msg.center.x}, {msg.center.y}, {msg.center.z})\n'
            f'  radius = {msg.radius}'
        )

def main(args=None):
    rclpy.init(args=args)
    node = PythonSubNode()
    rclpy.spin(node)
    rclpy.shutdown()
