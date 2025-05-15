#ifndef STATE_ROUTER_HPP
#define STATE_ROUTER_HPP
#include "state_logic.hpp"
#include <map>

class StateRouter {
public:
    void registerLogic(RobotState state, std::shared_ptr<IStateLogic> logic) {
        logic_map_[state] = logic;
    }

    void routePose(RobotState state, const PoseMsg::SharedPtr& msg) {
        if (logic_map_.count(state)) logic_map_[state]->onPose(msg);
    }

private:
    std::map<RobotState, std::shared_ptr<IStateLogic>> logic_map_;
};
#endif // STATE_ROUTER_HPP