#include "rclcpp/rclcpp.hpp"
#include "Mode/mode_router.hpp"
#include "Mode/mode_logic.hpp"

#include "State/state_router.hpp"
#include "State/state_logic.hpp"



class UnifiedMediatorNode : public rclcpp::Node {
public:
    UnifiedMediatorNode() : Node("unified_mediator_node") {
        // 모드 로직 등록
        mode_router_.registerLogic(RobotMode::LEADER, std::make_shared<LeaderMode>());
        mode_router_.registerLogic(RobotMode::FOLLOWER, std::make_shared<FollowerMode>());

        // 상태 로직 등록
        state_router_.registerLogic(RobotState::B, std::make_shared<StateB>());

        // 타이머
        timer_ = this->create_wall_timer(std::chrono::seconds(1), [this]() {
            mode_router_.tick(current_mode_);
        });

        // subscriber
        pose_sub_ = this->create_subscription<PoseMsg>("/pose", 10, [this](PoseMsg::SharedPtr msg) {
            state_router_.routePose(current_state_, msg);
        });
    }

private:
    RobotMode current_mode_ = RobotMode::FOLLOWER;
    RobotState current_state_ = RobotState::B;

    ModeRouter mode_router_;
    StateRouter state_router_;

    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Subscription<PoseMsg>::SharedPtr pose_sub_;
};
