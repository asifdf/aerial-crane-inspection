// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__TRAITS_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pegasus_msgs/msg/detail/zone_info__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"
// Member 'zone_center'
#include "geometry_msgs/msg/detail/pose__traits.hpp"
// Member 'zone_dimensions'
#include "geometry_msgs/msg/detail/vector3__traits.hpp"

namespace pegasus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const ZoneInfo & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: zone_id
  {
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << ", ";
  }

  // member: zone_name
  {
    out << "zone_name: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_name, out);
    out << ", ";
  }

  // member: zone_type
  {
    out << "zone_type: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_type, out);
    out << ", ";
  }

  // member: zone_center
  {
    out << "zone_center: ";
    to_flow_style_yaml(msg.zone_center, out);
    out << ", ";
  }

  // member: zone_dimensions
  {
    out << "zone_dimensions: ";
    to_flow_style_yaml(msg.zone_dimensions, out);
    out << ", ";
  }

  // member: waypoints_x
  {
    if (msg.waypoints_x.size() == 0) {
      out << "waypoints_x: []";
    } else {
      out << "waypoints_x: [";
      size_t pending_items = msg.waypoints_x.size();
      for (auto item : msg.waypoints_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoints_y
  {
    if (msg.waypoints_y.size() == 0) {
      out << "waypoints_y: []";
    } else {
      out << "waypoints_y: [";
      size_t pending_items = msg.waypoints_y.size();
      for (auto item : msg.waypoints_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoints_z
  {
    if (msg.waypoints_z.size() == 0) {
      out << "waypoints_z: []";
    } else {
      out << "waypoints_z: [";
      size_t pending_items = msg.waypoints_z.size();
      for (auto item : msg.waypoints_z) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: waypoints_yaw
  {
    if (msg.waypoints_yaw.size() == 0) {
      out << "waypoints_yaw: []";
    } else {
      out << "waypoints_yaw: [";
      size_t pending_items = msg.waypoints_yaw.size();
      for (auto item : msg.waypoints_yaw) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: camera_pitch
  {
    if (msg.camera_pitch.size() == 0) {
      out << "camera_pitch: []";
    } else {
      out << "camera_pitch: [";
      size_t pending_items = msg.camera_pitch.size();
      for (auto item : msg.camera_pitch) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: camera_yaw
  {
    if (msg.camera_yaw.size() == 0) {
      out << "camera_yaw: []";
    } else {
      out << "camera_yaw: [";
      size_t pending_items = msg.camera_yaw.size();
      for (auto item : msg.camera_yaw) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: expected_defects
  {
    if (msg.expected_defects.size() == 0) {
      out << "expected_defects: []";
    } else {
      out << "expected_defects: [";
      size_t pending_items = msg.expected_defects.size();
      for (auto item : msg.expected_defects) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: priority
  {
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const ZoneInfo & msg,
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

  // member: zone_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_id: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_id, out);
    out << "\n";
  }

  // member: zone_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_name: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_name, out);
    out << "\n";
  }

  // member: zone_type
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_type: ";
    rosidl_generator_traits::value_to_yaml(msg.zone_type, out);
    out << "\n";
  }

  // member: zone_center
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_center:\n";
    to_block_style_yaml(msg.zone_center, out, indentation + 2);
  }

  // member: zone_dimensions
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "zone_dimensions:\n";
    to_block_style_yaml(msg.zone_dimensions, out, indentation + 2);
  }

  // member: waypoints_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints_x.size() == 0) {
      out << "waypoints_x: []\n";
    } else {
      out << "waypoints_x:\n";
      for (auto item : msg.waypoints_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoints_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints_y.size() == 0) {
      out << "waypoints_y: []\n";
    } else {
      out << "waypoints_y:\n";
      for (auto item : msg.waypoints_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoints_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints_z.size() == 0) {
      out << "waypoints_z: []\n";
    } else {
      out << "waypoints_z:\n";
      for (auto item : msg.waypoints_z) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: waypoints_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.waypoints_yaw.size() == 0) {
      out << "waypoints_yaw: []\n";
    } else {
      out << "waypoints_yaw:\n";
      for (auto item : msg.waypoints_yaw) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: camera_pitch
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.camera_pitch.size() == 0) {
      out << "camera_pitch: []\n";
    } else {
      out << "camera_pitch:\n";
      for (auto item : msg.camera_pitch) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: camera_yaw
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.camera_yaw.size() == 0) {
      out << "camera_yaw: []\n";
    } else {
      out << "camera_yaw:\n";
      for (auto item : msg.camera_yaw) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: expected_defects
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.expected_defects.size() == 0) {
      out << "expected_defects: []\n";
    } else {
      out << "expected_defects:\n";
      for (auto item : msg.expected_defects) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: priority
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "priority: ";
    rosidl_generator_traits::value_to_yaml(msg.priority, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const ZoneInfo & msg, bool use_flow_style = false)
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
  const pegasus_msgs::msg::ZoneInfo & msg,
  std::ostream & out, size_t indentation = 0)
{
  pegasus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pegasus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pegasus_msgs::msg::ZoneInfo & msg)
{
  return pegasus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pegasus_msgs::msg::ZoneInfo>()
{
  return "pegasus_msgs::msg::ZoneInfo";
}

template<>
inline const char * name<pegasus_msgs::msg::ZoneInfo>()
{
  return "pegasus_msgs/msg/ZoneInfo";
}

template<>
struct has_fixed_size<pegasus_msgs::msg::ZoneInfo>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pegasus_msgs::msg::ZoneInfo>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pegasus_msgs::msg::ZoneInfo>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__TRAITS_HPP_
