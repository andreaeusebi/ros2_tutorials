#include "rclcpp/rclcpp.hpp"
#include "my_srvs_pkg/srv/divide_integers.hpp"

void handle_service(
    const std::shared_ptr<my_srvs_pkg::srv::DivideIntegers::Request> request,
    std::shared_ptr<my_srvs_pkg::srv::DivideIntegers::Response> response)
{
    int64_t dividend = request->dividend;
    int64_t divisor = request->divisor;

    if (divisor == 0)
    {
        response->result = 0;
        response->success = false;
        response->message = "Division by zero is not allowed.";
    }
    else if (dividend % divisor != 0)
    {
        response->result = 0;
        response->success = false;
        response->message = std::to_string(dividend) + " is not exactly divisible by " +
                            std::to_string(divisor) + ".";
    }
    else
    {
        response->result = dividend / divisor;
        response->success = true;
        response->message = std::to_string(dividend) + " divided by " +
                            std::to_string(divisor) + " is " +
                            std::to_string(response->result) + ".";
    }

    RCLCPP_INFO(rclcpp::get_logger("cpp_custom_server"), "Request processed.");
}

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("cpp_custom_server");

    auto service = node->create_service<my_srvs_pkg::srv::DivideIntegers>("divide_integers",
                                                                          &handle_service);

    RCLCPP_INFO(node->get_logger(), "DivideIntegers service is ready.");

    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}
