// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from autopilot_interface_msgs:action/Takeoff.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__TRAITS_HPP_
#define AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "autopilot_interface_msgs/action/detail/takeoff__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_Goal & msg,
  std::ostream & out)
{
  out << "{";
  // member: takeoff_altitude
  {
    out << "takeoff_altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.takeoff_altitude, out);
    out << ", ";
  }

  // member: vtol_transition_heading
  {
    out << "vtol_transition_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_transition_heading, out);
    out << ", ";
  }

  // member: vtol_loiter_nord
  {
    out << "vtol_loiter_nord: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_nord, out);
    out << ", ";
  }

  // member: vtol_loiter_east
  {
    out << "vtol_loiter_east: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_east, out);
    out << ", ";
  }

  // member: vtol_loiter_alt
  {
    out << "vtol_loiter_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_alt, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: takeoff_altitude
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "takeoff_altitude: ";
    rosidl_generator_traits::value_to_yaml(msg.takeoff_altitude, out);
    out << "\n";
  }

  // member: vtol_transition_heading
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vtol_transition_heading: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_transition_heading, out);
    out << "\n";
  }

  // member: vtol_loiter_nord
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vtol_loiter_nord: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_nord, out);
    out << "\n";
  }

  // member: vtol_loiter_east
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vtol_loiter_east: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_east, out);
    out << "\n";
  }

  // member: vtol_loiter_alt
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "vtol_loiter_alt: ";
    rosidl_generator_traits::value_to_yaml(msg.vtol_loiter_alt, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_Goal & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_Goal & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_Goal & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_Goal>()
{
  return "autopilot_interface_msgs::action::Takeoff_Goal";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_Goal>()
{
  return "autopilot_interface_msgs/action/Takeoff_Goal";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_Goal>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_Goal>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_Result & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_Result & msg,
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
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_Result & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_Result & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_Result & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_Result>()
{
  return "autopilot_interface_msgs::action::Takeoff_Result";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_Result>()
{
  return "autopilot_interface_msgs/action/Takeoff_Result";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_Result>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_Result>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_Result>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_Feedback & msg,
  std::ostream & out)
{
  out << "{";
  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
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

inline std::string to_yaml(const Takeoff_Feedback & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_Feedback & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_Feedback & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_Feedback>()
{
  return "autopilot_interface_msgs::action::Takeoff_Feedback";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_Feedback>()
{
  return "autopilot_interface_msgs/action/Takeoff_Feedback";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_Feedback>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_Feedback>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
#include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'goal'
#include "autopilot_interface_msgs/action/detail/takeoff__traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_SendGoal_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: goal
  {
    out << "goal: ";
    to_flow_style_yaml(msg.goal, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: goal
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal:\n";
    to_block_style_yaml(msg.goal, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_SendGoal_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_SendGoal_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_SendGoal_Request & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>()
{
  return "autopilot_interface_msgs::action::Takeoff_SendGoal_Request";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>()
{
  return "autopilot_interface_msgs/action/Takeoff_SendGoal_Request";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>
  : std::integral_constant<bool, has_fixed_size<autopilot_interface_msgs::action::Takeoff_Goal>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>
  : std::integral_constant<bool, has_bounded_size<autopilot_interface_msgs::action::Takeoff_Goal>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'stamp'
#include "builtin_interfaces/msg/detail/time__traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_SendGoal_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: accepted
  {
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << ", ";
  }

  // member: stamp
  {
    out << "stamp: ";
    to_flow_style_yaml(msg.stamp, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: accepted
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "accepted: ";
    rosidl_generator_traits::value_to_yaml(msg.accepted, out);
    out << "\n";
  }

  // member: stamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stamp:\n";
    to_block_style_yaml(msg.stamp, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_SendGoal_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_SendGoal_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_SendGoal_Response & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>()
{
  return "autopilot_interface_msgs::action::Takeoff_SendGoal_Response";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>()
{
  return "autopilot_interface_msgs/action/Takeoff_SendGoal_Response";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>
  : std::integral_constant<bool, has_fixed_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>
  : std::integral_constant<bool, has_bounded_size<builtin_interfaces::msg::Time>::value> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_SendGoal>()
{
  return "autopilot_interface_msgs::action::Takeoff_SendGoal";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_SendGoal>()
{
  return "autopilot_interface_msgs/action/Takeoff_SendGoal";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_SendGoal>
  : std::integral_constant<
    bool,
    has_fixed_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>::value &&
    has_fixed_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>::value
  >
{
};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_SendGoal>
  : std::integral_constant<
    bool,
    has_bounded_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>::value &&
    has_bounded_size<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>::value
  >
{
};

template<>
struct is_service<autopilot_interface_msgs::action::Takeoff_SendGoal>
  : std::true_type
{
};

template<>
struct is_service_request<autopilot_interface_msgs::action::Takeoff_SendGoal_Request>
  : std::true_type
{
};

template<>
struct is_service_response<autopilot_interface_msgs::action::Takeoff_SendGoal_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_GetResult_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_GetResult_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_GetResult_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_GetResult_Request & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_GetResult_Request>()
{
  return "autopilot_interface_msgs::action::Takeoff_GetResult_Request";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_GetResult_Request>()
{
  return "autopilot_interface_msgs/action/Takeoff_GetResult_Request";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_GetResult_Request>
  : std::integral_constant<bool, has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_GetResult_Request>
  : std::integral_constant<bool, has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_GetResult_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'result'
// already included above
// #include "autopilot_interface_msgs/action/detail/takeoff__traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_GetResult_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: result
  {
    out << "result: ";
    to_flow_style_yaml(msg.result, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: result
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "result:\n";
    to_block_style_yaml(msg.result, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_GetResult_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_GetResult_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_GetResult_Response & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_GetResult_Response>()
{
  return "autopilot_interface_msgs::action::Takeoff_GetResult_Response";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_GetResult_Response>()
{
  return "autopilot_interface_msgs/action/Takeoff_GetResult_Response";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_GetResult_Response>
  : std::integral_constant<bool, has_fixed_size<autopilot_interface_msgs::action::Takeoff_Result>::value> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_GetResult_Response>
  : std::integral_constant<bool, has_bounded_size<autopilot_interface_msgs::action::Takeoff_Result>::value> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_GetResult_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_GetResult>()
{
  return "autopilot_interface_msgs::action::Takeoff_GetResult";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_GetResult>()
{
  return "autopilot_interface_msgs/action/Takeoff_GetResult";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_GetResult>
  : std::integral_constant<
    bool,
    has_fixed_size<autopilot_interface_msgs::action::Takeoff_GetResult_Request>::value &&
    has_fixed_size<autopilot_interface_msgs::action::Takeoff_GetResult_Response>::value
  >
{
};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_GetResult>
  : std::integral_constant<
    bool,
    has_bounded_size<autopilot_interface_msgs::action::Takeoff_GetResult_Request>::value &&
    has_bounded_size<autopilot_interface_msgs::action::Takeoff_GetResult_Response>::value
  >
{
};

template<>
struct is_service<autopilot_interface_msgs::action::Takeoff_GetResult>
  : std::true_type
{
};

template<>
struct is_service_request<autopilot_interface_msgs::action::Takeoff_GetResult_Request>
  : std::true_type
{
};

template<>
struct is_service_response<autopilot_interface_msgs::action::Takeoff_GetResult_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'goal_id'
// already included above
// #include "unique_identifier_msgs/msg/detail/uuid__traits.hpp"
// Member 'feedback'
// already included above
// #include "autopilot_interface_msgs/action/detail/takeoff__traits.hpp"

namespace autopilot_interface_msgs
{

namespace action
{

inline void to_flow_style_yaml(
  const Takeoff_FeedbackMessage & msg,
  std::ostream & out)
{
  out << "{";
  // member: goal_id
  {
    out << "goal_id: ";
    to_flow_style_yaml(msg.goal_id, out);
    out << ", ";
  }

  // member: feedback
  {
    out << "feedback: ";
    to_flow_style_yaml(msg.feedback, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Takeoff_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: goal_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "goal_id:\n";
    to_block_style_yaml(msg.goal_id, out, indentation + 2);
  }

  // member: feedback
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "feedback:\n";
    to_block_style_yaml(msg.feedback, out, indentation + 2);
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Takeoff_FeedbackMessage & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace action

}  // namespace autopilot_interface_msgs

namespace rosidl_generator_traits
{

[[deprecated("use autopilot_interface_msgs::action::to_block_style_yaml() instead")]]
inline void to_yaml(
  const autopilot_interface_msgs::action::Takeoff_FeedbackMessage & msg,
  std::ostream & out, size_t indentation = 0)
{
  autopilot_interface_msgs::action::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use autopilot_interface_msgs::action::to_yaml() instead")]]
inline std::string to_yaml(const autopilot_interface_msgs::action::Takeoff_FeedbackMessage & msg)
{
  return autopilot_interface_msgs::action::to_yaml(msg);
}

template<>
inline const char * data_type<autopilot_interface_msgs::action::Takeoff_FeedbackMessage>()
{
  return "autopilot_interface_msgs::action::Takeoff_FeedbackMessage";
}

template<>
inline const char * name<autopilot_interface_msgs::action::Takeoff_FeedbackMessage>()
{
  return "autopilot_interface_msgs/action/Takeoff_FeedbackMessage";
}

template<>
struct has_fixed_size<autopilot_interface_msgs::action::Takeoff_FeedbackMessage>
  : std::integral_constant<bool, has_fixed_size<autopilot_interface_msgs::action::Takeoff_Feedback>::value && has_fixed_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct has_bounded_size<autopilot_interface_msgs::action::Takeoff_FeedbackMessage>
  : std::integral_constant<bool, has_bounded_size<autopilot_interface_msgs::action::Takeoff_Feedback>::value && has_bounded_size<unique_identifier_msgs::msg::UUID>::value> {};

template<>
struct is_message<autopilot_interface_msgs::action::Takeoff_FeedbackMessage>
  : std::true_type {};

}  // namespace rosidl_generator_traits


namespace rosidl_generator_traits
{

template<>
struct is_action<autopilot_interface_msgs::action::Takeoff>
  : std::true_type
{
};

template<>
struct is_action_goal<autopilot_interface_msgs::action::Takeoff_Goal>
  : std::true_type
{
};

template<>
struct is_action_result<autopilot_interface_msgs::action::Takeoff_Result>
  : std::true_type
{
};

template<>
struct is_action_feedback<autopilot_interface_msgs::action::Takeoff_Feedback>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits


#endif  // AUTOPILOT_INTERFACE_MSGS__ACTION__DETAIL__TAKEOFF__TRAITS_HPP_
