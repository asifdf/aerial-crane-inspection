// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__TRAITS_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pegasus_msgs/msg/detail/inspection_result__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'drone_pose'
#include "geometry_msgs/msg/detail/pose_stamped__traits.hpp"
// Member 'defects'
#include "pegasus_msgs/msg/detail/defect_array__traits.hpp"

namespace pegasus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const InspectionResult & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: drone_id
  {
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << ", ";
  }

  // member: mission_id
  {
    out << "mission_id: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_id, out);
    out << ", ";
  }

  // member: zone_id
  {
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << ", ";
  }

  // member: drone_pose
  {
    out << "drone_pose: ";
    to_flow_style_yaml(msg.drone_pose, out);
    out << ", ";
  }

  // member: defects
  {
    out << "defects: ";
    to_flow_style_yaml(msg.defects, out);
    out << ", ";
  }

  // member: coverage_percent
  {
    out << "coverage_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.coverage_percent, out);
    out << ", ";
  }

  // member: images_captured
  {
    out << "images_captured: ";
    rosidl_generator_traits::value_to_yaml(msg.images_captured, out);
    out << ", ";
  }

  // member: images_with_defects
  {
    out << "images_with_defects: ";
    rosidl_generator_traits::value_to_yaml(msg.images_with_defects, out);
    out << ", ";
  }

  // member: zone_risk_level
  {
    out << "zone_risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_risk_level, out);
    out << ", ";
  }

  // member: zone_risk_id
  {
    out << "zone_risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_risk_id, out);
    out << ", ";
  }

  // member: json_payload
  {
    out << "json_payload: ";
    rosidl_generator_traits::value_to_yaml(msg.json_payload, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const InspectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: drone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.drone_id, out);
    out << "\n";
  }

  // member: mission_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mission_id: ";
    rosidl_generator_traits::value_to_yaml(msg.mission_id, out);
    out << "\n";
  }

  // member: zone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << "\n";
  }

  // member: drone_pose
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "drone_pose:\n";
    to_block_style_yaml(msg.drone_pose, out, indentation + 2);
  }

  // member: defects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "defects:\n";
    to_block_style_yaml(msg.defects, out, indentation + 2);
  }

  // member: coverage_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "coverage_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.coverage_percent, out);
    out << "\n";
  }

  // member: images_captured
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "images_captured: ";
    rosidl_generator_traits::value_to_yaml(msg.images_captured, out);
    out << "\n";
  }

  // member: images_with_defects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "images_with_defects: ";
    rosidl_generator_traits::value_to_yaml(msg.images_with_defects, out);
    out << "\n";
  }

  // member: zone_risk_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_risk_level, out);
    out << "\n";
  }

  // member: zone_risk_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_risk_id, out);
    out << "\n";
  }

  // member: json_payload
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "json_payload: ";
    rosidl_generator_traits::value_to_yaml(msg.json_payload, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const InspectionResult & msg, bool use_flow_style = false)
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

}  // namespace pegasus_msgs

namespace rosidl_generator_traits
{

[[deprecated("use pegasus_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const pegasus_msgs::msg::InspectionResult & msg,
  std::ostream & out, size_t indentation = 0)
{
  pegasus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pegasus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pegasus_msgs::msg::InspectionResult & msg)
{
  return pegasus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pegasus_msgs::msg::InspectionResult>()
{
  return "pegasus_msgs::msg::InspectionResult";
}

template<>
inline const char * name<pegasus_msgs::msg::InspectionResult>()
{
  return "pegasus_msgs/msg/InspectionResult";
}

template<>
struct has_fixed_size<pegasus_msgs::msg::InspectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pegasus_msgs::msg::InspectionResult>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pegasus_msgs::msg::InspectionResult>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__TRAITS_HPP_
