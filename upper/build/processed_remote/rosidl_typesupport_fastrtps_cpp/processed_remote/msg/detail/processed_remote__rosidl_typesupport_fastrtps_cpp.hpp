// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__rosidl_typesupport_fastrtps_cpp.hpp.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#ifndef PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
#define PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_

#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_interface/macros.h"
#include "processed_remote/msg/rosidl_typesupport_fastrtps_cpp__visibility_control.h"
#include "processed_remote/msg/detail/processed_remote__struct.hpp"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

#include "fastcdr/Cdr.h"

namespace processed_remote
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_processed_remote
cdr_serialize(
  const processed_remote::msg::ProcessedRemote & ros_message,
  eprosima::fastcdr::Cdr & cdr);

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_processed_remote
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  processed_remote::msg::ProcessedRemote & ros_message);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_processed_remote
get_serialized_size(
  const processed_remote::msg::ProcessedRemote & ros_message,
  size_t current_alignment);

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_processed_remote
max_serialized_size_ProcessedRemote(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace processed_remote

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_processed_remote
const rosidl_message_type_support_t *
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, processed_remote, msg, ProcessedRemote)();

#ifdef __cplusplus
}
#endif

#endif  // PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__ROSIDL_TYPESUPPORT_FASTRTPS_CPP_HPP_
