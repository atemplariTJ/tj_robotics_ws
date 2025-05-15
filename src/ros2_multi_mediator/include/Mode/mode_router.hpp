#ifndef MODE_ROUTER_HPP
#define MODE_ROUTER_HPP

#include "mode_logic.hpp"
#include <map>

class ModeRouter {
public:
    void registerLogic(RobotMode mode, std::shared_ptr<IModeLogic> logic) {
        logic_map_[mode] = logic;
    }

    void tick(RobotMode mode) {
        if (logic_map_.count(mode)) logic_map_[mode]->onTick();
    }

private:
    std::map<RobotMode, std::shared_ptr<IModeLogic>> logic_map_;
};

#endif // MODE_ROUTER_HPP