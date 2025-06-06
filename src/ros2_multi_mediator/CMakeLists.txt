cmake_minimum_required(VERSION 3.8)
project(ros2_multi_mediator)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -std=c++17)
endif()

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(nav2_msgs REQUIRED)

include_directories(
  include
)

add_executable(unified_node
  src/main.cpp
)

ament_target_dependencies(unified_node
  rclcpp
  std_msgs
  geometry_msgs
  sensor_msgs
  nav2_msgs
)

install(TARGETS
  unified_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
