// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from joy_msg:msg/JoystickData.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "joy_msg/msg/detail/joystick_data__rosidl_typesupport_introspection_c.h"
#include "joy_msg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "joy_msg/msg/detail/joystick_data__functions.h"
#include "joy_msg/msg/detail/joystick_data__struct.h"


// Include directives for member types
// Member `axes`
// Member `buttons`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  joy_msg__msg__JoystickData__init(message_memory);
}

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_fini_function(void * message_memory)
{
  joy_msg__msg__JoystickData__fini(message_memory);
}

size_t joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__size_function__JoystickData__axes(
  const void * untyped_member)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return member->size;
}

const void * joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__axes(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__float__Sequence * member =
    (const rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void * joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__axes(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  return &member->data[index];
}

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__fetch_function__JoystickData__axes(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const float * item =
    ((const float *)
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__axes(untyped_member, index));
  float * value =
    (float *)(untyped_value);
  *value = *item;
}

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__assign_function__JoystickData__axes(
  void * untyped_member, size_t index, const void * untyped_value)
{
  float * item =
    ((float *)
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__axes(untyped_member, index));
  const float * value =
    (const float *)(untyped_value);
  *item = *value;
}

bool joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__resize_function__JoystickData__axes(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__float__Sequence * member =
    (rosidl_runtime_c__float__Sequence *)(untyped_member);
  rosidl_runtime_c__float__Sequence__fini(member);
  return rosidl_runtime_c__float__Sequence__init(member, size);
}

size_t joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__size_function__JoystickData__buttons(
  const void * untyped_member)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return member->size;
}

const void * joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__buttons(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__int32__Sequence * member =
    (const rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void * joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__buttons(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  return &member->data[index];
}

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__fetch_function__JoystickData__buttons(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const int32_t * item =
    ((const int32_t *)
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__buttons(untyped_member, index));
  int32_t * value =
    (int32_t *)(untyped_value);
  *value = *item;
}

void joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__assign_function__JoystickData__buttons(
  void * untyped_member, size_t index, const void * untyped_value)
{
  int32_t * item =
    ((int32_t *)
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__buttons(untyped_member, index));
  const int32_t * value =
    (const int32_t *)(untyped_value);
  *item = *value;
}

bool joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__resize_function__JoystickData__buttons(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__int32__Sequence * member =
    (rosidl_runtime_c__int32__Sequence *)(untyped_member);
  rosidl_runtime_c__int32__Sequence__fini(member);
  return rosidl_runtime_c__int32__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_member_array[2] = {
  {
    "axes",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_FLOAT,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_msg__msg__JoystickData, axes),  // bytes offset in struct
    NULL,  // default value
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__size_function__JoystickData__axes,  // size() function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__axes,  // get_const(index) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__axes,  // get(index) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__fetch_function__JoystickData__axes,  // fetch(index, &value) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__assign_function__JoystickData__axes,  // assign(index, value) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__resize_function__JoystickData__axes  // resize(index) function pointer
  },
  {
    "buttons",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(joy_msg__msg__JoystickData, buttons),  // bytes offset in struct
    NULL,  // default value
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__size_function__JoystickData__buttons,  // size() function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_const_function__JoystickData__buttons,  // get_const(index) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__get_function__JoystickData__buttons,  // get(index) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__fetch_function__JoystickData__buttons,  // fetch(index, &value) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__assign_function__JoystickData__buttons,  // assign(index, value) function pointer
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__resize_function__JoystickData__buttons  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_members = {
  "joy_msg__msg",  // message namespace
  "JoystickData",  // message name
  2,  // number of fields
  sizeof(joy_msg__msg__JoystickData),
  joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_member_array,  // message members
  joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_init_function,  // function to initialize message memory (memory has to be allocated)
  joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_type_support_handle = {
  0,
  &joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_joy_msg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, joy_msg, msg, JoystickData)() {
  if (!joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_type_support_handle.typesupport_identifier) {
    joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &joy_msg__msg__JoystickData__rosidl_typesupport_introspection_c__JoystickData_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
