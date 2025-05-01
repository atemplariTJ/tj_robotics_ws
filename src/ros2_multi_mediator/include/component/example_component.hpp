#pragma once
#include "component_interface.hpp"
#include "std_msgs/msg/string.hpp"
#include <iostream>

class ExampleComponent : public ComponentInterface<std_msgs::msg::String> {
public:
    void onMessageReceived(std::shared_ptr<std_msgs::msg::String> msg) override {
        std::cout << "[ExampleComponent] Received data: " << msg->data << std::endl;
    }
};