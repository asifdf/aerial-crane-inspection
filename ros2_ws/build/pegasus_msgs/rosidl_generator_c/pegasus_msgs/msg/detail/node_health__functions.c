// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pegasus_msgs:msg/NodeHealth.idl
// generated code does not contain a copyright notice
#include "pegasus_msgs/msg/detail/node_health__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `node_name`
// Member `device_id`
// Member `model_path`
// Member `model_version`
// Member `precision`
// Member `status`
// Member `active_alerts`
#include "rosidl_runtime_c/string_functions.h"

bool
pegasus_msgs__msg__NodeHealth__init(pegasus_msgs__msg__NodeHealth * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__init(&msg->node_name)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__init(&msg->device_id)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // fps
  // avg_latency_ms
  // p95_latency_ms
  // p99_latency_ms
  // gpu_util_percent
  // gpu_mem_used_mb
  // gpu_mem_total_mb
  // cpu_util_percent
  // cpu_mem_used_mb
  // cpu_mem_total_mb
  // temperature_c
  // model_path
  if (!rosidl_runtime_c__String__init(&msg->model_path)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // model_version
  if (!rosidl_runtime_c__String__init(&msg->model_version)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // precision
  if (!rosidl_runtime_c__String__init(&msg->precision)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // input_width
  // input_height
  // frames_processed
  // detections_published
  // errors_count
  // last_error_time
  // status
  if (!rosidl_runtime_c__String__init(&msg->status)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  // active_alerts
  if (!rosidl_runtime_c__String__Sequence__init(&msg->active_alerts, 0)) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
    return false;
  }
  return true;
}

void
pegasus_msgs__msg__NodeHealth__fini(pegasus_msgs__msg__NodeHealth * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // node_name
  rosidl_runtime_c__String__fini(&msg->node_name);
  // device_id
  rosidl_runtime_c__String__fini(&msg->device_id);
  // fps
  // avg_latency_ms
  // p95_latency_ms
  // p99_latency_ms
  // gpu_util_percent
  // gpu_mem_used_mb
  // gpu_mem_total_mb
  // cpu_util_percent
  // cpu_mem_used_mb
  // cpu_mem_total_mb
  // temperature_c
  // model_path
  rosidl_runtime_c__String__fini(&msg->model_path);
  // model_version
  rosidl_runtime_c__String__fini(&msg->model_version);
  // precision
  rosidl_runtime_c__String__fini(&msg->precision);
  // input_width
  // input_height
  // frames_processed
  // detections_published
  // errors_count
  // last_error_time
  // status
  rosidl_runtime_c__String__fini(&msg->status);
  // active_alerts
  rosidl_runtime_c__String__Sequence__fini(&msg->active_alerts);
}

bool
pegasus_msgs__msg__NodeHealth__are_equal(const pegasus_msgs__msg__NodeHealth * lhs, const pegasus_msgs__msg__NodeHealth * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->node_name), &(rhs->node_name)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->device_id), &(rhs->device_id)))
  {
    return false;
  }
  // fps
  if (lhs->fps != rhs->fps) {
    return false;
  }
  // avg_latency_ms
  if (lhs->avg_latency_ms != rhs->avg_latency_ms) {
    return false;
  }
  // p95_latency_ms
  if (lhs->p95_latency_ms != rhs->p95_latency_ms) {
    return false;
  }
  // p99_latency_ms
  if (lhs->p99_latency_ms != rhs->p99_latency_ms) {
    return false;
  }
  // gpu_util_percent
  if (lhs->gpu_util_percent != rhs->gpu_util_percent) {
    return false;
  }
  // gpu_mem_used_mb
  if (lhs->gpu_mem_used_mb != rhs->gpu_mem_used_mb) {
    return false;
  }
  // gpu_mem_total_mb
  if (lhs->gpu_mem_total_mb != rhs->gpu_mem_total_mb) {
    return false;
  }
  // cpu_util_percent
  if (lhs->cpu_util_percent != rhs->cpu_util_percent) {
    return false;
  }
  // cpu_mem_used_mb
  if (lhs->cpu_mem_used_mb != rhs->cpu_mem_used_mb) {
    return false;
  }
  // cpu_mem_total_mb
  if (lhs->cpu_mem_total_mb != rhs->cpu_mem_total_mb) {
    return false;
  }
  // temperature_c
  if (lhs->temperature_c != rhs->temperature_c) {
    return false;
  }
  // model_path
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model_path), &(rhs->model_path)))
  {
    return false;
  }
  // model_version
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->model_version), &(rhs->model_version)))
  {
    return false;
  }
  // precision
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->precision), &(rhs->precision)))
  {
    return false;
  }
  // input_width
  if (lhs->input_width != rhs->input_width) {
    return false;
  }
  // input_height
  if (lhs->input_height != rhs->input_height) {
    return false;
  }
  // frames_processed
  if (lhs->frames_processed != rhs->frames_processed) {
    return false;
  }
  // detections_published
  if (lhs->detections_published != rhs->detections_published) {
    return false;
  }
  // errors_count
  if (lhs->errors_count != rhs->errors_count) {
    return false;
  }
  // last_error_time
  if (lhs->last_error_time != rhs->last_error_time) {
    return false;
  }
  // status
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->status), &(rhs->status)))
  {
    return false;
  }
  // active_alerts
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->active_alerts), &(rhs->active_alerts)))
  {
    return false;
  }
  return true;
}

