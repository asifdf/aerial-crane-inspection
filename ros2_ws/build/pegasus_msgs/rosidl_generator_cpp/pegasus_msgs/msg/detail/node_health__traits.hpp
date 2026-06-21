// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from pegasus_msgs:msg/NodeHealth.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__TRAITS_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "pegasus_msgs/msg/detail/node_health__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace pegasus_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const NodeHealth & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: node_name
  {
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << ", ";
  }

  // member: device_id
  {
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << ", ";
  }

  // member: fps
  {
    out << "fps: ";
    rosidl_generator_traits::value_to_yaml(msg.fps, out);
    out << ", ";
  }

  // member: avg_latency_ms
  {
    out << "avg_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_latency_ms, out);
    out << ", ";
  }

  // member: p95_latency_ms
  {
    out << "p95_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.p95_latency_ms, out);
    out << ", ";
  }

  // member: p99_latency_ms
  {
    out << "p99_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.p99_latency_ms, out);
    out << ", ";
  }

  // member: gpu_util_percent
  {
    out << "gpu_util_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_util_percent, out);
    out << ", ";
  }

  // member: gpu_mem_used_mb
  {
    out << "gpu_mem_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_mem_used_mb, out);
    out << ", ";
  }

  // member: gpu_mem_total_mb
  {
    out << "gpu_mem_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_mem_total_mb, out);
    out << ", ";
  }

  // member: cpu_util_percent
  {
    out << "cpu_util_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_util_percent, out);
    out << ", ";
  }

  // member: cpu_mem_used_mb
  {
    out << "cpu_mem_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_mem_used_mb, out);
    out << ", ";
  }

  // member: cpu_mem_total_mb
  {
    out << "cpu_mem_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_mem_total_mb, out);
    out << ", ";
  }

  // member: temperature_c
  {
    out << "temperature_c: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c, out);
    out << ", ";
  }

  // member: model_path
  {
    out << "model_path: ";
    rosidl_generator_traits::value_to_yaml(msg.model_path, out);
    out << ", ";
  }

  // member: model_version
  {
    out << "model_version: ";
    rosidl_generator_traits::value_to_yaml(msg.model_version, out);
    out << ", ";
  }

  // member: precision
  {
    out << "precision: ";
    rosidl_generator_traits::value_to_yaml(msg.precision, out);
    out << ", ";
  }

  // member: input_width
  {
    out << "input_width: ";
    rosidl_generator_traits::value_to_yaml(msg.input_width, out);
    out << ", ";
  }

  // member: input_height
  {
    out << "input_height: ";
    rosidl_generator_traits::value_to_yaml(msg.input_height, out);
    out << ", ";
  }

  // member: frames_processed
  {
    out << "frames_processed: ";
    rosidl_generator_traits::value_to_yaml(msg.frames_processed, out);
    out << ", ";
  }

  // member: detections_published
  {
    out << "detections_published: ";
    rosidl_generator_traits::value_to_yaml(msg.detections_published, out);
    out << ", ";
  }

  // member: errors_count
  {
    out << "errors_count: ";
    rosidl_generator_traits::value_to_yaml(msg.errors_count, out);
    out << ", ";
  }

  // member: last_error_time
  {
    out << "last_error_time: ";
    rosidl_generator_traits::value_to_yaml(msg.last_error_time, out);
    out << ", ";
  }

  // member: status
  {
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << ", ";
  }

  // member: active_alerts
  {
    if (msg.active_alerts.size() == 0) {
      out << "active_alerts: []";
    } else {
      out << "active_alerts: [";
      size_t pending_items = msg.active_alerts.size();
      for (auto item : msg.active_alerts) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const NodeHealth & msg,
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

  // member: node_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "node_name: ";
    rosidl_generator_traits::value_to_yaml(msg.node_name, out);
    out << "\n";
  }

  // member: device_id
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "device_id: ";
    rosidl_generator_traits::value_to_yaml(msg.device_id, out);
    out << "\n";
  }

  // member: fps
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "fps: ";
    rosidl_generator_traits::value_to_yaml(msg.fps, out);
    out << "\n";
  }

  // member: avg_latency_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "avg_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.avg_latency_ms, out);
    out << "\n";
  }

  // member: p95_latency_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p95_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.p95_latency_ms, out);
    out << "\n";
  }

  // member: p99_latency_ms
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "p99_latency_ms: ";
    rosidl_generator_traits::value_to_yaml(msg.p99_latency_ms, out);
    out << "\n";
  }

  // member: gpu_util_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_util_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_util_percent, out);
    out << "\n";
  }

  // member: gpu_mem_used_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_mem_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_mem_used_mb, out);
    out << "\n";
  }

  // member: gpu_mem_total_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "gpu_mem_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.gpu_mem_total_mb, out);
    out << "\n";
  }

  // member: cpu_util_percent
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_util_percent: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_util_percent, out);
    out << "\n";
  }

  // member: cpu_mem_used_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_mem_used_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_mem_used_mb, out);
    out << "\n";
  }

  // member: cpu_mem_total_mb
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "cpu_mem_total_mb: ";
    rosidl_generator_traits::value_to_yaml(msg.cpu_mem_total_mb, out);
    out << "\n";
  }

  // member: temperature_c
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "temperature_c: ";
    rosidl_generator_traits::value_to_yaml(msg.temperature_c, out);
    out << "\n";
  }

  // member: model_path
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model_path: ";
    rosidl_generator_traits::value_to_yaml(msg.model_path, out);
    out << "\n";
  }

  // member: model_version
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "model_version: ";
    rosidl_generator_traits::value_to_yaml(msg.model_version, out);
    out << "\n";
  }

  // member: precision
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "precision: ";
    rosidl_generator_traits::value_to_yaml(msg.precision, out);
    out << "\n";
  }

  // member: input_width
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_width: ";
    rosidl_generator_traits::value_to_yaml(msg.input_width, out);
    out << "\n";
  }

  // member: input_height
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "input_height: ";
    rosidl_generator_traits::value_to_yaml(msg.input_height, out);
    out << "\n";
  }

  // member: frames_processed
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "frames_processed: ";
    rosidl_generator_traits::value_to_yaml(msg.frames_processed, out);
    out << "\n";
  }

  // member: detections_published
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "detections_published: ";
    rosidl_generator_traits::value_to_yaml(msg.detections_published, out);
    out << "\n";
  }

  // member: errors_count
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "errors_count: ";
    rosidl_generator_traits::value_to_yaml(msg.errors_count, out);
    out << "\n";
  }

  // member: last_error_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "last_error_time: ";
    rosidl_generator_traits::value_to_yaml(msg.last_error_time, out);
    out << "\n";
  }

  // member: status
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "status: ";
    rosidl_generator_traits::value_to_yaml(msg.status, out);
    out << "\n";
  }

  // member: active_alerts
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.active_alerts.size() == 0) {
      out << "active_alerts: []\n";
    } else {
      out << "active_alerts:\n";
      for (auto item : msg.active_alerts) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const NodeHealth & msg, bool use_flow_style = false)
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
  const pegasus_msgs::msg::NodeHealth & msg,
  std::ostream & out, size_t indentation = 0)
{
  pegasus_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use pegasus_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const pegasus_msgs::msg::NodeHealth & msg)
{
  return pegasus_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<pegasus_msgs::msg::NodeHealth>()
{
  return "pegasus_msgs::msg::NodeHealth";
}

template<>
inline const char * name<pegasus_msgs::msg::NodeHealth>()
{
  return "pegasus_msgs/msg/NodeHealth";
}

template<>
struct has_fixed_size<pegasus_msgs::msg::NodeHealth>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<pegasus_msgs::msg::NodeHealth>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<pegasus_msgs::msg::NodeHealth>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__TRAITS_HPP_
