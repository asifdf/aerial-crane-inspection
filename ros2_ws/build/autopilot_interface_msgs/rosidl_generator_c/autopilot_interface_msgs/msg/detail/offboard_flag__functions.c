// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from autopilot_interface_msgs:msg/OffboardFlag.idl
// generated code does not contain a copyright notice
#include "autopilot_interface_msgs/msg/detail/offboard_flag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
autopilot_interface_msgs__msg__OffboardFlag__init(autopilot_interface_msgs__msg__OffboardFlag * msg)
{
  if (!msg) {
    return false;
  }
  // offboard_flag
  return true;
}

void
autopilot_interface_msgs__msg__OffboardFlag__fini(autopilot_interface_msgs__msg__OffboardFlag * msg)
{
  if (!msg) {
    return;
  }
  // offboard_flag
}

bool
autopilot_interface_msgs__msg__OffboardFlag__are_equal(const autopilot_interface_msgs__msg__OffboardFlag * lhs, const autopilot_interface_msgs__msg__OffboardFlag * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // offboard_flag
  if (lhs->offboard_flag != rhs->offboard_flag) {
    return false;
  }
  return true;
}

bool
autopilot_interface_msgs__msg__OffboardFlag__copy(
  const autopilot_interface_msgs__msg__OffboardFlag * input,
  autopilot_interface_msgs__msg__OffboardFlag * output)
{
  if (!input || !output) {
    return false;
  }
  // offboard_flag
  output->offboard_flag = input->offboard_flag;
  return true;
}

autopilot_interface_msgs__msg__OffboardFlag *
autopilot_interface_msgs__msg__OffboardFlag__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__msg__OffboardFlag * msg = (autopilot_interface_msgs__msg__OffboardFlag *)allocator.allocate(sizeof(autopilot_interface_msgs__msg__OffboardFlag), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(autopilot_interface_msgs__msg__OffboardFlag));
  bool success = autopilot_interface_msgs__msg__OffboardFlag__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
autopilot_interface_msgs__msg__OffboardFlag__destroy(autopilot_interface_msgs__msg__OffboardFlag * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    autopilot_interface_msgs__msg__OffboardFlag__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__init(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__msg__OffboardFlag * data = NULL;

  if (size) {
    data = (autopilot_interface_msgs__msg__OffboardFlag *)allocator.zero_allocate(size, sizeof(autopilot_interface_msgs__msg__OffboardFlag), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = autopilot_interface_msgs__msg__OffboardFlag__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        autopilot_interface_msgs__msg__OffboardFlag__fini(&data[i - 1]);
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
autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array)
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
      autopilot_interface_msgs__msg__OffboardFlag__fini(&array->data[i]);
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

autopilot_interface_msgs__msg__OffboardFlag__Sequence *
autopilot_interface_msgs__msg__OffboardFlag__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  autopilot_interface_msgs__msg__OffboardFlag__Sequence * array = (autopilot_interface_msgs__msg__OffboardFlag__Sequence *)allocator.allocate(sizeof(autopilot_interface_msgs__msg__OffboardFlag__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = autopilot_interface_msgs__msg__OffboardFlag__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
autopilot_interface_msgs__msg__OffboardFlag__Sequence__destroy(autopilot_interface_msgs__msg__OffboardFlag__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    autopilot_interface_msgs__msg__OffboardFlag__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__are_equal(const autopilot_interface_msgs__msg__OffboardFlag__Sequence * lhs, const autopilot_interface_msgs__msg__OffboardFlag__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!autopilot_interface_msgs__msg__OffboardFlag__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
autopilot_interface_msgs__msg__OffboardFlag__Sequence__copy(
  const autopilot_interface_msgs__msg__OffboardFlag__Sequence * input,
  autopilot_interface_msgs__msg__OffboardFlag__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(autopilot_interface_msgs__msg__OffboardFlag);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    autopilot_interface_msgs__msg__OffboardFlag * data =
      (autopilot_interface_msgs__msg__OffboardFlag *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!autopilot_interface_msgs__msg__OffboardFlag__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          autopilot_interface_msgs__msg__OffboardFlag__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!autopilot_interface_msgs__msg__OffboardFlag__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
