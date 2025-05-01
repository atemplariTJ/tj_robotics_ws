#pragma once
#include "rclcpp/rclcpp.hpp"
#include "mediator/sensor_mediator_part.hpp"
#include "mediator/motion_mediator_part.hpp"
#include "component/component_interface.hpp"
#include "component/example_component.hpp"
#include "std_msgs/msg/string.hpp"

enum class RobotState {
    LEADER,
    FOLLOWER
};

class UnifiedMediatorNode : public rclcpp::Node {
public:
    UnifiedMediatorNode();

private:
    void switchState(RobotState new_state);
    void handleLeaderLogic();
    void handleFollowerLogic();

    SensorMediatorPart sensor_mediator_;
    MotionMediatorPart motion_mediator_;
    RobotState current_state_;

    std::shared_ptr<ComponentWrapper<std_msgs::msg::String>> example_component_wrapper_;
};