// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_HPP_

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
// Member 'zone_center'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'zone_dimensions'
#include "geometry_msgs/msg/detail/vector3__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pegasus_msgs__msg__ZoneInfo __attribute__((deprecated))
#else
# define DEPRECATED__pegasus_msgs__msg__ZoneInfo __declspec(deprecated)
#endif

namespace pegasus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ZoneInfo_
{
  using Type = ZoneInfo_<ContainerAllocator>;

  explicit ZoneInfo_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    zone_center(_init),
    zone_dimensions(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->zone_id = "";
      this->zone_name = "";
      this->zone_type = "";
      this->priority = 0;
    }
  }

  explicit ZoneInfo_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    zone_id(_alloc),
    zone_name(_alloc),
    zone_type(_alloc),
    zone_center(_alloc, _init),
    zone_dimensions(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->zone_id = "";
      this->zone_name = "";
      this->zone_type = "";
      this->priority = 0;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _zone_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_id_type zone_id;
  using _zone_name_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_name_type zone_name;
  using _zone_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _zone_type_type zone_type;
  using _zone_center_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _zone_center_type zone_center;
  using _zone_dimensions_type =
    geometry_msgs::msg::Vector3_<ContainerAllocator>;
  _zone_dimensions_type zone_dimensions;
  using _waypoints_x_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _waypoints_x_type waypoints_x;
  using _waypoints_y_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _waypoints_y_type waypoints_y;
  using _waypoints_z_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _waypoints_z_type waypoints_z;
  using _waypoints_yaw_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _waypoints_yaw_type waypoints_yaw;
  using _camera_pitch_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _camera_pitch_type camera_pitch;
  using _camera_yaw_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _camera_yaw_type camera_yaw;
  using _expected_defects_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _expected_defects_type expected_defects;
  using _priority_type =
    uint8_t;
  _priority_type priority;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__zone_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_id = _arg;
    return *this;
  }
  Type & set__zone_name(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_name = _arg;
    return *this;
  }
  Type & set__zone_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->zone_type = _arg;
    return *this;
  }
  Type & set__zone_center(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->zone_center = _arg;
    return *this;
  }
  Type & set__zone_dimensions(
    const geometry_msgs::msg::Vector3_<ContainerAllocator> & _arg)
  {
    this->zone_dimensions = _arg;
    return *this;
  }
  Type & set__waypoints_x(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->waypoints_x = _arg;
    return *this;
  }
  Type & set__waypoints_y(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->waypoints_y = _arg;
    return *this;
  }
  Type & set__waypoints_z(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->waypoints_z = _arg;
    return *this;
  }
  Type & set__waypoints_yaw(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->waypoints_yaw = _arg;
    return *this;
  }
  Type & set__camera_pitch(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->camera_pitch = _arg;
    return *this;
  }
  Type & set__camera_yaw(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->camera_yaw = _arg;
    return *this;
  }
  Type & set__expected_defects(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->expected_defects = _arg;
    return *this;
  }
  Type & set__priority(
    const uint8_t & _arg)
  {
    this->priority = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> *;
  using ConstRawPtr =
    const pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pegasus_msgs__msg__ZoneInfo
    std::shared_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pegasus_msgs__msg__ZoneInfo
    std::shared_ptr<pegasus_msgs::msg::ZoneInfo_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ZoneInfo_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->zone_id != other.zone_id) {
      return false;
    }
    if (this->zone_name != other.zone_name) {
      return false;
    }
    if (this->zone_type != other.zone_type) {
      return false;
    }
    if (this->zone_center != other.zone_center) {
      return false;
    }
    if (this->zone_dimensions != other.zone_dimensions) {
      return false;
    }
    if (this->waypoints_x != other.waypoints_x) {
      return false;
    }
    if (this->waypoints_y != other.waypoints_y) {
      return false;
    }
    if (this->waypoints_z != other.waypoints_z) {
      return false;
    }
    if (this->waypoints_yaw != other.waypoints_yaw) {
      return false;
    }
    if (this->camera_pitch != other.camera_pitch) {
      return false;
    }
    if (this->camera_yaw != other.camera_yaw) {
      return false;
    }
    if (this->expected_defects != other.expected_defects) {
      return false;
    }
    if (this->priority != other.priority) {
      return false;
    }
    return true;
  }
  bool operator!=(const ZoneInfo_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ZoneInfo_

// alias to use template instance with default allocator
using ZoneInfo =
  pegasus_msgs::msg::ZoneInfo_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__ZONE_INFO__STRUCT_HPP_