bool
pegasus_msgs__msg__NodeHealth__copy(
  const pegasus_msgs__msg__NodeHealth * input,
  pegasus_msgs__msg__NodeHealth * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__copy(
      &(input->node_name), &(output->node_name)))
  {
    return false;
  }
  // device_id
  if (!rosidl_runtime_c__String__copy(
      &(input->device_id), &(output->device_id)))
  {
    return false;
  }
  // fps
  output->fps = input->fps;
  // avg_latency_ms
  output->avg_latency_ms = input->avg_latency_ms;
  // p95_latency_ms
  output->p95_latency_ms = input->p95_latency_ms;
  // p99_latency_ms
  output->p99_latency_ms = input->p99_latency_ms;
  // gpu_util_percent
  output->gpu_util_percent = input->gpu_util_percent;
  // gpu_mem_used_mb
  output->gpu_mem_used_mb = input->gpu_mem_used_mb;
  // gpu_mem_total_mb
  output->gpu_mem_total_mb = input->gpu_mem_total_mb;
  // cpu_util_percent
  output->cpu_util_percent = input->cpu_util_percent;
  // cpu_mem_used_mb
  output->cpu_mem_used_mb = input->cpu_mem_used_mb;
  // cpu_mem_total_mb
  output->cpu_mem_total_mb = input->cpu_mem_total_mb;
  // temperature_c
  output->temperature_c = input->temperature_c;
  // model_path
  if (!rosidl_runtime_c__String__copy(
      &(input->model_path), &(output->model_path)))
  {
    return false;
  }
  // model_version
  if (!rosidl_runtime_c__String__copy(
      &(input->model_version), &(output->model_version)))
  {
    return false;
  }
  // precision
  if (!rosidl_runtime_c__String__copy(
      &(input->precision), &(output->precision)))
  {
    return false;
  }
  // input_width
  output->input_width = input->input_width;
  // input_height
  output->input_height = input->input_height;
  // frames_processed
  output->frames_processed = input->frames_processed;
  // detections_published
  output->detections_published = input->detections_published;
  // errors_count
  output->errors_count = input->errors_count;
  // last_error_time
  output->last_error_time = input->last_error_time;
  // status
  if (!rosidl_runtime_c__String__copy(
      &(input->status), &(output->status)))
  {
    return false;
  }
  // active_alerts
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->active_alerts), &(output->active_alerts)))
  {
    return false;
  }
  return true;
}

pegasus_msgs__msg__NodeHealth *
pegasus_msgs__msg__NodeHealth__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__NodeHealth * msg = (pegasus_msgs__msg__NodeHealth *)allocator.allocate(sizeof(pegasus_msgs__msg__NodeHealth), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pegasus_msgs__msg__NodeHealth));
  bool success = pegasus_msgs__msg__NodeHealth__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pegasus_msgs__msg__NodeHealth__destroy(pegasus_msgs__msg__NodeHealth * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pegasus_msgs__msg__NodeHealth__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pegasus_msgs__msg__NodeHealth__Sequence__init(pegasus_msgs__msg__NodeHealth__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__NodeHealth * data = NULL;

  if (size) {
    data = (pegasus_msgs__msg__NodeHealth *)allocator.zero_allocate(size, sizeof(pegasus_msgs__msg__NodeHealth), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pegasus_msgs__msg__NodeHealth__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pegasus_msgs__msg__NodeHealth__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
pegasus_msgs__msg__NodeHealth__Sequence__fini(pegasus_msgs__msg__NodeHealth__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      pegasus_msgs__msg__NodeHealth__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

pegasus_msgs__msg__NodeHealth__Sequence *
pegasus_msgs__msg__NodeHealth__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__NodeHealth__Sequence * array = (pegasus_msgs__msg__NodeHealth__Sequence *)allocator.allocate(sizeof(pegasus_msgs__msg__NodeHealth__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pegasus_msgs__msg__NodeHealth__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pegasus_msgs__msg__NodeHealth__Sequence__destroy(pegasus_msgs__msg__NodeHealth__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pegasus_msgs__msg__NodeHealth__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pegasus_msgs__msg__NodeHealth__Sequence__are_equal(const pegasus_msgs__msg__NodeHealth__Sequence * lhs, const pegasus_msgs__msg__NodeHealth__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pegasus_msgs__msg__NodeHealth__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pegasus_msgs__msg__NodeHealth__Sequence__copy(
  const pegasus_msgs__msg__NodeHealth__Sequence * input,
  pegasus_msgs__msg__NodeHealth__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pegasus_msgs__msg__NodeHealth);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pegasus_msgs__msg__NodeHealth * data =
      (pegasus_msgs__msg__NodeHealth *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pegasus_msgs__msg__NodeHealth__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pegasus_msgs__msg__NodeHealth__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pegasus_msgs__msg__NodeHealth__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
