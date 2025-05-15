#include "rclcpp/rclcpp.hpp"
#include "unified_node.hpp"

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    auto node = std::make_shared<UnifiedMediatorNode>();
    rclcpp::spin(node);
    //yes

    rclcpp::shutdown();
    return 0;
}
