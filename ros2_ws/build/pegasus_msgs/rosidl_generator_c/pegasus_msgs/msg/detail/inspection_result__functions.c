// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pegasus_msgs:msg/InspectionResult.idl
// generated code does not contain a copyright notice
#include "pegasus_msgs/msg/detail/inspection_result__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `drone_id`
// Member `mission_id`
// Member `zone_id`
// Member `zone_risk_level`
// Member `json_payload`
#include "rosidl_runtime_c/string_functions.h"
// Member `drone_pose`
#include "geometry_msgs/msg/detail/pose_stamped__functions.h"
// Member `defects`
#include "pegasus_msgs/msg/detail/defect_array__functions.h"

bool
pegasus_msgs__msg__InspectionResult__init(pegasus_msgs__msg__InspectionResult * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // drone_id
  if (!rosidl_runtime_c__String__init(&msg->drone_id)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // mission_id
  if (!rosidl_runtime_c__String__init(&msg->mission_id)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__init(&msg->zone_id)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // drone_pose
  if (!geometry_msgs__msg__PoseStamped__init(&msg->drone_pose)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // defects
  if (!pegasus_msgs__msg__DefectArray__init(&msg->defects)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // coverage_percent
  // images_captured
  // images_with_defects
  // zone_risk_level
  if (!rosidl_runtime_c__String__init(&msg->zone_risk_level)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  // zone_risk_id
  // json_payload
  if (!rosidl_runtime_c__String__init(&msg->json_payload)) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
    return false;
  }
  return true;
}

void
pegasus_msgs__msg__InspectionResult__fini(pegasus_msgs__msg__InspectionResult * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // drone_id
  rosidl_runtime_c__String__fini(&msg->drone_id);
  // mission_id
  rosidl_runtime_c__String__fini(&msg->mission_id);
  // zone_id
  rosidl_runtime_c__String__fini(&msg->zone_id);
  // drone_pose
  geometry_msgs__msg__PoseStamped__fini(&msg->drone_pose);
  // defects
  pegasus_msgs__msg__DefectArray__fini(&msg->defects);
  // coverage_percent
  // images_captured
  // images_with_defects
  // zone_risk_level
  rosidl_runtime_c__String__fini(&msg->zone_risk_level);
  // zone_risk_id
  // json_payload
  rosidl_runtime_c__String__fini(&msg->json_payload);
}

bool
pegasus_msgs__msg__InspectionResult__are_equal(const pegasus_msgs__msg__InspectionResult * lhs, const pegasus_msgs__msg__InspectionResult * rhs)
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
  // mission_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->mission_id), &(rhs->mission_id)))
  {
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_id), &(rhs->zone_id)))
  {
    return false;
  }
  // drone_pose
  if (!geometry_msgs__msg__PoseStamped__are_equal(
      &(lhs->drone_pose), &(rhs->drone_pose)))
  {
    return false;
  }
  // defects
  if (!pegasus_msgs__msg__DefectArray__are_equal(
      &(lhs->defects), &(rhs->defects)))
  {
    return false;
  }
  // coverage_percent
  if (lhs->coverage_percent != rhs->coverage_percent) {
    return false;
  }
  // images_captured
  if (lhs->images_captured != rhs->images_captured) {
    return false;
  }
  // images_with_defects
  if (lhs->images_with_defects != rhs->images_with_defects) {
    return false;
  }
  // zone_risk_level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->zone_risk_level), &(rhs->zone_risk_level)))
  {
    return false;
  }
  // zone_risk_id
  if (lhs->zone_risk_id != rhs->zone_risk_id) {
    return false;
  }
  // json_payload
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->json_payload), &(rhs->json_payload)))
  {
    return false;
  }
  return true;
}

bool
pegasus_msgs__msg__InspectionResult__copy(
  const pegasus_msgs__msg__InspectionResult * input,
  pegasus_msgs__msg__InspectionResult * output)
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
  // mission_id
  if (!rosidl_runtime_c__String__copy(
      &(input->mission_id), &(output->mission_id)))
  {
    return false;
  }
  // zone_id
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_id), &(output->zone_id)))
  {
    return false;
  }
  // drone_pose
  if (!geometry_msgs__msg__PoseStamped__copy(
      &(input->drone_pose), &(output->drone_pose)))
  {
    return false;
  }
  // defects
  if (!pegasus_msgs__msg__DefectArray__copy(
      &(input->defects), &(output->defects)))
  {
    return false;
  }
  // coverage_percent
  output->coverage_percent = input->coverage_percent;
  // images_captured
  output->images_captured = input->images_captured;
  // images_with_defects
  output->images_with_defects = input->images_with_defects;
  // zone_risk_level
  if (!rosidl_runtime_c__String__copy(
      &(input->zone_risk_level), &(output->zone_risk_level)))
  {
    return false;
  }
  // zone_risk_id
  output->zone_risk_id = input->zone_risk_id;
  // json_payload
  if (!rosidl_runtime_c__String__copy(
      &(input->json_payload), &(output->json_payload)))
  {
    return false;
  }
  return true;
}

pegasus_msgs__msg__InspectionResult *
pegasus_msgs__msg__InspectionResult__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__InspectionResult * msg = (pegasus_msgs__msg__InspectionResult *)allocator.allocate(sizeof(pegasus_msgs__msg__InspectionResult), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pegasus_msgs__msg__InspectionResult));
  bool success = pegasus_msgs__msg__InspectionResult__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pegasus_msgs__msg__InspectionResult__destroy(pegasus_msgs__msg__InspectionResult * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pegasus_msgs__msg__InspectionResult__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pegasus_msgs__msg__InspectionResult__Sequence__init(pegasus_msgs__msg__InspectionResult__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__InspectionResult * data = NULL;

  if (size) {
    data = (pegasus_msgs__msg__InspectionResult *)allocator.zero_allocate(size, sizeof(pegasus_msgs__msg__InspectionResult), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pegasus_msgs__msg__InspectionResult__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pegasus_msgs__msg__InspectionResult__fini(&data[i - 1]);
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
pegasus_msgs__msg__InspectionResult__Sequence__fini(pegasus_msgs__msg__InspectionResult__Sequence * array)
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
      pegasus_msgs__msg__InspectionResult__fini(&array->data[i]);
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

pegasus_msgs__msg__InspectionResult__Sequence *
pegasus_msgs__msg__InspectionResult__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__InspectionResult__Sequence * array = (pegasus_msgs__msg__InspectionResult__Sequence *)allocator.allocate(sizeof(pegasus_msgs__msg__InspectionResult__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pegasus_msgs__msg__InspectionResult__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pegasus_msgs__msg__InspectionResult__Sequence__destroy(pegasus_msgs__msg__InspectionResult__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pegasus_msgs__msg__InspectionResult__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pegasus_msgs__msg__InspectionResult__Sequence__are_equal(const pegasus_msgs__msg__InspectionResult__Sequence * lhs, const pegasus_msgs__msg__InspectionResult__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pegasus_msgs__msg__InspectionResult__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pegasus_msgs__msg__InspectionResult__Sequence__copy(
  const pegasus_msgs__msg__InspectionResult__Sequence * input,
  pegasus_msgs__msg__InspectionResult__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pegasus_msgs__msg__InspectionResult);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pegasus_msgs__msg__InspectionResult * data =
      (pegasus_msgs__msg__InspectionResult *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pegasus_msgs__msg__InspectionResult__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pegasus_msgs__msg__InspectionResult__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pegasus_msgs__msg__InspectionResult__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
