// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autopilot_interface_msgs:srv/SetSpeed.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_SPEED__TRAITS_HPP_
#define AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_SPEED__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autopilot_interface_msgs/srv/detail/set_speed__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autopilot_interface_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSpeed_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: speed
  {
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetSpeed_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: speed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "speed: ";
    rosidl_generator_traits::value_to_yaml(msg.speed, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetSpeed_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::srv::SetSpeed_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::srv::SetSpeed_Request & msg)
{
  return autopilot_interface_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::srv::SetSpeed_Request>()
{
  return "autopilot_interface_msgs::srv::SetSpeed_Request";
}

template<>
inline const char * name<autopilot_interface_msgs::srv::SetSpeed_Request>()
{
  return "autopilot_interface_msgs/srv/SetSpeed_Request";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::srv::SetSpeed_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::srv::SetSpeed_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autopilot_interface_msgs::srv::SetSpeed_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace autopilot_interface_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const SetSpeed_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SetSpeed_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SetSpeed_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::srv::SetSpeed_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::srv::SetSpeed_Response & msg)
{
  return autopilot_interface_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::srv::SetSpeed_Response>()
{
  return "autopilot_interface_msgs::srv::SetSpeed_Response";
}

template<>
inline const char * name<autopilot_interface_msgs::srv::SetSpeed_Response>()
{
  return "autopilot_interface_msgs/srv/SetSpeed_Response";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::srv::SetSpeed_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::srv::SetSpeed_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<autopilot_interface_msgs::srv::SetSpeed_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<autopilot_interface_msgs::srv::SetSpeed>()
{
  return "autopilot_interface_msgs::srv::SetSpeed";
}

template<>
inline const char * name<autopilot_interface_msgs::srv::SetSpeed>()
{
  return "autopilot_interface_msgs/srv/SetSpeed";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::srv::SetSpeed>
  : std::integral_constant<
    bool,
    has_fixed_size<autopilot_interface_msgs::srv::SetSpeed_Request>::value &&
    has_fixed_size<autopilot_interface_msgs::srv::SetSpeed_Response>::value
  >
{
};

template<>
struct has_bounded_size<autopilot_interface_msgs::srv::SetSpeed>
  : std::integral_constant<
    bool,
    has_bounded_size<autopilot_interface_msgs::srv::SetSpeed_Request>::value &&
    has_bounded_size<autopilot_interface_msgs::srv::SetSpeed_Response>::value
  >
{
};

template<>
struct is_service<autopilot_interface_msgs::srv::SetSpeed>
  : std::true_type
{
};

template<>
struct is_service_request<autopilot_interface_msgs::srv::SetSpeed_Request>
  : std::true_type
{
};

template<>
struct is_service_response<autopilot_interface_msgs::srv::SetSpeed_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // AUTOPILOT_INTERFACE_MSGS__SRV__DETAIL__SET_SPEED__TRAITS_HPP_
