#include "rclcpp/rclcpp.hpp"
#include "my_srvs_pkg/srv/divide_integers.hpp"
#include <chrono>
#include <cstdlib>
#include <ctime>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);

    auto node = rclcpp::Node::make_shared("cpp_custom_client");
    auto client = node->create_client<my_srvs_pkg::srv::DivideIntegers>("divide_integers");

    while (!client->wait_for_service(1s) && rclcpp::ok())
    {
        RCLCPP_INFO(node->get_logger(), "Waiting for service...");
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    rclcpp::Rate loop_rate(0.5);  // one request every 2 seconds

    while (rclcpp::ok())
    {
        auto request = std::make_shared<my_srvs_pkg::srv::DivideIntegers::Request>();

        // Randomly generate dividend and divisor as integers between 0 and 10
        request->dividend = std::rand() % 11;
        request->divisor = std::rand() % 11;

        RCLCPP_INFO(node->get_logger(),"Sending request: %ld / %ld",
                    request->dividend, request->divisor);

        // Call the service asynchronously (function is not blocking)
        auto future = client->async_send_request(request);

        if (rclcpp::spin_until_future_complete(node, future) ==
            rclcpp::FutureReturnCode::SUCCESS)
        {
            auto response = future.get();
            if (response->success)
            {
                RCLCPP_INFO(node->get_logger(), "Success: %s", response->message.c_str());
            }
            else
            {
                RCLCPP_WARN(node->get_logger(), "Failed: %s", response->message.c_str());
            }
        }
        else
        {
            RCLCPP_ERROR(node->get_logger(), "Failed to call service.");
        }

        loop_rate.sleep();
    }

    rclcpp::shutdown();
    return 0;
}
