#ifndef PLOTJUGGLER_MSGS__DATA_POINTS_HPP_
#define PLOTJUGGLER_MSGS__DATA_POINTS_HPP_

#include <plotjuggler_msgs/msg/data_points.hpp>

namespace plotjuggler_msgs
{
struct DataPoints : public plotjuggler_msgs::msg::DataPoints
{
  DataPoints();
  DataPoints(uint32_t dictionary_uuid){
    this->dictionary_uuid = dictionary_uuid;
  }

  void push_back(const plotjuggler_msgs::msg::DataPoint& data_point){
    this->samples.push_back(data_point);
  }
  const plotjuggler_msgs::msg::DataPoints& msg() const {
    return static_cast<const plotjuggler_msgs::msg::DataPoints&>(*this);
  }
  plotjuggler_msgs::msg::DataPoints& msg() {
    return static_cast< plotjuggler_msgs::msg::DataPoints&>(*this);
  }
};
}  // namespace plotjuggler_msgs
#endif  // PLOTJUGGLER_MSGS__DATA_POINTS_HPP_