// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from joy_msg:msg/JoystickData.idl
// generated code does not contain a copyright notice

#ifndef JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__BUILDER_HPP_
#define JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "joy_msg/msg/detail/joystick_data__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace joy_msg
{

namespace msg
{

namespace builder
{

class Init_JoystickData_buttons
{
public:
  explicit Init_JoystickData_buttons(::joy_msg::msg::JoystickData & msg)
  : msg_(msg)
  {}
  ::joy_msg::msg::JoystickData buttons(::joy_msg::msg::JoystickData::_buttons_type arg)
  {
    msg_.buttons = std::move(arg);
    return std::move(msg_);
  }

private:
  ::joy_msg::msg::JoystickData msg_;
};

class Init_JoystickData_axes
{
public:
  Init_JoystickData_axes()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_JoystickData_buttons axes(::joy_msg::msg::JoystickData::_axes_type arg)
  {
    msg_.axes = std::move(arg);
    return Init_JoystickData_buttons(msg_);
  }

private:
  ::joy_msg::msg::JoystickData msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::joy_msg::msg::JoystickData>()
{
  return joy_msg::msg::builder::Init_JoystickData_axes();
}

}  // namespace joy_msg

#endif  // JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__BUILDER_HPP_
