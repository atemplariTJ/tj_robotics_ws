#include "SensorDataReaderOne.hpp"

SensorDataReaderOne::SensorDataReaderOne(const rclcpp::NodeOptions & node_options) : Node("Mgs04_mooc",node_options)
{

    this->timer_=this->create_wall_timer(5ms,std::bind(&SensorDataReaderOne::TestFuncfion,this));


    this->over_count_image=0;
    this->over_count_imu=0;
    this->over_count_point=0;
    publisher_     = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel",10);

}

void SensorDataReaderOne::TestFuncfion()
{
    auto st_time = this->get_clock()->now();
    // 1. allocate Read Data
    geometry_msgs::msg::Twist msg;
    msg.linear.x = 1.0;


    // 2. Get Imu Data from SHM
    publisher_->publish(msg);

}



int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<SensorDataReaderOne>();

  rclcpp::executors::MultiThreadedExecutor exec;

  exec.add_node(node);
  exec.spin();

  rclcpp::shutdown();

  return 0;
}
