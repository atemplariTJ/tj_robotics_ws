#ifndef __MODE_LOGIC_HPP__
#define __MODE_LOGIC_HPP__
#include <rclcpp/rclcpp.hpp>

enum class RobotMode { LEADER, FOLLOWER };

class IModeLogic {
public:
    virtual ~IModeLogic() = default;
    virtual void onTick() = 0;
};

class LeaderMode : public IModeLogic {
public:
    void onTick() override {
        RCLCPP_INFO(rclcpp::get_logger("LeaderMode"), "Leader tick logic");
    }
};

class FollowerMode : public IModeLogic {
public:
    void onTick() override {
        RCLCPP_INFO(rclcpp::get_logger("FollowerMode"), "Follower tick logic");
    }
};

#endif