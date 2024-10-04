// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from joy_msg:msg/JoystickData.idl
// generated code does not contain a copyright notice
#include "joy_msg/msg/detail/joystick_data__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `axes`
// Member `buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
joy_msg__msg__JoystickData__init(joy_msg__msg__JoystickData * msg)
{
  if (!msg) {
    return false;
  }
  // axes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->axes, 0)) {
    joy_msg__msg__JoystickData__fini(msg);
    return false;
  }
  // buttons
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->buttons, 0)) {
    joy_msg__msg__JoystickData__fini(msg);
    return false;
  }
  return true;
}

void
joy_msg__msg__JoystickData__fini(joy_msg__msg__JoystickData * msg)
{
  if (!msg) {
    return;
  }
  // axes
  rosidl_runtime_c__float__Sequence__fini(&msg->axes);
  // buttons
  rosidl_runtime_c__int32__Sequence__fini(&msg->buttons);
}

bool
joy_msg__msg__JoystickData__are_equal(const joy_msg__msg__JoystickData * lhs, const joy_msg__msg__JoystickData * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // axes
  if (!rosidl_runtime_c__float__Sequence__are_equal(
      &(lhs->axes), &(rhs->axes)))
  {
    return false;
  }
  // buttons
  if (!rosidl_runtime_c__int32__Sequence__are_equal(
      &(lhs->buttons), &(rhs->buttons)))
  {
    return false;
  }
  return true;
}

bool
joy_msg__msg__JoystickData__copy(
  const joy_msg__msg__JoystickData * input,
  joy_msg__msg__JoystickData * output)
{
  if (!input || !output) {
    return false;
  }
  // axes
  if (!rosidl_runtime_c__float__Sequence__copy(
      &(input->axes), &(output->axes)))
  {
    return false;
  }
  // buttons
  if (!rosidl_runtime_c__int32__Sequence__copy(
      &(input->buttons), &(output->buttons)))
  {
    return false;
  }
  return true;
}

joy_msg__msg__JoystickData *
joy_msg__msg__JoystickData__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_msg__msg__JoystickData * msg = (joy_msg__msg__JoystickData *)allocator.allocate(sizeof(joy_msg__msg__JoystickData), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(joy_msg__msg__JoystickData));
  bool success = joy_msg__msg__JoystickData__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
joy_msg__msg__JoystickData__destroy(joy_msg__msg__JoystickData * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    joy_msg__msg__JoystickData__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
joy_msg__msg__JoystickData__Sequence__init(joy_msg__msg__JoystickData__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_msg__msg__JoystickData * data = NULL;

  if (size) {
    data = (joy_msg__msg__JoystickData *)allocator.zero_allocate(size, sizeof(joy_msg__msg__JoystickData), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = joy_msg__msg__JoystickData__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        joy_msg__msg__JoystickData__fini(&data[i - 1]);
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
joy_msg__msg__JoystickData__Sequence__fini(joy_msg__msg__JoystickData__Sequence * array)
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
      joy_msg__msg__JoystickData__fini(&array->data[i]);
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

joy_msg__msg__JoystickData__Sequence *
joy_msg__msg__JoystickData__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  joy_msg__msg__JoystickData__Sequence * array = (joy_msg__msg__JoystickData__Sequence *)allocator.allocate(sizeof(joy_msg__msg__JoystickData__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = joy_msg__msg__JoystickData__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
joy_msg__msg__JoystickData__Sequence__destroy(joy_msg__msg__JoystickData__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    joy_msg__msg__JoystickData__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
joy_msg__msg__JoystickData__Sequence__are_equal(const joy_msg__msg__JoystickData__Sequence * lhs, const joy_msg__msg__JoystickData__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!joy_msg__msg__JoystickData__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
joy_msg__msg__JoystickData__Sequence__copy(
  const joy_msg__msg__JoystickData__Sequence * input,
  joy_msg__msg__JoystickData__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(joy_msg__msg__JoystickData);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    joy_msg__msg__JoystickData * data =
      (joy_msg__msg__JoystickData *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!joy_msg__msg__JoystickData__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          joy_msg__msg__JoystickData__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!joy_msg__msg__JoystickData__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
