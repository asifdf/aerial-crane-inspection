// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice

#ifndef AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_HPP_
#define AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__autopilot_interface_msgs__msg__OffboardFlag __attribute__((deprecated))
#else
# define DEPRECATED__autopilot_interface_msgs__msg__OffboardFlag __declspec(deprecated)
#endif

namespace autopilot_interface_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct OffboardFlag_
{
  using Type = OffboardFlag_<ContainerAllocator>;

  explicit OffboardFlag_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offboard_flag = 0;
    }
  }

  explicit OffboardFlag_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->offboard_flag = 0;
    }
  }

  // field types and members
  using _offboard_flag_type =
    uint8_t;
  _offboard_flag_type offboard_flag;

  // setters for named parameter idiom
  Type & set__offboard_flag(
    const uint8_t & _arg)
  {
    this->offboard_flag = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t INACTIVE =
    0u;
  static constexpr uint8_t PX4_QUAD_ATTITUDE =
    1u;
  static constexpr uint8_t PX4_VTOL_ATTITUDE =
    2u;
  static constexpr uint8_t PX4_QUAD_RATES =
    3u;
  static constexpr uint8_t PX4_VTOL_RATES =
    4u;
  static constexpr uint8_t PX4_QUAD_TRAJECTORY =
    5u;
  static constexpr uint8_t PX4_VTOL_TRAJECTORY =
    6u;
  static constexpr uint8_t AP_QUAD_VELOCITY =
    7u;
  static constexpr uint8_t AP_QUAD_ACCELERATION =
    8u;

  // pointer types
  using RawPtr =
    autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> *;
  using ConstRawPtr =
    const autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__autopilot_interface_msgs__msg__OffboardFlag
    std::shared_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__autopilot_interface_msgs__msg__OffboardFlag
    std::shared_ptr<autopilot_interface_msgs::msg::OffboardFlag_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const OffboardFlag_ & other) const
  {
    if (this->offboard_flag != other.offboard_flag) {
      return false;
    }
    return true;
  }
  bool operator!=(const OffboardFlag_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct OffboardFlag_

// alias to use template instance with default allocator
using OffboardFlag =
  autopilot_interface_msgs::msg::OffboardFlag_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::INACTIVE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_QUAD_ATTITUDE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_VTOL_ATTITUDE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_QUAD_RATES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_VTOL_RATES;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_QUAD_TRAJECTORY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::PX4_VTOL_TRAJECTORY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::AP_QUAD_VELOCITY;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t OffboardFlag_<ContainerAllocator>::AP_QUAD_ACCELERATION;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace autopilot_interface_msgs

#endif  // AUTOPILOT_INTERFACE_MSGS__MSG__DETAIL__OFFBOARD_FLAG__STRUCT_HPP_
