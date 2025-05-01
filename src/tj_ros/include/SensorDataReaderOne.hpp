
#ifndef SENSOR_DATA_READER_1_HPP_
#define SENSOR_DATA_READER_1_HPP_

#include "rclcpp/rclcpp.hpp"

#include "geometry_msgs/msg/pose_stamped.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "cv_bridge/cv_bridge.h"
#include "opencv2/opencv.hpp"

// For argument
#include "rcutils/cmdline_parser.h"
#include <string>
#include <memory>
#include <bitset>

#include <chrono>
#include <thread>
#include <deque>


using std::placeholders::_1;
using std::placeholders::_2;
using namespace std::chrono_literals;



#define __FILENAME__ (strchr(__FILE__,'\\') ? strchr(__FILE__,'\\')+1:__FILE__)
#define LINEDEBUG RCLCPP_INFO(this->get_logger(), "E : [FILE : %s] [FUNCTION : %s] [LINE : %d] \n\r", __FILENAME__,__FUNCTION__,__LINE__)


class SensorDataReaderOne : public rclcpp::Node
{
    public :
        explicit SensorDataReaderOne(const rclcpp::NodeOptions & node_options=rclcpp::NodeOptions());
        virtual ~SensorDataReaderOne(){}

    private : 

        void TestFuncfion();
         rclcpp::TimerBase::SharedPtr timer_;

        uint32_t over_count_imu;
        uint32_t over_count_point;
        uint32_t over_count_image;
 
        rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
        rclcpp::Subscription<geometry_msgs::msg::Pose>::SharedPtr sub_tf;
        

};

#endif //SENSOR_DATA_READER_1_HPP_