// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__TRAITS_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pegasus_msgs/msg/detail/defect_array__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'detections'
#include "pegasus_msgs/msg/detail/defect_detection__traits.hpp"

namespace pegasus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const DefectArray & msg,
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

  // member: zone_id
  {
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << ", ";
  }

  // member: detections
  {
    if (msg.detections.size() == 0) {
      out << "detections: []";
    } else {
      out << "detections: [";
      size_t pending_items = msg.detections.size();
      for (auto item : msg.detections) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: total_count
  {
    out << "total_count: ";
    rosidl_generator_traits::value_to_yaml(msg.total_count, out);
    out << ", ";
  }

  // member: crack_count
  {
    out << "crack_count: ";
    rosidl_generator_traits::value_to_yaml(msg.crack_count, out);
    out << ", ";
  }

  // member: corrosion_count
  {
    out << "corrosion_count: ";
    rosidl_generator_traits::value_to_yaml(msg.corrosion_count, out);
    out << ", ";
  }

  // member: paint_damage_count
  {
    out << "paint_damage_count: ";
    rosidl_generator_traits::value_to_yaml(msg.paint_damage_count, out);
    out << ", ";
  }

  // member: max_risk_level
  {
    out << "max_risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.max_risk_level, out);
    out << ", ";
  }

  // member: max_risk_id
  {
    out << "max_risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.max_risk_id, out);
    out << ", ";
  }

  // member: inference_latency
  {
    out << "inference_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.inference_latency, out);
    out << ", ";
  }

  // member: total_latency
  {
    out << "total_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.total_latency, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DefectArray & msg,
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

  // member: zone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << "\n";
  }

  // member: detections
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.detections.size() == 0) {
      out << "detections: []\n";
    } else {
      out << "detections:\n";
      for (auto item : msg.detections) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }

  // member: total_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_count: ";
    rosidl_generator_traits::value_to_yaml(msg.total_count, out);
    out << "\n";
  }

  // member: crack_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "crack_count: ";
    rosidl_generator_traits::value_to_yaml(msg.crack_count, out);
    out << "\n";
  }

  // member: corrosion_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "corrosion_count: ";
    rosidl_generator_traits::value_to_yaml(msg.corrosion_count, out);
    out << "\n";
  }

  // member: paint_damage_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "paint_damage_count: ";
    rosidl_generator_traits::value_to_yaml(msg.paint_damage_count, out);
    out << "\n";
  }

  // member: max_risk_level
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_risk_level: ";
    rosidl_generator_traits::value_to_yaml(msg.max_risk_level, out);
    out << "\n";
  }

  // member: max_risk_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "max_risk_id: ";
    rosidl_generator_traits::value_to_yaml(msg.max_risk_id, out);
    out << "\n";
  }

  // member: inference_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "inference_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.inference_latency, out);
    out << "\n";
  }

  // member: total_latency
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "total_latency: ";
    rosidl_generator_traits::value_to_yaml(msg.total_latency, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DefectArray & msg, bool use_flow_style = false)
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
  const pegasus_msgs::msg::DefectArray & msg,
  std::ostream & out, size_t indentation = 0)
{
  pegasus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pegasus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pegasus_msgs::msg::DefectArray & msg)
{
  return pegasus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pegasus_msgs::msg::DefectArray>()
{
  return "pegasus_msgs::msg::DefectArray";
}

template<>
inline const char * name<pegasus_msgs::msg::DefectArray>()
{
  return "pegasus_msgs/msg/DefectArray";
}

template<>
struct has_fixed_size<pegasus_msgs::msg::DefectArray>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pegasus_msgs::msg::DefectArray>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pegasus_msgs::msg::DefectArray>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__TRAITS_HPP_
