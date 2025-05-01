#include "mediator/motion_mediator_part.hpp"

MotionMediatorPart::MotionMediatorPart(rclcpp::Node* node) : node_(node) {
    cmd_vel_pub_ = node_->create_publisher<std_msgs::msg::String>("/cmd_vel", 10);
}

void MotionMediatorPart::publishCommand(const std::string& command) {
    auto msg = std_msgs::msg::String();
    msg.data = command;
    cmd_vel_pub_->publish(msg);
}