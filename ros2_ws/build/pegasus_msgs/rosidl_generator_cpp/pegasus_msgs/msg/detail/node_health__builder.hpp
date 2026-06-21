// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from pegasus_msgs:msg/NodeHealth.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__BUILDER_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "pegasus_msgs/msg/detail/node_health__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace pegasus_msgs
{

namespace msg
{

namespace builder
{

class Init_NodeHealth_active_alerts
{
public:
  explicit Init_NodeHealth_active_alerts(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  ::pegasus_msgs::msg::NodeHealth active_alerts(::pegasus_msgs::msg::NodeHealth::_active_alerts_type arg)
  {
    msg_.active_alerts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_status
{
public:
  explicit Init_NodeHealth_status(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_active_alerts status(::pegasus_msgs::msg::NodeHealth::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_NodeHealth_active_alerts(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_last_error_time
{
public:
  explicit Init_NodeHealth_last_error_time(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_status last_error_time(::pegasus_msgs::msg::NodeHealth::_last_error_time_type arg)
  {
    msg_.last_error_time = std::move(arg);
    return Init_NodeHealth_status(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_errors_count
{
public:
  explicit Init_NodeHealth_errors_count(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_last_error_time errors_count(::pegasus_msgs::msg::NodeHealth::_errors_count_type arg)
  {
    msg_.errors_count = std::move(arg);
    return Init_NodeHealth_last_error_time(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_detections_published
{
public:
  explicit Init_NodeHealth_detections_published(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_errors_count detections_published(::pegasus_msgs::msg::NodeHealth::_detections_published_type arg)
  {
    msg_.detections_published = std::move(arg);
    return Init_NodeHealth_errors_count(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_frames_processed
{
public:
  explicit Init_NodeHealth_frames_processed(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_detections_published frames_processed(::pegasus_msgs::msg::NodeHealth::_frames_processed_type arg)
  {
    msg_.frames_processed = std::move(arg);
    return Init_NodeHealth_detections_published(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_input_height
{
public:
  explicit Init_NodeHealth_input_height(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_frames_processed input_height(::pegasus_msgs::msg::NodeHealth::_input_height_type arg)
  {
    msg_.input_height = std::move(arg);
    return Init_NodeHealth_frames_processed(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_input_width
{
public:
  explicit Init_NodeHealth_input_width(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_input_height input_width(::pegasus_msgs::msg::NodeHealth::_input_width_type arg)
  {
    msg_.input_width = std::move(arg);
    return Init_NodeHealth_input_height(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_precision
{
public:
  explicit Init_NodeHealth_precision(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_input_width precision(::pegasus_msgs::msg::NodeHealth::_precision_type arg)
  {
    msg_.precision = std::move(arg);
    return Init_NodeHealth_input_width(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_model_version
{
public:
  explicit Init_NodeHealth_model_version(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_precision model_version(::pegasus_msgs::msg::NodeHealth::_model_version_type arg)
  {
    msg_.model_version = std::move(arg);
    return Init_NodeHealth_precision(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_model_path
{
public:
  explicit Init_NodeHealth_model_path(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_model_version model_path(::pegasus_msgs::msg::NodeHealth::_model_path_type arg)
  {
    msg_.model_path = std::move(arg);
    return Init_NodeHealth_model_version(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_temperature_c
{
public:
  explicit Init_NodeHealth_temperature_c(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_model_path temperature_c(::pegasus_msgs::msg::NodeHealth::_temperature_c_type arg)
  {
    msg_.temperature_c = std::move(arg);
    return Init_NodeHealth_model_path(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_cpu_mem_total_mb
{
public:
  explicit Init_NodeHealth_cpu_mem_total_mb(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_temperature_c cpu_mem_total_mb(::pegasus_msgs::msg::NodeHealth::_cpu_mem_total_mb_type arg)
  {
    msg_.cpu_mem_total_mb = std::move(arg);
    return Init_NodeHealth_temperature_c(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_cpu_mem_used_mb
{
public:
  explicit Init_NodeHealth_cpu_mem_used_mb(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_cpu_mem_total_mb cpu_mem_used_mb(::pegasus_msgs::msg::NodeHealth::_cpu_mem_used_mb_type arg)
  {
    msg_.cpu_mem_used_mb = std::move(arg);
    return Init_NodeHealth_cpu_mem_total_mb(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_cpu_util_percent
{
public:
  explicit Init_NodeHealth_cpu_util_percent(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_cpu_mem_used_mb cpu_util_percent(::pegasus_msgs::msg::NodeHealth::_cpu_util_percent_type arg)
  {
    msg_.cpu_util_percent = std::move(arg);
    return Init_NodeHealth_cpu_mem_used_mb(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_gpu_mem_total_mb
{
public:
  explicit Init_NodeHealth_gpu_mem_total_mb(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_cpu_util_percent gpu_mem_total_mb(::pegasus_msgs::msg::NodeHealth::_gpu_mem_total_mb_type arg)
  {
    msg_.gpu_mem_total_mb = std::move(arg);
    return Init_NodeHealth_cpu_util_percent(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_gpu_mem_used_mb
{
public:
  explicit Init_NodeHealth_gpu_mem_used_mb(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_gpu_mem_total_mb gpu_mem_used_mb(::pegasus_msgs::msg::NodeHealth::_gpu_mem_used_mb_type arg)
  {
    msg_.gpu_mem_used_mb = std::move(arg);
    return Init_NodeHealth_gpu_mem_total_mb(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_gpu_util_percent
{
public:
  explicit Init_NodeHealth_gpu_util_percent(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_gpu_mem_used_mb gpu_util_percent(::pegasus_msgs::msg::NodeHealth::_gpu_util_percent_type arg)
  {
    msg_.gpu_util_percent = std::move(arg);
    return Init_NodeHealth_gpu_mem_used_mb(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_p99_latency_ms
{
public:
  explicit Init_NodeHealth_p99_latency_ms(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_gpu_util_percent p99_latency_ms(::pegasus_msgs::msg::NodeHealth::_p99_latency_ms_type arg)
  {
    msg_.p99_latency_ms = std::move(arg);
    return Init_NodeHealth_gpu_util_percent(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_p95_latency_ms
{
public:
  explicit Init_NodeHealth_p95_latency_ms(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_p99_latency_ms p95_latency_ms(::pegasus_msgs::msg::NodeHealth::_p95_latency_ms_type arg)
  {
    msg_.p95_latency_ms = std::move(arg);
    return Init_NodeHealth_p99_latency_ms(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_avg_latency_ms
{
public:
  explicit Init_NodeHealth_avg_latency_ms(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_p95_latency_ms avg_latency_ms(::pegasus_msgs::msg::NodeHealth::_avg_latency_ms_type arg)
  {
    msg_.avg_latency_ms = std::move(arg);
    return Init_NodeHealth_p95_latency_ms(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_fps
{
public:
  explicit Init_NodeHealth_fps(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_avg_latency_ms fps(::pegasus_msgs::msg::NodeHealth::_fps_type arg)
  {
    msg_.fps = std::move(arg);
    return Init_NodeHealth_avg_latency_ms(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_device_id
{
public:
  explicit Init_NodeHealth_device_id(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_fps device_id(::pegasus_msgs::msg::NodeHealth::_device_id_type arg)
  {
    msg_.device_id = std::move(arg);
    return Init_NodeHealth_fps(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_node_name
{
public:
  explicit Init_NodeHealth_node_name(::pegasus_msgs::msg::NodeHealth & msg)
  : msg_(msg)
  {}
  Init_NodeHealth_device_id node_name(::pegasus_msgs::msg::NodeHealth::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_NodeHealth_device_id(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

class Init_NodeHealth_header
{
public:
  Init_NodeHealth_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_NodeHealth_node_name header(::pegasus_msgs::msg::NodeHealth::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_NodeHealth_node_name(msg_);
  }

private:
  ::pegasus_msgs::msg::NodeHealth msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::pegasus_msgs::msg::NodeHealth>()
{
  return pegasus_msgs::msg::builder::Init_NodeHealth_header();
}

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__BUILDER_HPP_
