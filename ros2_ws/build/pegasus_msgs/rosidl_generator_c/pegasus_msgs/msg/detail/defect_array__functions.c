// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pegasus_msgs:msg/DefectArray.idl
// generated code does not contain a copyright notice
#include "pegasus_msgs/msg/detail/defect_array__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `drone_id`
// Member `zone_id`
// Member `max_risk_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `detections`
#include "pegasus_msgs/msg/detail/defect_detection__functions.h"

bool
pegasus_msgs__msg__DefectArray__init(pegasus_msgs__msg__DefectArray * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pegasus_msgs__msg__DefectArray__fini(msg);
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    pegasus_msgs__msg__DefectArray__fini(msg);
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__init(&msg->zone_id)) {
    pegasus_msgs__msg__DefectArray__fini(msg);
    return false;
  }
  // detections
  if (!pegasus_msgs__msg__DefectDetection__Sequence__init(&msg->detections, 0)) {
    pegasus_msgs__msg__DefectArray__fini(msg);
    return false;
  }
  // total_count
  // crack_count
  // corrosion_count
  // paint_damage_count
  // max_risk_level
  if (!rosidl_runtime_c__String__init(&msg->max_risk_level)) {
    pegasus_msgs__msg__DefectArray__fini(msg);
    return false;
  }
  // max_risk_id
  // inference_latency
  // total_latency
  return true;
}

void
pegasus_msgs__msg__DefectArray__fini(pegasus_msgs__msg__DefectArray * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // zone_id
  rosidl_runtime_c__String__fini(&msg->zone_id);
  // detections
  pegasus_msgs__msg__DefectDetection__Sequence__fini(&msg->detections);
  // total_count
  // crack_count
  // corrosion_count
  // paint_damage_count
  // max_risk_level
  rosidl_runtime_c__String__fini(&msg->max_risk_level);
  // max_risk_id
  // inference_latency
  // total_latency
}

bool
pegasus_msgs__msg__DefectArray__are_equal(const pegasus_msgs__msg__DefectArray * lhs, const pegasus_msgs__msg__DefectArray * rhs)
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
  // drone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->drone_id), &(rhs->drone_id)))
  {
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_id), &(rhs->zone_id)))
  {
    return false;
  }
  // detections
  if (!pegasus_msgs__msg__DefectDetection__Sequence__are_equal(
      &(lhs->detections), &(rhs->detections)))
  {
    return false;
  }
  // total_count
  if (lhs->total_count != rhs->total_count) {
    return false;
  }
  // crack_count
  if (lhs->crack_count != rhs->crack_count) {
    return false;
  }
  // corrosion_count
  if (lhs->corrosion_count != rhs->corrosion_count) {
    return false;
  }
  // paint_damage_count
  if (lhs->paint_damage_count != rhs->paint_damage_count) {
    return false;
  }
  // max_risk_level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->max_risk_level), &(rhs->max_risk_level)))
  {
    return false;
  }
  // max_risk_id
  if (lhs->max_risk_id != rhs->max_risk_id) {
    return false;
  }
  // inference_latency
  if (lhs->inference_latency != rhs->inference_latency) {
    return false;
  }
  // total_latency
  if (lhs->total_latency != rhs->total_latency) {
    return false;
  }
  return true;
}

bool
pegasus_msgs__msg__DefectArray__copy(
  const pegasus_msgs__msg__DefectArray * input,
  pegasus_msgs__msg__DefectArray * output)
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
  // drone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->drone_id), &(output->drone_id)))
  {
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_id), &(output->zone_id)))
  {
    return false;
  }
  // detections
  if (!pegasus_msgs__msg__DefectDetection__Sequence__copy(
      &(input->detections), &(output->detections)))
  {
    return false;
  }
  // total_count
  output->total_count = input->total_count;
  // crack_count
  output->crack_count = input->crack_count;
  // corrosion_count
  output->corrosion_count = input->corrosion_count;
  // paint_damage_count
  output->paint_damage_count = input->paint_damage_count;
  // max_risk_level
  if (!rosidl_runtime_c__String__copy(
      &(input->max_risk_level), &(output->max_risk_level)))
  {
    return false;
  }
  // max_risk_id
  output->max_risk_id = input->max_risk_id;
  // inference_latency
  output->inference_latency = input->inference_latency;
  // total_latency
  output->total_latency = input->total_latency;
  return true;
}

pegasus_msgs__msg__DefectArray *
pegasus_msgs__msg__DefectArray__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectArray * msg = (pegasus_msgs__msg__DefectArray *)allocator.allocate(sizeof(pegasus_msgs__msg__DefectArray), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pegasus_msgs__msg__DefectArray));
  bool success = pegasus_msgs__msg__DefectArray__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pegasus_msgs__msg__DefectArray__destroy(pegasus_msgs__msg__DefectArray * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pegasus_msgs__msg__DefectArray__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pegasus_msgs__msg__DefectArray__Sequence__init(pegasus_msgs__msg__DefectArray__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectArray * data = NULL;

  if (size) {
    data = (pegasus_msgs__msg__DefectArray *)allocator.zero_allocate(size, sizeof(pegasus_msgs__msg__DefectArray), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pegasus_msgs__msg__DefectArray__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pegasus_msgs__msg__DefectArray__fini(&data[i - 1]);
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
pegasus_msgs__msg__DefectArray__Sequence__fini(pegasus_msgs__msg__DefectArray__Sequence * array)
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
      pegasus_msgs__msg__DefectArray__fini(&array->data[i]);
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

pegasus_msgs__msg__DefectArray__Sequence *
pegasus_msgs__msg__DefectArray__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectArray__Sequence * array = (pegasus_msgs__msg__DefectArray__Sequence *)allocator.allocate(sizeof(pegasus_msgs__msg__DefectArray__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pegasus_msgs__msg__DefectArray__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pegasus_msgs__msg__DefectArray__Sequence__destroy(pegasus_msgs__msg__DefectArray__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pegasus_msgs__msg__DefectArray__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pegasus_msgs__msg__DefectArray__Sequence__are_equal(const pegasus_msgs__msg__DefectArray__Sequence * lhs, const pegasus_msgs__msg__DefectArray__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pegasus_msgs__msg__DefectArray__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pegasus_msgs__msg__DefectArray__Sequence__copy(
  const pegasus_msgs__msg__DefectArray__Sequence * input,
  pegasus_msgs__msg__DefectArray__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pegasus_msgs__msg__DefectArray);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pegasus_msgs__msg__DefectArray * data =
      (pegasus_msgs__msg__DefectArray *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pegasus_msgs__msg__DefectArray__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pegasus_msgs__msg__DefectArray__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pegasus_msgs__msg__DefectArray__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
