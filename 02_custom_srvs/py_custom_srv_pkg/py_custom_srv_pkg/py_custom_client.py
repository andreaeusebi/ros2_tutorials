import rclpy
from rclpy.node import Node
from my_srvs_pkg.srv import DivideIntegers
import random

class PyCustomClient(Node):
    def __init__(self):
        super().__init__('py_custom_client')
        self.client = self.create_client(DivideIntegers, 'divide_integers')

        while not self.client.wait_for_service(timeout_sec=1.0):
            self.get_logger().info('Waiting for service to become available...')
        
        self.get_logger().info('Service is available.')

        # Timer to send requests every 2 seconds
        self.timer = self.create_timer(2.0, self.timer_callback)

    def timer_callback(self):
        dividend = random.randint(0, 10)
        divisor = random.randint(0, 10)

        self.get_logger().info(f"Sending request: {dividend} / {divisor}")

        request = DivideIntegers.Request()
        request.dividend = dividend
        request.divisor = divisor

        # Call the service asynchronously (function is not blocking)
        self.future = self.client.call_async(request)

        # When Response is ready, automatically call response_callback() method
        self.future.add_done_callback(self.response_callback)

    def response_callback(self, future):
        response = future.result()
        if response.success:
            self.get_logger().info(f"Success: {response.message}")
        else:
            self.get_logger().warn(f"Failed: {response.message}")

def main(args=None):
    rclpy.init(args=args)
    node = PyCustomClient()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
