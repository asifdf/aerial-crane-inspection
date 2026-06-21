// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from pegasus_msgs:msg/DefectDetection.idl
// generated code does not contain a copyright notice
#include "pegasus_msgs/msg/detail/defect_detection__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `type`
// Member `risk_level`
#include "rosidl_runtime_c/string_functions.h"
// Member `mask`
#include "sensor_msgs/msg/detail/compressed_image__functions.h"
// Member `position_3d`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
pegasus_msgs__msg__DefectDetection__init(pegasus_msgs__msg__DefectDetection * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
    return false;
  }
  // type
  if (!rosidl_runtime_c__String__init(&msg->type)) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
    return false;
  }
  // class_id
  // confidence
  // bbox_x
  // bbox_y
  // bbox_width
  // bbox_height
  // bbox_x_norm
  // bbox_y_norm
  // bbox_width_norm
  // bbox_height_norm
  // risk_level
  if (!rosidl_runtime_c__String__init(&msg->risk_level)) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
    return false;
  }
  // risk_id
  // mask
  if (!sensor_msgs__msg__CompressedImage__init(&msg->mask)) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
    return false;
  }
  // position_3d
  if (!geometry_msgs__msg__Point__init(&msg->position_3d)) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
    return false;
  }
  // has_3d_position
  return true;
}

void
pegasus_msgs__msg__DefectDetection__fini(pegasus_msgs__msg__DefectDetection * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // type
  rosidl_runtime_c__String__fini(&msg->type);
  // class_id
  // confidence
  // bbox_x
  // bbox_y
  // bbox_width
  // bbox_height
  // bbox_x_norm
  // bbox_y_norm
  // bbox_width_norm
  // bbox_height_norm
  // risk_level
  rosidl_runtime_c__String__fini(&msg->risk_level);
  // risk_id
  // mask
  sensor_msgs__msg__CompressedImage__fini(&msg->mask);
  // position_3d
  geometry_msgs__msg__Point__fini(&msg->position_3d);
  // has_3d_position
}

bool
pegasus_msgs__msg__DefectDetection__are_equal(const pegasus_msgs__msg__DefectDetection * lhs, const pegasus_msgs__msg__DefectDetection * rhs)
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
  // type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->type), &(rhs->type)))
  {
    return false;
  }
  // class_id
  if (lhs->class_id != rhs->class_id) {
    return false;
  }
  // confidence
  if (lhs->confidence != rhs->confidence) {
    return false;
  }
  // bbox_x
  if (lhs->bbox_x != rhs->bbox_x) {
    return false;
  }
  // bbox_y
  if (lhs->bbox_y != rhs->bbox_y) {
    return false;
  }
  // bbox_width
  if (lhs->bbox_width != rhs->bbox_width) {
    return false;
  }
  // bbox_height
  if (lhs->bbox_height != rhs->bbox_height) {
    return false;
  }
  // bbox_x_norm
  if (lhs->bbox_x_norm != rhs->bbox_x_norm) {
    return false;
  }
  // bbox_y_norm
  if (lhs->bbox_y_norm != rhs->bbox_y_norm) {
    return false;
  }
  // bbox_width_norm
  if (lhs->bbox_width_norm != rhs->bbox_width_norm) {
    return false;
  }
  // bbox_height_norm
  if (lhs->bbox_height_norm != rhs->bbox_height_norm) {
    return false;
  }
  // risk_level
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->risk_level), &(rhs->risk_level)))
  {
    return false;
  }
  // risk_id
  if (lhs->risk_id != rhs->risk_id) {
    return false;
  }
  // mask
  if (!sensor_msgs__msg__CompressedImage__are_equal(
      &(lhs->mask), &(rhs->mask)))
  {
    return false;
  }
  // position_3d
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->position_3d), &(rhs->position_3d)))
  {
    return false;
  }
  // has_3d_position
  if (lhs->has_3d_position != rhs->has_3d_position) {
    return false;
  }
  return true;
}

