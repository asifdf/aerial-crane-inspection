// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__TRAITS_HPP_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autopilot_interface_msgs/msg/detail/offboard_flag__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autopilot_interface_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const OffboardFlag & msg,
  std::ostream & out)
{
  out << "{";
  // member: offboard_flag
  {
    out << "offboard_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.offboard_flag, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const OffboardFlag & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: offboard_flag
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offboard_flag: ";
    rosidl_generator_traits::value_to_yaml(msg.offboard_flag, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const OffboardFlag & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::msg::OffboardFlag & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::msg::OffboardFlag & msg)
{
  return autopilot_interface_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::msg::OffboardFlag>()
{
  return "autopilot_interface_msgs::msg::OffboardFlag";
}

template<>
inline const char * name<autopilot_interface_msgs::msg::OffboardFlag>()
{
  return "autopilot_interface_msgs/msg/OffboardFlag";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::msg::OffboardFlag>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::msg::OffboardFlag>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autopilot_interface_msgs::msg::OffboardFlag>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__TRAITS_HPP_
