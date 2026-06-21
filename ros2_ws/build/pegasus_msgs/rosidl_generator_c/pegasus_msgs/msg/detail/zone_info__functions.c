// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pegasus_msgs:msg/ZoneInfo.idl
// generated code does not contain a copyright notice
#include "pegasus_msgs/msg/detail/zone_info__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `zone_id`
// Member `zone_name`
// Member `zone_type`
// Member `expected_defects`
#include "rosidl_runtime_c/string_functions.h"
// Member `zone_center`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `zone_dimensions`
#include "geometry_msgs/msg/detail/vector3__functions.h"
// Member `waypoints_x`
// Member `waypoints_y`
// Member `waypoints_z`
// Member `waypoints_yaw`
// Member `camera_pitch`
// Member `camera_yaw`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
pegasus_msgs__msg__ZoneInfo__init(pegasus_msgs__msg__ZoneInfo * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__init(&msg->zone_id)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // zone_name
  if (!rosidl_runtime_c__String__init(&msg->zone_name)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // zone_type
  if (!rosidl_runtime_c__String__init(&msg->zone_type)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // zone_center
  if (!geometry_msgs__msg__Pose__init(&msg->zone_center)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // zone_dimensions
  if (!geometry_msgs__msg__Vector3__init(&msg->zone_dimensions)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // waypoints_x
  if (!rosidl_runtime_c__float__Sequence__init(&msg->waypoints_x, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // waypoints_y
  if (!rosidl_runtime_c__float__Sequence__init(&msg->waypoints_y, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // waypoints_z
  if (!rosidl_runtime_c__float__Sequence__init(&msg->waypoints_z, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // waypoints_yaw
  if (!rosidl_runtime_c__float__Sequence__init(&msg->waypoints_yaw, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // camera_pitch
  if (!rosidl_runtime_c__float__Sequence__init(&msg->camera_pitch, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // camera_yaw
  if (!rosidl_runtime_c__float__Sequence__init(&msg->camera_yaw, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // expected_defects
  if (!rosidl_runtime_c__String__Sequence__init(&msg->expected_defects, 0)) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
    return false;
  }
  // priority
  return true;
}

void
pegasus_msgs__msg__ZoneInfo__fini(pegasus_msgs__msg__ZoneInfo * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // zone_id
  rosidl_runtime_c__String__fini(&msg->zone_id);
  // zone_name
  rosidl_runtime_c__String__fini(&msg->zone_name);
  // zone_type
  rosidl_runtime_c__String__fini(&msg->zone_type);
  // zone_center
  geometry_msgs__msg__Pose__fini(&msg->zone_center);
  // zone_dimensions
  geometry_msgs__msg__Vector3__fini(&msg->zone_dimensions);
  // waypoints_x
  rosidl_runtime_c__float__Sequence__fini(&msg->waypoints_x);
  // waypoints_y
  rosidl_runtime_c__float__Sequence__fini(&msg->waypoints_y);
  // waypoints_z
  rosidl_runtime_c__float__Sequence__fini(&msg->waypoints_z);
  // waypoints_yaw
  rosidl_runtime_c__float__Sequence__fini(&msg->waypoints_yaw);
  // camera_pitch
  rosidl_runtime_c__float__Sequence__fini(&msg->camera_pitch);
  // camera_yaw
  rosidl_runtime_c__float__Sequence__fini(&msg->camera_yaw);
  // expected_defects
  rosidl_runtime_c__String__Sequence__fini(&msg->expected_defects);
  // priority
}

bool
pegasus_msgs__msg__ZoneInfo__are_equal(const pegasus_msgs__msg__ZoneInfo * lhs, const pegasus_msgs__msg__ZoneInfo * rhs)
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
  // zone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_id), &(rhs->zone_id)))
  {
    return false;
  }
  // zone_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_name), &(rhs->zone_name)))
  {
    return false;
  }
  // zone_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_type), &(rhs->zone_type)))
  {
    return false;
  }
  // zone_center
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->zone_center), &(rhs->zone_center)))
  {
    return false;
  }
  // zone_dimensions
  if (!geometry_msgs__msg__Vector3__are_equal(
      &(lhs->zone_dimensions), &(rhs->zone_dimensions)))
  {
    return false;
  }
  // waypoints_x
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->waypoints_x), &(rhs->waypoints_x)))
  {
    return false;
  }
  // waypoints_y
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->waypoints_y), &(rhs->waypoints_y)))
  {
    return false;
  }
  // waypoints_z
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->waypoints_z), &(rhs->waypoints_z)))
  {
    return false;
  }
  // waypoints_yaw
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->waypoints_yaw), &(rhs->waypoints_yaw)))
  {
    return false;
  }
  // camera_pitch
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->camera_pitch), &(rhs->camera_pitch)))
  {
    return false;
  }
  // camera_yaw
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->camera_yaw), &(rhs->camera_yaw)))
  {
    return false;
  }
  // expected_defects
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->expected_defects), &(rhs->expected_defects)))
  {
    return false;
  }
  // priority
  if (lhs->priority != rhs->priority) {
    return false;
  }
  return true;
}

