#pragma once
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "component/component_interface.hpp"
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>

class SensorMediatorPart {
public:
    SensorMediatorPart(rclcpp::Node* node);
    void registerErasedComponent(const std::string& topic, std::shared_ptr<IErasedComponent> component);
    void enable();
    void disable();

private:
    void lidarCallback(const std_msgs::msg::String::SharedPtr msg);
    rclcpp::Node* node_;
    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr lidar_sub_;
    std::unordered_map<std::string, std::vector<std::shared_ptr<IErasedComponent>>> topic_subscribers_;
    bool enabled_ = true;
};