// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from joy_msg:msg/JoystickData.idl
// generated code does not contain a copyright notice

#ifndef JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__TRAITS_HPP_
#define JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "joy_msg/msg/detail/joystick_data__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace joy_msg
{

namespace msg
{

inline void to_flow_style_yaml(
  const JoystickData & msg,
  std::ostream & out)
{
  out << "{";
  // member: axes
  {
    if (msg.axes.size() == 0) {
      out << "axes: []";
    } else {
      out << "axes: [";
      size_t pending_items = msg.axes.size();
      for (auto item : msg.axes) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: buttons
  {
    if (msg.buttons.size() == 0) {
      out << "buttons: []";
    } else {
      out << "buttons: [";
      size_t pending_items = msg.buttons.size();
      for (auto item : msg.buttons) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const JoystickData & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: axes
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.axes.size() == 0) {
      out << "axes: []\n";
    } else {
      out << "axes:\n";
      for (auto item : msg.axes) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: buttons
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.buttons.size() == 0) {
      out << "buttons: []\n";
    } else {
      out << "buttons:\n";
      for (auto item : msg.buttons) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const JoystickData & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace joy_msg

namespace rosidl_generator_traits
{

[[deprecated("use joy_msg::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const joy_msg::msg::JoystickData & msg,
  std::ostream & out, size_t indentation = 0)
{
  joy_msg::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use joy_msg::msg::to_yaml() instead")]]
inline std::string to_yaml(const joy_msg::msg::JoystickData & msg)
{
  return joy_msg::msg::to_yaml(msg);
}

template<>
inline const char * data_type<joy_msg::msg::JoystickData>()
{
  return "joy_msg::msg::JoystickData";
}

template<>
inline const char * name<joy_msg::msg::JoystickData>()
{
  return "joy_msg/msg/JoystickData";
}

template<>
struct has_fixed_size<joy_msg::msg::JoystickData>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<joy_msg::msg::JoystickData>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<joy_msg::msg::JoystickData>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // JOY_MSG__MSG__DETAIL__JOYSTICK_DATA__TRAITS_HPP_