bool
pegasus_msgs__msg__ZoneInfo__copy(
  const pegasus_msgs__msg__ZoneInfo * input,
  pegasus_msgs__msg__ZoneInfo * output)
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
  // zone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_id), &(output->zone_id)))
  {
    return false;
  }
  // zone_name
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_name), &(output->zone_name)))
  {
    return false;
  }
  // zone_type
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_type), &(output->zone_type)))
  {
    return false;
  }
  // zone_center
  if (!geometry_msgs__msg__Pose__copy(
      &(input->zone_center), &(output->zone_center)))
  {
    return false;
  }
  // zone_dimensions
  if (!geometry_msgs__msg__Vector3__copy(
      &(input->zone_dimensions), &(output->zone_dimensions)))
  {
    return false;
  }
  // waypoints_x
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->waypoints_x), &(output->waypoints_x)))
  {
    return false;
  }
  // waypoints_y
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->waypoints_y), &(output->waypoints_y)))
  {
    return false;
  }
  // waypoints_z
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->waypoints_z), &(output->waypoints_z)))
  {
    return false;
  }
  // waypoints_yaw
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->waypoints_yaw), &(output->waypoints_yaw)))
  {
    return false;
  }
  // camera_pitch
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->camera_pitch), &(output->camera_pitch)))
  {
    return false;
  }
  // camera_yaw
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->camera_yaw), &(output->camera_yaw)))
  {
    return false;
  }
  // expected_defects
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->expected_defects), &(output->expected_defects)))
  {
    return false;
  }
  // priority
  output->priority = input->priority;
  return true;
}

pegasus_msgs__msg__ZoneInfo *
pegasus_msgs__msg__ZoneInfo__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__ZoneInfo * msg = (pegasus_msgs__msg__ZoneInfo *)allocator.allocate(sizeof(pegasus_msgs__msg__ZoneInfo), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pegasus_msgs__msg__ZoneInfo));
  bool success = pegasus_msgs__msg__ZoneInfo__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pegasus_msgs__msg__ZoneInfo__destroy(pegasus_msgs__msg__ZoneInfo * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pegasus_msgs__msg__ZoneInfo__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pegasus_msgs__msg__ZoneInfo__Sequence__init(pegasus_msgs__msg__ZoneInfo__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__ZoneInfo * data = NULL;

  if (size) {
    data = (pegasus_msgs__msg__ZoneInfo *)allocator.zero_allocate(size, sizeof(pegasus_msgs__msg__ZoneInfo), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pegasus_msgs__msg__ZoneInfo__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pegasus_msgs__msg__ZoneInfo__fini(&data[i - 1]);
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
pegasus_msgs__msg__ZoneInfo__Sequence__fini(pegasus_msgs__msg__ZoneInfo__Sequence * array)
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
      pegasus_msgs__msg__ZoneInfo__fini(&array->data[i]);
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

pegasus_msgs__msg__ZoneInfo__Sequence *
pegasus_msgs__msg__ZoneInfo__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__ZoneInfo__Sequence * array = (pegasus_msgs__msg__ZoneInfo__Sequence *)allocator.allocate(sizeof(pegasus_msgs__msg__ZoneInfo__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pegasus_msgs__msg__ZoneInfo__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pegasus_msgs__msg__ZoneInfo__Sequence__destroy(pegasus_msgs__msg__ZoneInfo__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pegasus_msgs__msg__ZoneInfo__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pegasus_msgs__msg__ZoneInfo__Sequence__are_equal(const pegasus_msgs__msg__ZoneInfo__Sequence * lhs, const pegasus_msgs__msg__ZoneInfo__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pegasus_msgs__msg__ZoneInfo__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pegasus_msgs__msg__ZoneInfo__Sequence__copy(
  const pegasus_msgs__msg__ZoneInfo__Sequence * input,
  pegasus_msgs__msg__ZoneInfo__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pegasus_msgs__msg__ZoneInfo);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pegasus_msgs__msg__ZoneInfo * data =
      (pegasus_msgs__msg__ZoneInfo *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pegasus_msgs__msg__ZoneInfo__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pegasus_msgs__msg__ZoneInfo__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pegasus_msgs__msg__ZoneInfo__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
