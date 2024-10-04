// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from joy_msg:msg/JoystickData.idl
// generated code does not contain a copyright notice

#ifndef JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__STRUCT_H_
#define JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'axes'
// Member 'buttons'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in msg/JoystickData in the package joy_msg.
typedef struct joy_msg__msg__JoystickData
{
  rosidl_runtime_c__float__Sequence axes;
  rosidl_runtime_c__int32__Sequence buttons;
} joy_msg__msg__JoystickData;

// Struct for a sequence of joy_msg__msg__JoystickData.
typedef struct joy_msg__msg__JoystickData__Sequence
{
  joy_msg__msg__JoystickData * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} joy_msg__msg__JoystickData__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__STRUCT_H_
