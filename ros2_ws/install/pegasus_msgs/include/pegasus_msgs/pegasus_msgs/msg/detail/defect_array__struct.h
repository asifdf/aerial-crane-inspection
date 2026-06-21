// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_H_
#define PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'drone_id'
// Member 'zone_id'
// Member 'max_risk_level'
#include "rosidl_runtime_c/string.h"
// Member 'detections'
#include "pegasus_msgs/msg/detail/defect_detection__struct.h"

/// Struct defined in msg/DefectArray in the package pegasus_msgs.
/**
  * Array of defect detections for a single frame
 */
typedef struct pegasus_msgs__msg__DefectArray
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String drone_id;
  rosidl_runtime_c__String zone_id;
  /// All detections in this frame
  pegasus_msgs__msg__DefectDetection__Sequence detections;
  /// Summary counts
  uint32_t total_count;
  uint32_t crack_count;
  uint32_t corrosion_count;
  uint32_t paint_damage_count;
  /// Highest risk in this frame
  rosidl_runtime_c__String max_risk_level;
  uint8_t max_risk_id;
  /// Processing latency (seconds)
  float inference_latency;
  float total_latency;
} pegasus_msgs__msg__DefectArray;

// Struct for a sequence of pegasus_msgs__msg__DefectArray.
typedef struct pegasus_msgs__msg__DefectArray__Sequence
{
  pegasus_msgs__msg__DefectArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pegasus_msgs__msg__DefectArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__DEFECT_ARRAY__STRUCT_H_
