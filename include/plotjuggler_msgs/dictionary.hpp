#ifndef PLOTJUGGLER_MSGS__DICTIONARY_HPP_
#define PLOTJUGGLER_MSGS__DICTIONARY_HPP_

#include <plotjuggler_msgs/msg/dictionary.hpp>

namespace plotjuggler_msgs
{
struct Dictionary : public plotjuggler_msgs::msg::Dictionary
{
  Dictionary();
  Dictionary(uint32_t dictionary_uuid){
    this->dictionary_uuid = dictionary_uuid;
  }
  void push_back(const std::string& name){
    this->names.push_back(name);
  }
  const plotjuggler_msgs::msg::Dictionary& msg() const {
    return static_cast<const plotjuggler_msgs::msg::Dictionary&>(*this);
  }
  plotjuggler_msgs::msg::Dictionary& msg() {
    return static_cast<plotjuggler_msgs::msg::Dictionary&>(*this);
  }
};
}  // namespace plotjuggler_msgs
#endif  // PLOTJUGGLER_MSGS__DICTIONARY_HPP_