#include "unified_node.hpp"

UnifiedMediatorNode::UnifiedMediatorNode()
: Node("unified_mediator_node"),
  sensor_mediator_(this),
  motion_mediator_(this),
  current_state_(RobotState::FOLLOWER) {
    auto example_component = std::make_shared<ExampleComponent>();
    example_component_wrapper_ = std::make_shared<ComponentWrapper<std_msgs::msg::String>>(example_component);
    sensor_mediator_.registerErasedComponent("/sensor/lidar", example_component_wrapper_);

    this->create_wall_timer(
        std::chrono::seconds(10),
        [this]() {
            if (current_state_ == RobotState::FOLLOWER) {
                switchState(RobotState::LEADER);
            } else {
                switchState(RobotState::FOLLOWER);
            }
        }
    );
}

void UnifiedMediatorNode::switchState(RobotState new_state) {
    if (current_state_ != new_state) {
        current_state_ = new_state;
        if (current_state_ == RobotState::LEADER) {
            RCLCPP_INFO(this->get_logger(), "Switched to LEADER state");
            motion_mediator_.publishCommand("Leader Active");
            handleLeaderLogic();
        } else {
            RCLCPP_INFO(this->get_logger(), "Switched to FOLLOWER state");
            motion_mediator_.publishCommand("Follower Active");
            handleFollowerLogic();
        }
    }
}

void UnifiedMediatorNode::handleLeaderLogic() {
    sensor_mediator_.enable();
    motion_mediator_.publishCommand("Navigating to goal as leader");
}

void UnifiedMediatorNode::handleFollowerLogic() {
    sensor_mediator_.disable();
    motion_mediator_.publishCommand("Waiting for leader direction");
}