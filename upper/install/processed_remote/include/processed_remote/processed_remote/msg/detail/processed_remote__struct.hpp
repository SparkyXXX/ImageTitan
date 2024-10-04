// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#ifndef PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_HPP_
#define PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__processed_remote__msg__ProcessedRemote __attribute__((deprecated))
#else
# define DEPRECATED__processed_remote__msg__ProcessedRemote __declspec(deprecated)
#endif

namespace processed_remote
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ProcessedRemote_
{
  using Type = ProcessedRemote_<ContainerAllocator>;

  explicit ProcessedRemote_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit ProcessedRemote_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _axes_type =
    std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>>;
  _axes_type axes;
  using _buttons_type =
    std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>>;
  _buttons_type buttons;

  // setters for named parameter idiom
  Type & set__axes(
    const std::vector<float, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<float>> & _arg)
  {
    this->axes = _arg;
    return *this;
  }
  Type & set__buttons(
    const std::vector<int32_t, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<int32_t>> & _arg)
  {
    this->buttons = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    processed_remote::msg::ProcessedRemote_<ContainerAllocator> *;
  using ConstRawPtr =
    const processed_remote::msg::ProcessedRemote_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      processed_remote::msg::ProcessedRemote_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      processed_remote::msg::ProcessedRemote_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__processed_remote__msg__ProcessedRemote
    std::shared_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__processed_remote__msg__ProcessedRemote
    std::shared_ptr<processed_remote::msg::ProcessedRemote_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ProcessedRemote_ & other) const
  {
    if (this->axes != other.axes) {
      return false;
    }
    if (this->buttons != other.buttons) {
      return false;
    }
    return true;
  }
  bool operator!=(const ProcessedRemote_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ProcessedRemote_

// alias to use template instance with default allocator
using ProcessedRemote =
  processed_remote::msg::ProcessedRemote_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace processed_remote

#endif  // PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__STRUCT_HPP_
