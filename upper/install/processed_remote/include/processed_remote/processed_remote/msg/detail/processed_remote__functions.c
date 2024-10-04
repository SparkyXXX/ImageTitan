// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice
#include "processed_remote/msg/detail/processed_remote__functions.h"

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
processed_remote__msg__ProcessedRemote__init(processed_remote__msg__ProcessedRemote * msg)
{
  if (!msg) {
    return false;
  }
  // axes
  if (!rosidl_runtime_c__float__Sequence__init(&msg->axes, 0)) {
    processed_remote__msg__ProcessedRemote__fini(msg);
    return false;
  }
  // buttons
  if (!rosidl_runtime_c__int32__Sequence__init(&msg->buttons, 0)) {
    processed_remote__msg__ProcessedRemote__fini(msg);
    return false;
  }
  return true;
}

void
processed_remote__msg__ProcessedRemote__fini(processed_remote__msg__ProcessedRemote * msg)
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
processed_remote__msg__ProcessedRemote__are_equal(const processed_remote__msg__ProcessedRemote * lhs, const processed_remote__msg__ProcessedRemote * rhs)
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
processed_remote__msg__ProcessedRemote__copy(
  const processed_remote__msg__ProcessedRemote * input,
  processed_remote__msg__ProcessedRemote * output)
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

processed_remote__msg__ProcessedRemote *
processed_remote__msg__ProcessedRemote__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  processed_remote__msg__ProcessedRemote * msg = (processed_remote__msg__ProcessedRemote *)allocator.allocate(sizeof(processed_remote__msg__ProcessedRemote), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(processed_remote__msg__ProcessedRemote));
  bool success = processed_remote__msg__ProcessedRemote__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
processed_remote__msg__ProcessedRemote__destroy(processed_remote__msg__ProcessedRemote * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    processed_remote__msg__ProcessedRemote__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
processed_remote__msg__ProcessedRemote__Sequence__init(processed_remote__msg__ProcessedRemote__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  processed_remote__msg__ProcessedRemote * data = NULL;

  if (size) {
    data = (processed_remote__msg__ProcessedRemote *)allocator.zero_allocate(size, sizeof(processed_remote__msg__ProcessedRemote), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = processed_remote__msg__ProcessedRemote__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        processed_remote__msg__ProcessedRemote__fini(&data[i - 1]);
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
processed_remote__msg__ProcessedRemote__Sequence__fini(processed_remote__msg__ProcessedRemote__Sequence * array)
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
      processed_remote__msg__ProcessedRemote__fini(&array->data[i]);
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

processed_remote__msg__ProcessedRemote__Sequence *
processed_remote__msg__ProcessedRemote__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  processed_remote__msg__ProcessedRemote__Sequence * array = (processed_remote__msg__ProcessedRemote__Sequence *)allocator.allocate(sizeof(processed_remote__msg__ProcessedRemote__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = processed_remote__msg__ProcessedRemote__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
processed_remote__msg__ProcessedRemote__Sequence__destroy(processed_remote__msg__ProcessedRemote__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    processed_remote__msg__ProcessedRemote__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
processed_remote__msg__ProcessedRemote__Sequence__are_equal(const processed_remote__msg__ProcessedRemote__Sequence * lhs, const processed_remote__msg__ProcessedRemote__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!processed_remote__msg__ProcessedRemote__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
processed_remote__msg__ProcessedRemote__Sequence__copy(
  const processed_remote__msg__ProcessedRemote__Sequence * input,
  processed_remote__msg__ProcessedRemote__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(processed_remote__msg__ProcessedRemote);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    processed_remote__msg__ProcessedRemote * data =
      (processed_remote__msg__ProcessedRemote *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!processed_remote__msg__ProcessedRemote__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          processed_remote__msg__ProcessedRemote__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!processed_remote__msg__ProcessedRemote__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
