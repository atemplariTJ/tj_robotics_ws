#pragma once
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MotionMediatorPart {
public:
    MotionMediatorPart(rclcpp::Node* node);
    void publishCommand(const std::string& command);

private:
    rclcpp::Node* node_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr cmd_vel_pub_;
};