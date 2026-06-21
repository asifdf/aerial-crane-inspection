// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_HPP_

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
// Member 'drone_pose'
#include "geometry_msgs/msg/detail/pose_stamped__struct.hpp"
// Member 'defects'
#include "pegasus_msgs/msg/detail/defect_array__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pegasus_msgs__msg__InspectionResult __attribute__((deprecated))
#else
# define DEPRECATED__pegasus_msgs__msg__InspectionResult __declspec(deprecated)
#endif

namespace pegasus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InspectionResult_
{
  using Type = InspectionResult_<ContainerAllocator>;

  explicit InspectionResult_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    drone_pose(_init),
    defects(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->mission_id = "";
      this->zone_id = "";
      this->coverage_percent = 0.0f;
      this->images_captured = 0ul;
      this->images_with_defects = 0ul;
      this->zone_risk_level = "";
      this->zone_risk_id = 0;
      this->json_payload = "";
    }
  }

  explicit InspectionResult_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    drone_id(_alloc),
    mission_id(_alloc),
    zone_id(_alloc),
    drone_pose(_alloc, _init),
    defects(_alloc, _init),
    zone_risk_level(_alloc),
    json_payload(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->drone_id = "";
      this->mission_id = "";
      this->zone_id = "";
      this->coverage_percent = 0.0f;
      this->images_captured = 0ul;
      this->images_with_defects = 0ul;
      this->zone_risk_level = "";
      this->zone_risk_id = 0;
      this->json_payload = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _drone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _drone_id_type drone_id;
  using _mission_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _mission_id_type mission_id;
  using _zone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_id_type zone_id;
  using _drone_pose_type =
    geometry_msgs::msg::PoseStamped_<ContainerAllocator>;
  _drone_pose_type drone_pose;
  using _defects_type =
    pegasus_msgs::msg::DefectArray_<ContainerAllocator>;
  _defects_type defects;
  using _coverage_percent_type =
    float;
  _coverage_percent_type coverage_percent;
  using _images_captured_type =
    uint32_t;
  _images_captured_type images_captured;
  using _images_with_defects_type =
    uint32_t;
  _images_with_defects_type images_with_defects;
  using _zone_risk_level_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_risk_level_type zone_risk_level;
  using _zone_risk_id_type =
    uint8_t;
  _zone_risk_id_type zone_risk_id;
  using _json_payload_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _json_payload_type json_payload;

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
  Type & set__mission_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->mission_id = _arg;
    return *this;
  }
  Type & set__zone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_id = _arg;
    return *this;
  }
  Type & set__drone_pose(
    const geometry_msgs::msg::PoseStamped_<ContainerAllocator> & _arg)
  {
    this->drone_pose = _arg;
    return *this;
  }
  Type & set__defects(
    const pegasus_msgs::msg::DefectArray_<ContainerAllocator> & _arg)
  {
    this->defects = _arg;
    return *this;
  }
  Type & set__coverage_percent(
    const float & _arg)
  {
    this->coverage_percent = _arg;
    return *this;
  }
  Type & set__images_captured(
    const uint32_t & _arg)
  {
    this->images_captured = _arg;
    return *this;
  }
  Type & set__images_with_defects(
    const uint32_t & _arg)
  {
    this->images_with_defects = _arg;
    return *this;
  }
  Type & set__zone_risk_level(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_risk_level = _arg;
    return *this;
  }
  Type & set__zone_risk_id(
    const uint8_t & _arg)
  {
    this->zone_risk_id = _arg;
    return *this;
  }
  Type & set__json_payload(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->json_payload = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pegasus_msgs::msg::InspectionResult_<ContainerAllocator> *;
  using ConstRawPtr =
    const pegasus_msgs::msg::InspectionResult_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::InspectionResult_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::InspectionResult_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pegasus_msgs__msg__InspectionResult
    std::shared_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pegasus_msgs__msg__InspectionResult
    std::shared_ptr<pegasus_msgs::msg::InspectionResult_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InspectionResult_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->drone_id != other.drone_id) {
      return false;
    }
    if (this->mission_id != other.mission_id) {
      return false;
    }
    if (this->zone_id != other.zone_id) {
      return false;
    }
    if (this->drone_pose != other.drone_pose) {
      return false;
    }
    if (this->defects != other.defects) {
      return false;
    }
    if (this->coverage_percent != other.coverage_percent) {
      return false;
    }
    if (this->images_captured != other.images_captured) {
      return false;
    }
    if (this->images_with_defects != other.images_with_defects) {
      return false;
    }
    if (this->zone_risk_level != other.zone_risk_level) {
      return false;
    }
    if (this->zone_risk_id != other.zone_risk_id) {
      return false;
    }
    if (this->json_payload != other.json_payload) {
      return false;
    }
    return true;
  }
  bool operator!=(const InspectionResult_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InspectionResult_

// alias to use template instance with default allocator
using InspectionResult =
  pegasus_msgs::msg::InspectionResult_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__INSPECTION_RESULT__STRUCT_HPP_
