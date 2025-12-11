#include <iostream>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <random>
#include <cmath>
#include "plotjuggler_msgs/dictionary.hpp"
#include "plotjuggler_msgs/data_point.hpp"
#include "plotjuggler_msgs/data_points.hpp"

using namespace std::chrono_literals;

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = rclcpp::Node::make_shared("pj_test");

  auto publisher_dict = node->create_publisher<plotjuggler_msgs::msg::Dictionary>("pj_msg_dictionary",
                                                                         rclcpp::QoS(10).transient_local());
  auto publisher = node->create_publisher<plotjuggler_msgs::msg::DataPoints>("pj_msg_data", 10);

  std::random_device rd;
  const uint32_t UUID = rd(); // just a random number

  plotjuggler_msgs::Dictionary dictionary(UUID);
  dictionary.push_back("sensor_a"); // index 0
  dictionary.push_back("sensor_b"); // index 1
  dictionary.push_back("sensor_c"); // index 2

  publisher_dict->publish(dictionary.msg());


  rclcpp::WallRate loop_rate(50ms);
  double t=0;
  while (rclcpp::ok()) {

    t += 0.1;
    plotjuggler_msgs::DataPoints points(UUID);
    points.samples.push_back( plotjuggler_msgs::DataPoint(0, t, std::sin(t)).msg());
    points.samples.push_back( plotjuggler_msgs::DataPoint(1, t, std::cos(t)).msg());
    points.samples.push_back( plotjuggler_msgs::DataPoint(2, t, 2*std::cos(t)).msg());

    publisher->publish(points.msg());
    rclcpp::spin_some(node);
    loop_rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}
