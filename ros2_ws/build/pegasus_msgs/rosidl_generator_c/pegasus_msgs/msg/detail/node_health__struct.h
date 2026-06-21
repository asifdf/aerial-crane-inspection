// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from pegasus_msgs:msg/NodeHealth.idl
// generated code does not contain a copyright notice

#ifndef PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_H_
#define PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_H_

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
// Member 'node_name'
// Member 'device_id'
// Member 'model_path'
// Member 'model_version'
// Member 'precision'
// Member 'status'
// Member 'active_alerts'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/NodeHealth in the package pegasus_msgs.
/**
  * AI inference node health status
 */
typedef struct pegasus_msgs__msg__NodeHealth
{
  std_msgs__msg__Header header;
  rosidl_runtime_c__String node_name;
  /// e.g., "jetson_orin_nano_super"
  rosidl_runtime_c__String device_id;
  /// Performance metrics
  float fps;
  float avg_latency_ms;
  float p95_latency_ms;
  float p99_latency_ms;
  /// Resource usage
  float gpu_util_percent;
  float gpu_mem_used_mb;
  float gpu_mem_total_mb;
  float cpu_util_percent;
  float cpu_mem_used_mb;
  float cpu_mem_total_mb;
  float temperature_c;
  /// Model info
  rosidl_runtime_c__String model_path;
  rosidl_runtime_c__String model_version;
  /// "fp32", "fp16", "int8"
  rosidl_runtime_c__String precision;
  uint32_t input_width;
  uint32_t input_height;
  /// Counters
  uint64_t frames_processed;
  uint64_t detections_published;
  uint64_t errors_count;
  uint64_t last_error_time;
  /// Status
  /// "healthy", "degraded", "error", "starting"
  rosidl_runtime_c__String status;
  rosidl_runtime_c__String__Sequence active_alerts;
} pegasus_msgs__msg__NodeHealth;

// Struct for a sequence of pegasus_msgs__msg__NodeHealth.
typedef struct pegasus_msgs__msg__NodeHealth__Sequence
{
  pegasus_msgs__msg__NodeHealth * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} pegasus_msgs__msg__NodeHealth__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PEGASUS_MSGS__MSG__DETAIL__NODE_HEALTH__STRUCT_H_
