#include "rclcpp/rclcpp.hpp"
#include "my_msgs_pkg/msg/sphere.hpp"

class CppPubNode : public rclcpp::Node
{
    public:
        CppPubNode() : Node("cpp_pub_node")
        {
            m_publisher = this->create_publisher<my_msgs_pkg::msg::Sphere>("sphere_topic", 10);

            m_timer = this->create_wall_timer(std::chrono::seconds(1),
                                              std::bind(&CppPubNode::publishSphere, this));
        }

    private:

        void publishSphere()
        {
            auto msg = my_msgs_pkg::msg::Sphere();

            // Header
            msg.header.stamp = this->now();
            msg.header.frame_id = "world";

            // Center
            msg.center.x = 1.0;
            msg.center.y = 2.0;
            msg.center.z = 3.0;

            // Radius
            msg.radius = 0.5;

            m_publisher->publish(msg);

            RCLCPP_INFO_STREAM(this->get_logger(), "Sphere Message Published!");
        }

        rclcpp::Publisher<my_msgs_pkg::msg::Sphere>::SharedPtr m_publisher;
        rclcpp::TimerBase::SharedPtr m_timer;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    auto node = std::make_shared<CppPubNode>();
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}
