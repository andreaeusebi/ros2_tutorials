import rclpy
from rclpy.node import Node
from my_srvs_pkg.srv import DivideIntegers

class PyCustomServer(Node):
    def __init__(self):
        super().__init__('py_custom_server')
        self.srv = self.create_service(DivideIntegers, 'divide_integers', self.divide_callback)
        self.get_logger().info('DivideIntegers service is up and running.')

    def divide_callback(self, request, response):
        dividend = request.dividend
        divisor = request.divisor

        if divisor == 0:
            response.result = 0
            response.success = False
            response.message = "Division by zero is not allowed."
        elif dividend % divisor != 0:
            response.result = 0
            response.success = False
            response.message = f"{dividend} is not exactly divisible by {divisor}."
        else:
            response.result = dividend // divisor
            response.success = True
            response.message = f"{dividend} divided by {divisor} is {response.result}."

        self.get_logger().info(f"Request processed.")

        return response

def main(args=None):
    rclpy.init(args=args)
    node = PyCustomServer()
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()
