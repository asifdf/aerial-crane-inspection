// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__TRAITS_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pegasus_msgs/msg/detail/defect_detection__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'mask'
#include "sensor_msgs/msg/detail/compressed_image__traits.hpp"
// Member 'position_3d'
#include "geometry_msgs/msg/detail/point__traits.hpp"

namespace pegasus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DefectDetection & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: type
  {
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << ", ";
  }

  // member: class_id
  {
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << ", ";
  }

  // member: confidence
  {
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << ", ";
  }

  // member: bbox_x
  {
    out << "bbox_x: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x, out);
    out << ", ";
  }

  // member: bbox_y
  {
    out << "bbox_y: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y, out);
    out << ", ";
  }

  // member: bbox_width
  {
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << ", ";
  }

  // member: bbox_height
  {
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
    out << ", ";
  }

  // member: bbox_x_norm
  {
    out << "bbox_x_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x_norm, out);
    out << ", ";
  }

  // member: bbox_y_norm
  {
    out << "bbox_y_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y_norm, out);
    out << ", ";
  }

  // member: bbox_width_norm
  {
    out << "bbox_width_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width_norm, out);
    out << ", ";
  }

  // member: bbox_height_norm
  {
    out << "bbox_height_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height_norm, out);
    out << ", ";
  }

  // member: risk_level
  {
    out << "risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.risk_level, out);
    out << ", ";
  }

  // member: risk_id
  {
    out << "risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.risk_id, out);
    out << ", ";
  }

  // member: mask
  {
    out << "mask: ";
    to_flow_style_yaml(msg.mask, out);
    out << ", ";
  }

  // member: position_3d
  {
    out << "position_3d: ";
    to_flow_style_yaml(msg.position_3d, out);
    out << ", ";
  }

  // member: has_3d_position
  {
    out << "has_3d_position: ";
    rosidl_generator_traits::value_to_yaml(msg.has_3d_position, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DefectDetection & msg,
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

  // member: type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "type: ";
    rosidl_generator_traits::value_to_yaml(msg.type, out);
    out << "\n";
  }

  // member: class_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "class_id: ";
    rosidl_generator_traits::value_to_yaml(msg.class_id, out);
    out << "\n";
  }

  // member: confidence
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "confidence: ";
    rosidl_generator_traits::value_to_yaml(msg.confidence, out);
    out << "\n";
  }

  // member: bbox_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_x: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x, out);
    out << "\n";
  }

  // member: bbox_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_y: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y, out);
    out << "\n";
  }

  // member: bbox_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_width: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width, out);
    out << "\n";
  }

  // member: bbox_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_height: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height, out);
    out << "\n";
  }

  // member: bbox_x_norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_x_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_x_norm, out);
    out << "\n";
  }

  // member: bbox_y_norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_y_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_y_norm, out);
    out << "\n";
  }

  // member: bbox_width_norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_width_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_width_norm, out);
    out << "\n";
  }

  // member: bbox_height_norm
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "bbox_height_norm: ";
    rosidl_generator_traits::value_to_yaml(msg.bbox_height_norm, out);
    out << "\n";
  }

  // member: risk_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.risk_level, out);
    out << "\n";
  }

  // member: risk_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.risk_id, out);
    out << "\n";
  }

  // member: mask
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mask:\n";
    to_block_style_yaml(msg.mask, out, indentation + 2);
  }

  // member: position_3d
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "position_3d:\n";
    to_block_style_yaml(msg.position_3d, out, indentation + 2);
  }

  // member: has_3d_position
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "has_3d_position: ";
    rosidl_generator_traits::value_to_yaml(msg.has_3d_position, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DefectDetection & msg, bool use_flow_style = false)
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
  const pegasus_msgs::msg::DefectDetection & msg,
  std::ostream & out, size_t indentation = 0)
{
  pegasus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pegasus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pegasus_msgs::msg::DefectDetection & msg)
{
  return pegasus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pegasus_msgs::msg::DefectDetection>()
{
  return "pegasus_msgs::msg::DefectDetection";
}

template<>
inline const char * name<pegasus_msgs::msg::DefectDetection>()
{
  return "pegasus_msgs/msg/DefectDetection";
}

template<>
struct has_fixed_size<pegasus_msgs::msg::DefectDetection>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pegasus_msgs::msg::DefectDetection>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pegasus_msgs::msg::DefectDetection>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__TRAITS_HPP_
