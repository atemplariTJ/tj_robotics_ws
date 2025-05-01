#include "mediator/sensor_mediator_part.hpp"

SensorMediatorPart::SensorMediatorPart(rclcpp::Node* node) : node_(node), enabled_(true) {
    lidar_sub_ = node_->create_subscription<std_msgs::msg::String>(
        "/sensor/lidar", 10,
        std::bind(&SensorMediatorPart::lidarCallback, this, std::placeholders::_1)
    );
}

void SensorMediatorPart::registerErasedComponent(const std::string& topic, std::shared_ptr<IErasedComponent> component) {
    topic_subscribers_[topic].push_back(component);
}

void SensorMediatorPart::lidarCallback(const std_msgs::msg::String::SharedPtr msg) {
    if (!enabled_) return;
    auto topic = "/sensor/lidar";
    if (topic_subscribers_.count(topic)) {
        for (auto& comp : topic_subscribers_[topic]) {
            comp->call(static_cast<void*>(msg.get()));
        }
    }
}

void SensorMediatorPart::enable() {
    enabled_ = true;
    RCLCPP_INFO(node_->get_logger(), "SensorMediator enabled");
}

void SensorMediatorPart::disable() {
    enabled_ = false;
    RCLCPP_INFO(node_->get_logger(), "SensorMediator disabled");
}