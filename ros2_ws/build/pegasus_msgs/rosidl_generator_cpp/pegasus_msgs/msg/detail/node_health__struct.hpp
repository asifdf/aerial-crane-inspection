// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pegasus_msgs:msg/NodeHealth.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pegasus_msgs__msg__NodeHealth __attribute__((deprecated))
#else
# define DEPRECATED__pegasus_msgs__msg__NodeHealth __declspec(deprecated)
#endif

namespace pegasus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct NodeHealth_
{
  using Type = NodeHealth_<ContainerAllocator>;

  explicit NodeHealth_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
      this->device_id = "";
      this->fps = 0.0f;
      this->avg_latency_ms = 0.0f;
      this->p95_latency_ms = 0.0f;
      this->p99_latency_ms = 0.0f;
      this->gpu_util_percent = 0.0f;
      this->gpu_mem_used_mb = 0.0f;
      this->gpu_mem_total_mb = 0.0f;
      this->cpu_util_percent = 0.0f;
      this->cpu_mem_used_mb = 0.0f;
      this->cpu_mem_total_mb = 0.0f;
      this->temperature_c = 0.0f;
      this->model_path = "";
      this->model_version = "";
      this->precision = "";
      this->input_width = 0ul;
      this->input_height = 0ul;
      this->frames_processed = 0ull;
      this->detections_published = 0ull;
      this->errors_count = 0ull;
      this->last_error_time = 0ull;
      this->status = "";
    }
  }

  explicit NodeHealth_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    node_name(_alloc),
    device_id(_alloc),
    model_path(_alloc),
    model_version(_alloc),
    precision(_alloc),
    status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->node_name = "";
      this->device_id = "";
      this->fps = 0.0f;
      this->avg_latency_ms = 0.0f;
      this->p95_latency_ms = 0.0f;
      this->p99_latency_ms = 0.0f;
      this->gpu_util_percent = 0.0f;
      this->gpu_mem_used_mb = 0.0f;
      this->gpu_mem_total_mb = 0.0f;
      this->cpu_util_percent = 0.0f;
      this->cpu_mem_used_mb = 0.0f;
      this->cpu_mem_total_mb = 0.0f;
      this->temperature_c = 0.0f;
      this->model_path = "";
      this->model_version = "";
      this->precision = "";
      this->input_width = 0ul;
      this->input_height = 0ul;
      this->frames_processed = 0ull;
      this->detections_published = 0ull;
      this->errors_count = 0ull;
      this->last_error_time = 0ull;
      this->status = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _node_name_type node_name;
  using _device_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _device_id_type device_id;
  using _fps_type =
    float;
  _fps_type fps;
  using _avg_latency_ms_type =
    float;
  _avg_latency_ms_type avg_latency_ms;
  using _p95_latency_ms_type =
    float;
  _p95_latency_ms_type p95_latency_ms;
  using _p99_latency_ms_type =
    float;
  _p99_latency_ms_type p99_latency_ms;
  using _gpu_util_percent_type =
    float;
  _gpu_util_percent_type gpu_util_percent;
  using _gpu_mem_used_mb_type =
    float;
  _gpu_mem_used_mb_type gpu_mem_used_mb;
  using _gpu_mem_total_mb_type =
    float;
  _gpu_mem_total_mb_type gpu_mem_total_mb;
  using _cpu_util_percent_type =
    float;
  _cpu_util_percent_type cpu_util_percent;
  using _cpu_mem_used_mb_type =
    float;
  _cpu_mem_used_mb_type cpu_mem_used_mb;
  using _cpu_mem_total_mb_type =
    float;
  _cpu_mem_total_mb_type cpu_mem_total_mb;
  using _temperature_c_type =
    float;
  _temperature_c_type temperature_c;
  using _model_path_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_path_type model_path;
  using _model_version_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _model_version_type model_version;
  using _precision_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _precision_type precision;
  using _input_width_type =
    uint32_t;
  _input_width_type input_width;
  using _input_height_type =
    uint32_t;
  _input_height_type input_height;
  using _frames_processed_type =
    uint64_t;
  _frames_processed_type frames_processed;
  using _detections_published_type =
    uint64_t;
  _detections_published_type detections_published;
  using _errors_count_type =
    uint64_t;
  _errors_count_type errors_count;
  using _last_error_time_type =
    uint64_t;
  _last_error_time_type last_error_time;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _status_type status;
  using _active_alerts_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _active_alerts_type active_alerts;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }
  Type & set__device_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->device_id = _arg;
    return *this;
  }
  Type & set__fps(
    const float & _arg)
  {
    this->fps = _arg;
    return *this;
  }
  Type & set__avg_latency_ms(
    const float & _arg)
  {
    this->avg_latency_ms = _arg;
    return *this;
  }
  Type & set__p95_latency_ms(
    const float & _arg)
  {
    this->p95_latency_ms = _arg;
    return *this;
  }
  Type & set__p99_latency_ms(
    const float & _arg)
  {
    this->p99_latency_ms = _arg;
    return *this;
  }
  Type & set__gpu_util_percent(
    const float & _arg)
  {
    this->gpu_util_percent = _arg;
    return *this;
  }
  Type & set__gpu_mem_used_mb(
    const float & _arg)
  {
    this->gpu_mem_used_mb = _arg;
    return *this;
  }
  Type & set__gpu_mem_total_mb(
    const float & _arg)
  {
    this->gpu_mem_total_mb = _arg;
    return *this;
  }
  Type & set__cpu_util_percent(
    const float & _arg)
  {
    this->cpu_util_percent = _arg;
    return *this;
  }
  Type & set__cpu_mem_used_mb(
    const float & _arg)
  {
    this->cpu_mem_used_mb = _arg;
    return *this;
  }
  Type & set__cpu_mem_total_mb(
    const float & _arg)
  {
    this->cpu_mem_total_mb = _arg;
    return *this;
  }
  Type & set__temperature_c(
    const float & _arg)
  {
    this->temperature_c = _arg;
    return *this;
  }
  Type & set__model_path(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model_path = _arg;
    return *this;
  }
  Type & set__model_version(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->model_version = _arg;
    return *this;
  }
  Type & set__precision(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->precision = _arg;
    return *this;
  }
  Type & set__input_width(
    const uint32_t & _arg)
  {
    this->input_width = _arg;
    return *this;
  }
  Type & set__input_height(
    const uint32_t & _arg)
  {
    this->input_height = _arg;
    return *this;
  }
  Type & set__frames_processed(
    const uint64_t & _arg)
  {
    this->frames_processed = _arg;
    return *this;
  }
  Type & set__detections_published(
    const uint64_t & _arg)
  {
    this->detections_published = _arg;
    return *this;
  }
  Type & set__errors_count(
    const uint64_t & _arg)
  {
    this->errors_count = _arg;
    return *this;
  }
  Type & set__last_error_time(
    const uint64_t & _arg)
  {
    this->last_error_time = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__active_alerts(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->active_alerts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pegasus_msgs::msg::NodeHealth_<ContainerAllocator> *;
  using ConstRawPtr =
    const pegasus_msgs::msg::NodeHealth_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::NodeHealth_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::NodeHealth_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pegasus_msgs__msg__NodeHealth
    std::shared_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pegasus_msgs__msg__NodeHealth
    std::shared_ptr<pegasus_msgs::msg::NodeHealth_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const NodeHealth_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->node_name != other.node_name) {
      return false;
    }
    if (this->device_id != other.device_id) {
      return false;
    }
    if (this->fps != other.fps) {
      return false;
    }
    if (this->avg_latency_ms != other.avg_latency_ms) {
      return false;
    }
    if (this->p95_latency_ms != other.p95_latency_ms) {
      return false;
    }
    if (this->p99_latency_ms != other.p99_latency_ms) {
      return false;
    }
    if (this->gpu_util_percent != other.gpu_util_percent) {
      return false;
    }
    if (this->gpu_mem_used_mb != other.gpu_mem_used_mb) {
      return false;
    }
    if (this->gpu_mem_total_mb != other.gpu_mem_total_mb) {
      return false;
    }
    if (this->cpu_util_percent != other.cpu_util_percent) {
      return false;
    }
    if (this->cpu_mem_used_mb != other.cpu_mem_used_mb) {
      return false;
    }
    if (this->cpu_mem_total_mb != other.cpu_mem_total_mb) {
      return false;
    }
    if (this->temperature_c != other.temperature_c) {
      return false;
    }
    if (this->model_path != other.model_path) {
      return false;
    }
    if (this->model_version != other.model_version) {
      return false;
    }
    if (this->precision != other.precision) {
      return false;
    }
    if (this->input_width != other.input_width) {
      return false;
    }
    if (this->input_height != other.input_height) {
      return false;
    }
    if (this->frames_processed != other.frames_processed) {
      return false;
    }
    if (this->detections_published != other.detections_published) {
      return false;
    }
    if (this->errors_count != other.errors_count) {
      return false;
    }
    if (this->last_error_time != other.last_error_time) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->active_alerts != other.active_alerts) {
      return false;
    }
    return true;
  }
  bool operator!=(const NodeHealth_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct NodeHealth_

// alias to use template instance with default allocator
using NodeHealth =
  pegasus_msgs::msg::NodeHealth_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_HPP_
