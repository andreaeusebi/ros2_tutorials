# python_ros_pkg/python_pub_node.py

import rclpy
from rclpy.node import Node
from my_msgs_pkg.msg import Sphere
from geometry_msgs.msg import Point

class PythonPubNode(Node):
    def __init__(self):
        super().__init__('python_sub_node')
        self.publisher_ = self.create_publisher(Sphere, 'sphere_topic', 10)
        self.timer = self.create_timer(1.0, self.publish_sphere)

    def publish_sphere(self):
        msg = Sphere()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.header.frame_id = 'world'
        msg.center = Point(x=1.0, y=2.0, z=3.0)
        msg.radius = 0.5

        self.publisher_.publish(msg)

        self.get_logger().info('Sphere Message Published!')

def main(args=None):
    rclpy.init(args=args)
    node = PythonPubNode()
    rclpy.spin(node)
    rclpy.shutdown()
