#ifndef STATE_LOGIC_HPP
#define STATE_LOGIC_HPP

#include <rclcpp/rclcpp.hpp>
#include "geometry_msgs/msg/pose_stamped.hpp"

using PoseMsg = geometry_msgs::msg::PoseStamped;

enum class RobotState { A, B, C };

class IStateLogic {
public:
    virtual ~IStateLogic() = default;
    virtual void onPose(const PoseMsg::SharedPtr&) {}
};

class StateB : public IStateLogic {
public:
    void onPose(const PoseMsg::SharedPtr& msg) override {
        RCLCPP_INFO(rclcpp::get_logger("StateB"), "Received Pose: x=%.2f y=%.2f", msg->pose.position.x, msg->pose.position.y);
    }
};
#endif // STATE_LOGIC_HPP