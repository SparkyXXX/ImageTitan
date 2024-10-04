// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from processed_remote:msg/ProcessedRemote.idl
// generated code does not contain a copyright notice

#ifndef PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__FUNCTIONS_H_
#define PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "processed_remote/msg/rosidl_generator_c__visibility_control.h"

#include "processed_remote/msg/detail/processed_remote__struct.h"

/// Initialize msg/ProcessedRemote message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * processed_remote__msg__ProcessedRemote
 * )) before or use
 * processed_remote__msg__ProcessedRemote__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__init(processed_remote__msg__ProcessedRemote * msg);

/// Finalize msg/ProcessedRemote message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
void
processed_remote__msg__ProcessedRemote__fini(processed_remote__msg__ProcessedRemote * msg);

/// Create msg/ProcessedRemote message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * processed_remote__msg__ProcessedRemote__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
processed_remote__msg__ProcessedRemote *
processed_remote__msg__ProcessedRemote__create();

/// Destroy msg/ProcessedRemote message.
/**
 * It calls
 * processed_remote__msg__ProcessedRemote__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
void
processed_remote__msg__ProcessedRemote__destroy(processed_remote__msg__ProcessedRemote * msg);

/// Check for msg/ProcessedRemote message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__are_equal(const processed_remote__msg__ProcessedRemote * lhs, const processed_remote__msg__ProcessedRemote * rhs);

/// Copy a msg/ProcessedRemote message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__copy(
  const processed_remote__msg__ProcessedRemote * input,
  processed_remote__msg__ProcessedRemote * output);

/// Initialize array of msg/ProcessedRemote messages.
/**
 * It allocates the memory for the number of elements and calls
 * processed_remote__msg__ProcessedRemote__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__Sequence__init(processed_remote__msg__ProcessedRemote__Sequence * array, size_t size);

/// Finalize array of msg/ProcessedRemote messages.
/**
 * It calls
 * processed_remote__msg__ProcessedRemote__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
void
processed_remote__msg__ProcessedRemote__Sequence__fini(processed_remote__msg__ProcessedRemote__Sequence * array);

/// Create array of msg/ProcessedRemote messages.
/**
 * It allocates the memory for the array and calls
 * processed_remote__msg__ProcessedRemote__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
processed_remote__msg__ProcessedRemote__Sequence *
processed_remote__msg__ProcessedRemote__Sequence__create(size_t size);

/// Destroy array of msg/ProcessedRemote messages.
/**
 * It calls
 * processed_remote__msg__ProcessedRemote__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
void
processed_remote__msg__ProcessedRemote__Sequence__destroy(processed_remote__msg__ProcessedRemote__Sequence * array);

/// Check for msg/ProcessedRemote message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__Sequence__are_equal(const processed_remote__msg__ProcessedRemote__Sequence * lhs, const processed_remote__msg__ProcessedRemote__Sequence * rhs);

/// Copy an array of msg/ProcessedRemote messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_processed_remote
bool
processed_remote__msg__ProcessedRemote__Sequence__copy(
  const processed_remote__msg__ProcessedRemote__Sequence * input,
  processed_remote__msg__ProcessedRemote__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PROCESSED_REMOTE__MSG__DETAIL__PROCESSED_REMOTE__FUNCTIONS_H_
