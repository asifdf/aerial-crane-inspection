// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__BUILDER_HPP_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "autopilot_interface_msgs/msg/detail/offboard_flag__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace autopilot_interface_msgs
{

namespace msg
{

namespace builder
{

class Init_OffboardFlag_offboard_flag
{
public:
  Init_OffboardFlag_offboard_flag()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::autopilot_interface_msgs::msg::OffboardFlag offboard_flag(::autopilot_interface_msgs::msg::OffboardFlag::_offboard_flag_type arg)
  {
    msg_.offboard_flag = std::move(arg);
    return std::move(msg_);
  }

private:
  ::autopilot_interface_msgs::msg::OffboardFlag msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::autopilot_interface_msgs::msg::OffboardFlag>()
{
  return autopilot_interface_msgs::msg::builder::Init_OffboardFlag_offboard_flag();
}

}  // namespace autopilot_interface_msgs

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__BUILDER_HPP_
