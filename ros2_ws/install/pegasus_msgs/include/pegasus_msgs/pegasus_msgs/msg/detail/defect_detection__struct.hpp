// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_HPP_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_HPP_

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
// Member 'mask'
#include "sensor_msgs/msg/detail/compressed_image__struct.hpp"
// Member 'position_3d'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__pegasus_msgs__msg__DefectDetection __attribute__((deprecated))
#else
# define DEPRECATED__pegasus_msgs__msg__DefectDetection __declspec(deprecated)
#endif

namespace pegasus_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DefectDetection_
{
  using Type = DefectDetection_<ContainerAllocator>;

  explicit DefectDetection_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    mask(_init),
    position_3d(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->class_id = 0;
      this->confidence = 0.0f;
      this->bbox_x = 0.0f;
      this->bbox_y = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
      this->bbox_x_norm = 0.0f;
      this->bbox_y_norm = 0.0f;
      this->bbox_width_norm = 0.0f;
      this->bbox_height_norm = 0.0f;
      this->risk_level = "";
      this->risk_id = 0;
      this->has_3d_position = false;
    }
  }

  explicit DefectDetection_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    type(_alloc),
    risk_level(_alloc),
    mask(_alloc, _init),
    position_3d(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->type = "";
      this->class_id = 0;
      this->confidence = 0.0f;
      this->bbox_x = 0.0f;
      this->bbox_y = 0.0f;
      this->bbox_width = 0.0f;
      this->bbox_height = 0.0f;
      this->bbox_x_norm = 0.0f;
      this->bbox_y_norm = 0.0f;
      this->bbox_width_norm = 0.0f;
      this->bbox_height_norm = 0.0f;
      this->risk_level = "";
      this->risk_id = 0;
      this->has_3d_position = false;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _type_type type;
  using _class_id_type =
    uint8_t;
  _class_id_type class_id;
  using _confidence_type =
    float;
  _confidence_type confidence;
  using _bbox_x_type =
    float;
  _bbox_x_type bbox_x;
  using _bbox_y_type =
    float;
  _bbox_y_type bbox_y;
  using _bbox_width_type =
    float;
  _bbox_width_type bbox_width;
  using _bbox_height_type =
    float;
  _bbox_height_type bbox_height;
  using _bbox_x_norm_type =
    float;
  _bbox_x_norm_type bbox_x_norm;
  using _bbox_y_norm_type =
    float;
  _bbox_y_norm_type bbox_y_norm;
  using _bbox_width_norm_type =
    float;
  _bbox_width_norm_type bbox_width_norm;
  using _bbox_height_norm_type =
    float;
  _bbox_height_norm_type bbox_height_norm;
  using _risk_level_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _risk_level_type risk_level;
  using _risk_id_type =
    uint8_t;
  _risk_id_type risk_id;
  using _mask_type =
    sensor_msgs::msg::CompressedImage_<ContainerAllocator>;
  _mask_type mask;
  using _position_3d_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _position_3d_type position_3d;
  using _has_3d_position_type =
    bool;
  _has_3d_position_type has_3d_position;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->type = _arg;
    return *this;
  }
  Type & set__class_id(
    const uint8_t & _arg)
  {
    this->class_id = _arg;
    return *this;
  }
  Type & set__confidence(
    const float & _arg)
  {
    this->confidence = _arg;
    return *this;
  }
  Type & set__bbox_x(
    const float & _arg)
  {
    this->bbox_x = _arg;
    return *this;
  }
  Type & set__bbox_y(
    const float & _arg)
  {
    this->bbox_y = _arg;
    return *this;
  }
  Type & set__bbox_width(
    const float & _arg)
  {
    this->bbox_width = _arg;
    return *this;
  }
  Type & set__bbox_height(
    const float & _arg)
  {
    this->bbox_height = _arg;
    return *this;
  }
  Type & set__bbox_x_norm(
    const float & _arg)
  {
    this->bbox_x_norm = _arg;
    return *this;
  }
  Type & set__bbox_y_norm(
    const float & _arg)
  {
    this->bbox_y_norm = _arg;
    return *this;
  }
  Type & set__bbox_width_norm(
    const float & _arg)
  {
    this->bbox_width_norm = _arg;
    return *this;
  }
  Type & set__bbox_height_norm(
    const float & _arg)
  {
    this->bbox_height_norm = _arg;
    return *this;
  }
  Type & set__risk_level(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->risk_level = _arg;
    return *this;
  }
  Type & set__risk_id(
    const uint8_t & _arg)
  {
    this->risk_id = _arg;
    return *this;
  }
  Type & set__mask(
    const sensor_msgs::msg::CompressedImage_<ContainerAllocator> & _arg)
  {
    this->mask = _arg;
    return *this;
  }
  Type & set__position_3d(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->position_3d = _arg;
    return *this;
  }
  Type & set__has_3d_position(
    const bool & _arg)
  {
    this->has_3d_position = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t CLASS_CRACK =
    0u;
  static constexpr uint8_t CLASS_CORROSION =
    1u;
  static constexpr uint8_t CLASS_PAINT_DAMAGE =
    2u;
  static constexpr uint8_t RISK_LOW =
    0u;
  static constexpr uint8_t RISK_MEDIUM =
    1u;
  static constexpr uint8_t RISK_HIGH =
    2u;
  static constexpr uint8_t RISK_CRITICAL =
    3u;

  // pointer types
  using RawPtr =
    pegasus_msgs::msg::DefectDetection_<ContainerAllocator> *;
  using ConstRawPtr =
    const pegasus_msgs::msg::DefectDetection_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__pegasus_msgs__msg__DefectDetection
    std::shared_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__pegasus_msgs__msg__DefectDetection
    std::shared_ptr<pegasus_msgs::msg::DefectDetection_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DefectDetection_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->type != other.type) {
      return false;
    }
    if (this->class_id != other.class_id) {
      return false;
    }
    if (this->confidence != other.confidence) {
      return false;
    }
    if (this->bbox_x != other.bbox_x) {
      return false;
    }
    if (this->bbox_y != other.bbox_y) {
      return false;
    }
    if (this->bbox_width != other.bbox_width) {
      return false;
    }
    if (this->bbox_height != other.bbox_height) {
      return false;
    }
    if (this->bbox_x_norm != other.bbox_x_norm) {
      return false;
    }
    if (this->bbox_y_norm != other.bbox_y_norm) {
      return false;
    }
    if (this->bbox_width_norm != other.bbox_width_norm) {
      return false;
    }
    if (this->bbox_height_norm != other.bbox_height_norm) {
      return false;
    }
    if (this->risk_level != other.risk_level) {
      return false;
    }
    if (this->risk_id != other.risk_id) {
      return false;
    }
    if (this->mask != other.mask) {
      return false;
    }
    if (this->position_3d != other.position_3d) {
      return false;
    }
    if (this->has_3d_position != other.has_3d_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const DefectDetection_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DefectDetection_

// alias to use template instance with default allocator
using DefectDetection =
  pegasus_msgs::msg::DefectDetection_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::CLASS_CRACK;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::CLASS_CORROSION;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::CLASS_PAINT_DAMAGE;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::RISK_LOW;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::RISK_MEDIUM;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::RISK_HIGH;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr uint8_t DefectDetection_<ContainerAllocator>::RISK_CRITICAL;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace pegasus_msgs

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_HPP_
