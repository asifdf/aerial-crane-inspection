// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_H_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'CLASS_CRACK'.
enum
{
  pegasus_msgs__msg__DefectDetection__CLASS_CRACK = 0
};

/// Constant 'CLASS_CORROSION'.
enum
{
  pegasus_msgs__msg__DefectDetection__CLASS_CORROSION = 1
};

/// Constant 'CLASS_PAINT_DAMAGE'.
enum
{
  pegasus_msgs__msg__DefectDetection__CLASS_PAINT_DAMAGE = 2
};

/// Constant 'RISK_LOW'.
enum
{
  pegasus_msgs__msg__DefectDetection__RISK_LOW = 0
};

/// Constant 'RISK_MEDIUM'.
enum
{
  pegasus_msgs__msg__DefectDetection__RISK_MEDIUM = 1
};

/// Constant 'RISK_HIGH'.
enum
{
  pegasus_msgs__msg__DefectDetection__RISK_HIGH = 2
};

/// Constant 'RISK_CRITICAL'.
enum
{
  pegasus_msgs__msg__DefectDetection__RISK_CRITICAL = 3
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'type'
// Member 'risk_level'
#include "rosidl_runtime_c/string.h"
// Member 'mask'
#include "sensor_msgs/msg/detail/compressed_image__struct.h"
// Member 'position_3d'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/DefectDetection in the package pegasus_msgs.
/**
  * Single defect detection result
 */
typedef struct pegasus_msgs__msg__DefectDetection
{
  std_msgs__msg__Header header;
  /// Classification
  /// "crack", "corrosion", "paint_damage"
  rosidl_runtime_c__String type;
  uint8_t class_id;
  /// Confidence [0.0, 1.0]
  float confidence;
  /// Bounding box in pixel coordinates (top-left origin)
  float bbox_x;
  float bbox_y;
  float bbox_width;
  float bbox_height;
  /// Optional: normalized bbox [0,1] for resolution-invariant use
  float bbox_x_norm;
  float bbox_y_norm;
  float bbox_width_norm;
  float bbox_height_norm;
  /// Risk assessment
  /// "low", "medium", "high", "critical"
  rosidl_runtime_c__String risk_level;
  uint8_t risk_id;
  /// Optional segmentation mask (compressed PNG)
  sensor_msgs__msg__CompressedImage mask;
  /// 3D position estimate (if depth available)
  geometry_msgs__msg__Point position_3d;
  bool has_3d_position;
} pegasus_msgs__msg__DefectDetection;

// Struct for a sequence of pegasus_msgs__msg__DefectDetection.
typedef struct pegasus_msgs__msg__DefectDetection__Sequence
{
  pegasus_msgs__msg__DefectDetection * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pegasus_msgs__msg__DefectDetection__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_DETECTION__STRUCT_H_
