// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_HPP_

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
// Member 'detections'
#include "pegasus_msgs/msg/detail/defect_detection__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pegasus_msgs__msg__DefectArray __attribute__((deprecated))
#else
# define DEPRECATED__pegasus_msgs__msg__DefectArray __declspec(deprecated)
#endif

namespace pegasus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DefectArray_
{
  using Type = DefectArray_<ContainerAllocator>;

  explicit DefectArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->zone_id = "";
      this->total_count = 0ul;
      this->crack_count = 0ul;
      this->corrosion_count = 0ul;
      this->paint_damage_count = 0ul;
      this->max_risk_level = "";
      this->max_risk_id = 0;
      this->inference_latency = 0.0f;
      this->total_latency = 0.0f;
    }
  }

  explicit DefectArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    drone_id(_alloc),
    zone_id(_alloc),
    max_risk_level(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->zone_id = "";
      this->total_count = 0ul;
      this->crack_count = 0ul;
      this->corrosion_count = 0ul;
      this->paint_damage_count = 0ul;
      this->max_risk_level = "";
      this->max_risk_id = 0;
      this->inference_latency = 0.0f;
      this->total_latency = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;
  using _zone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_id_type zone_id;
  using _detections_type =
    std::vector<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>>;
  _detections_type detections;
  using _total_count_type =
    uint32_t;
  _total_count_type total_count;
  using _crack_count_type =
    uint32_t;
  _crack_count_type crack_count;
  using _corrosion_count_type =
    uint32_t;
  _corrosion_count_type corrosion_count;
  using _paint_damage_count_type =
    uint32_t;
  _paint_damage_count_type paint_damage_count;
  using _max_risk_level_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _max_risk_level_type max_risk_level;
  using _max_risk_id_type =
    uint8_t;
  _max_risk_id_type max_risk_id;
  using _inference_latency_type =
    float;
  _inference_latency_type inference_latency;
  using _total_latency_type =
    float;
  _total_latency_type total_latency;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__drone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->drone_id = _arg;
    return *this;
  }
  Type & set__zone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_id = _arg;
    return *this;
  }
  Type & set__detections(
    const std::vector<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>> & _arg)
  {
    this->detections = _arg;
    return *this;
  }
  Type & set__total_count(
    const uint32_t & _arg)
  {
    this->total_count = _arg;
    return *this;
  }
  Type & set__crack_count(
    const uint32_t & _arg)
  {
    this->crack_count = _arg;
    return *this;
  }
  Type & set__corrosion_count(
    const uint32_t & _arg)
  {
    this->corrosion_count = _arg;
    return *this;
  }
  Type & set__paint_damage_count(
    const uint32_t & _arg)
  {
    this->paint_damage_count = _arg;
    return *this;
  }
  Type & set__max_risk_level(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->max_risk_level = _arg;
    return *this;
  }
  Type & set__max_risk_id(
    const uint8_t & _arg)
  {
    this->max_risk_id = _arg;
    return *this;
  }
  Type & set__inference_latency(
    const float & _arg)
  {
    this->inference_latency = _arg;
    return *this;
  }
  Type & set__total_latency(
    const float & _arg)
  {
    this->total_latency = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pegasus_msgs::msg::DefectArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const pegasus_msgs::msg::DefectArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::DefectArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::DefectArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pegasus_msgs__msg__DefectArray
    std::shared_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pegasus_msgs__msg__DefectArray
    std::shared_ptr<pegasus_msgs::msg::DefectArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DefectArray_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->zone_id != other.zone_id) {
      return false;
    }
    if (this->detections != other.detections) {
      return false;
    }
    if (this->total_count != other.total_count) {
      return false;
    }
    if (this->crack_count != other.crack_count) {
      return false;
    }
    if (this->corrosion_count != other.corrosion_count) {
      return false;
    }
    if (this->paint_damage_count != other.paint_damage_count) {
      return false;
    }
    if (this->max_risk_level != other.max_risk_level) {
      return false;
    }
    if (this->max_risk_id != other.max_risk_id) {
      return false;
    }
    if (this->inference_latency != other.inference_latency) {
      return false;
    }
    if (this->total_latency != other.total_latency) {
      return false;
    }
    return true;
  }
  bool operator!=(const DefectArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DefectArray_

// alias to use template instance with default allocator
using DefectArray =
  pegasus_msgs::msg::DefectArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_HPP_
