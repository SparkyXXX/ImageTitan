// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#ifndef PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_H_
#define PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_H_

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

/// Struct defined in msg/ProcessedRemote in the package processed_remote.
typedef struct processed_remote__msg__ProcessedRemote
{
  rosidl_runtime_c__float__Sequence axes;
  rosidl_runtime_c__int32__Sequence buttons;
} processed_remote__msg__ProcessedRemote;

// Struct for a sequence of processed_remote__msg__ProcessedRemote.
typedef struct processed_remote__msg__ProcessedRemote__Sequence
{
  processed_remote__msg__ProcessedRemote * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} processed_remote__msg__ProcessedRemote__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_H_
