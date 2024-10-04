// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#ifndef PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__BUILDER_HPP_
#define PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "processed_remote/msg/detail/processed_remote__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace processed_remote
{

namespace msg
{

namespace builder
{

class Init_ProcessedRemote_buttons
{
public:
  explicit Init_ProcessedRemote_buttons(::processed_remote::msg::ProcessedRemote & msg)
  : msg_(msg)
  {}
  ::processed_remote::msg::ProcessedRemote buttons(::processed_remote::msg::ProcessedRemote::_buttons_type arg)
  {
    msg_.buttons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::processed_remote::msg::ProcessedRemote msg_;
};

class Init_ProcessedRemote_axes
{
public:
  Init_ProcessedRemote_axes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ProcessedRemote_buttons axes(::processed_remote::msg::ProcessedRemote::_axes_type arg)
  {
    msg_.axes = std::move(arg);
    return Init_ProcessedRemote_buttons(msg_);
  }

private:
  ::processed_remote::msg::ProcessedRemote msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::processed_remote::msg::ProcessedRemote>()
{
  return processed_remote::msg::builder::Init_ProcessedRemote_axes();
}

}  // namespace processed_remote

#endif  // PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__BUILDER_HPP_