bool
pegasus_msgs__msg__DefectDetection__copy(
  const pegasus_msgs__msg__DefectDetection * input,
  pegasus_msgs__msg__DefectDetection * output)
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
  // type
  if (!rosidl_runtime_c__String__copy(
      &(input->type), &(output->type)))
  {
    return false;
  }
  // class_id
  output->class_id = input->class_id;
  // confidence
  output->confidence = input->confidence;
  // bbox_x
  output->bbox_x = input->bbox_x;
  // bbox_y
  output->bbox_y = input->bbox_y;
  // bbox_width
  output->bbox_width = input->bbox_width;
  // bbox_height
  output->bbox_height = input->bbox_height;
  // bbox_x_norm
  output->bbox_x_norm = input->bbox_x_norm;
  // bbox_y_norm
  output->bbox_y_norm = input->bbox_y_norm;
  // bbox_width_norm
  output->bbox_width_norm = input->bbox_width_norm;
  // bbox_height_norm
  output->bbox_height_norm = input->bbox_height_norm;
  // risk_level
  if (!rosidl_runtime_c__String__copy(
      &(input->risk_level), &(output->risk_level)))
  {
    return false;
  }
  // risk_id
  output->risk_id = input->risk_id;
  // mask
  if (!sensor_msgs__msg__CompressedImage__copy(
      &(input->mask), &(output->mask)))
  {
    return false;
  }
  // position_3d
  if (!geometry_msgs__msg__Point__copy(
      &(input->position_3d), &(output->position_3d)))
  {
    return false;
  }
  // has_3d_position
  output->has_3d_position = input->has_3d_position;
  return true;
}

pegasus_msgs__msg__DefectDetection *
pegasus_msgs__msg__DefectDetection__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectDetection * msg = (pegasus_msgs__msg__DefectDetection *)allocator.allocate(sizeof(pegasus_msgs__msg__DefectDetection), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(pegasus_msgs__msg__DefectDetection));
  bool success = pegasus_msgs__msg__DefectDetection__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
pegasus_msgs__msg__DefectDetection__destroy(pegasus_msgs__msg__DefectDetection * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    pegasus_msgs__msg__DefectDetection__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
pegasus_msgs__msg__DefectDetection__Sequence__init(pegasus_msgs__msg__DefectDetection__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectDetection * data = NULL;

  if (size) {
    data = (pegasus_msgs__msg__DefectDetection *)allocator.zero_allocate(size, sizeof(pegasus_msgs__msg__DefectDetection), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = pegasus_msgs__msg__DefectDetection__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        pegasus_msgs__msg__DefectDetection__fini(&data[i - 1]);
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
pegasus_msgs__msg__DefectDetection__Sequence__fini(pegasus_msgs__msg__DefectDetection__Sequence * array)
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
      pegasus_msgs__msg__DefectDetection__fini(&array->data[i]);
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

pegasus_msgs__msg__DefectDetection__Sequence *
pegasus_msgs__msg__DefectDetection__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  pegasus_msgs__msg__DefectDetection__Sequence * array = (pegasus_msgs__msg__DefectDetection__Sequence *)allocator.allocate(sizeof(pegasus_msgs__msg__DefectDetection__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = pegasus_msgs__msg__DefectDetection__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
pegasus_msgs__msg__DefectDetection__Sequence__destroy(pegasus_msgs__msg__DefectDetection__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    pegasus_msgs__msg__DefectDetection__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
pegasus_msgs__msg__DefectDetection__Sequence__are_equal(const pegasus_msgs__msg__DefectDetection__Sequence * lhs, const pegasus_msgs__msg__DefectDetection__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!pegasus_msgs__msg__DefectDetection__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
pegasus_msgs__msg__DefectDetection__Sequence__copy(
  const pegasus_msgs__msg__DefectDetection__Sequence * input,
  pegasus_msgs__msg__DefectDetection__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(pegasus_msgs__msg__DefectDetection);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    pegasus_msgs__msg__DefectDetection * data =
      (pegasus_msgs__msg__DefectDetection *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!pegasus_msgs__msg__DefectDetection__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          pegasus_msgs__msg__DefectDetection__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!pegasus_msgs__msg__DefectDetection__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
