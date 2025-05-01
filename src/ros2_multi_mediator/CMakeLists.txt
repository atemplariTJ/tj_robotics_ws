cmake_minimum_required(VERSION 3.8)
project(ros2_multi_mediator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c++17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

include_directories(
  include
)

add_executable(unified_node
  src/unified_node.cpp
  src/sensor_mediator_part.cpp
  src/motion_mediator_part.cpp
  src/main.cpp
)

ament_target_dependencies(unified_node
  rclcpp
  std_msgs
)

install(TARGETS
  unified_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
