#ifndef PLOTJUGGLER_MSGS__DATA_POINT_HPP_
#define PLOTJUGGLER_MSGS__DATA_POINT_HPP_

#include <plotjuggler_msgs/msg/data_point.hpp>

namespace plotjuggler_msgs
{
struct DataPoint : public plotjuggler_msgs::msg::DataPoint
{
  DataPoint();
  DataPoint(uint16_t name_index, double time, double value)
  {
    this->stamp = time;
    this->name_index = name_index;
    this->value = value;
  }
  const plotjuggler_msgs::msg::DataPoint& msg() const {
    return static_cast<const plotjuggler_msgs::msg::DataPoint&>(*this);
  }
  plotjuggler_msgs::msg::DataPoint& msg() {
    return static_cast<plotjuggler_msgs::msg::DataPoint&>(*this);
  }
};
}  // namespace plotjuggler_msgs
#endif  // PLOTJUGGLER_MSGS__DATA_POINT_HPP_