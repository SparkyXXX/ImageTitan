// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "processed_remote/msg/detail/processed_remote__rosidl_typesupport_introspection_c.h"
#include "processed_remote/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "processed_remote/msg/detail/processed_remote__functions.h"
#include "processed_remote/msg/detail/processed_remote__struct.h"


// Include directives for member types
// Member `axes`
// Member `buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  processed_remote__msg__ProcessedRemote__init(message_memory);
}

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_fini_function(void * message_memory)
{
  processed_remote__msg__ProcessedRemote__fini(message_memory);
}

size_t processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__size_function__ProcessedRemote__axes(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__axes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__axes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__fetch_function__ProcessedRemote__axes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__axes(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__assign_function__ProcessedRemote__axes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__axes(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__resize_function__ProcessedRemote__axes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__size_function__ProcessedRemote__buttons(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__buttons(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__buttons(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__fetch_function__ProcessedRemote__buttons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__buttons(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__assign_function__ProcessedRemote__buttons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__buttons(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__resize_function__ProcessedRemote__buttons(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_member_array[2] = {
  {
    "axes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(processed_remote__msg__ProcessedRemote, axes),  // bytes offset in struct
    NULL,  // default value
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__size_function__ProcessedRemote__axes,  // size() function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__axes,  // get_const(index) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__axes,  // get(index) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__fetch_function__ProcessedRemote__axes,  // fetch(index, &value) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__assign_function__ProcessedRemote__axes,  // assign(index, value) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__resize_function__ProcessedRemote__axes  // resize(index) function pointer
  },
  {
    "buttons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(processed_remote__msg__ProcessedRemote, buttons),  // bytes offset in struct
    NULL,  // default value
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__size_function__ProcessedRemote__buttons,  // size() function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_const_function__ProcessedRemote__buttons,  // get_const(index) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__get_function__ProcessedRemote__buttons,  // get(index) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__fetch_function__ProcessedRemote__buttons,  // fetch(index, &value) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__assign_function__ProcessedRemote__buttons,  // assign(index, value) function pointer
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__resize_function__ProcessedRemote__buttons  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_members = {
  "processed_remote__msg",  // message namespace
  "ProcessedRemote",  // message name
  2,  // number of fields
  sizeof(processed_remote__msg__ProcessedRemote),
  processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_member_array,  // message members
  processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_init_function,  // function to initialize message memory (memory has to be allocated)
  processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_type_support_handle = {
  0,
  &processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_processed_remote
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, processed_remote, msg, ProcessedRemote)() {
  if (!processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_type_support_handle.typesupport_identifier) {
    processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &processed_remote__msg__ProcessedRemote__rosidl_typesupport_introspection_c__ProcessedRemote_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
