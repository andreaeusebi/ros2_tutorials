#include "rclcpp/rclcpp.hpp"
#include "my_msgs_pkg/msg/sphere.hpp"

class CppSubNode : public rclcpp::Node
{
    public:
        CppSubNode() : Node("sphere_subscriber")
    {
        subscription_ = this->create_subscription<my_msgs_pkg::msg::Sphere>(
            "sphere_topic",
            10,
            std::bind(&CppSubNode::callback, this, std::placeholders::_1)
        );
    }

    private:
        void callback(const my_msgs_pkg::msg::Sphere::SharedPtr msg)
        {
            RCLCPP_INFO_STREAM(this->get_logger(),
                "Received Sphere Message!\n"
                << "  Header:\n"
                << "    stamp = " << msg->header.stamp.sec << "." << msg->header.stamp.nanosec << "\n"
                << "    frame_id = " << msg->header.frame_id << "\n"
                << "  Center:\n"
                << "    x = " << msg->center.x << ", y = " << msg->center.y << ", z = " << msg->center.z << "\n"
                << "  Radius = " << msg->radius
            );
        }

        rclcpp::Subscription<my_msgs_pkg::msg::Sphere>::SharedPtr subscription_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CppSubNode>());
  rclcpp::shutdown();
  return 0;
}
