/**
 * @file libdummy.h
 * @brief A dummy C library for testing Emscripten builds
 * @version 1.0.0
 * @date 2025
 * 
 * This header file defines the public API for libdummy, a simple library
 * that provides basic mathematical operations and utility functions for
 * testing static library builds with Emscripten.
 */

#ifndef LIBDUMMY_H
#define LIBDUMMY_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h>
#include <stdint.h>

/* Version information */
#define LIBDUMMY_VERSION_MAJOR 1
#define LIBDUMMY_VERSION_MINOR 0
#define LIBDUMMY_VERSION_PATCH 0
#define LIBDUMMY_VERSION_STRING "1.0.0"

/* Error codes */
typedef enum {
    LIBDUMMY_SUCCESS = 0,
    LIBDUMMY_ERROR_INVALID_PARAM = -1,
    LIBDUMMY_ERROR_DIVISION_BY_ZERO = -2,
    LIBDUMMY_ERROR_BUFFER_TOO_SMALL = -3
} libdummy_error_t;

/**
 * @brief Get the library version string
 * @return Pointer to version string
 */
const char* libdummy_get_version(void);

/**
 * @brief Initialize the library
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_init(void);

/**
 * @brief Cleanup library resources
 */
void libdummy_cleanup(void);

/* Basic mathematical operations */

/**
 * @brief Add two integers
 * @param a First operand
 * @param b Second operand
 * @return Sum of a and b
 */
int libdummy_add(int a, int b);

/**
 * @brief Subtract two integers
 * @param a First operand
 * @param b Second operand
 * @return Difference (a - b)
 */
int libdummy_subtract(int a, int b);

/**
 * @brief Multiply two integers
 * @param a First operand
 * @param b Second operand
 * @return Product of a and b
 */
int libdummy_multiply(int a, int b);

/**
 * @brief Divide two integers with error checking
 * @param a Dividend
 * @param b Divisor
 * @param result Pointer to store the result
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_divide(int a, int b, int* result);

/**
 * @brief Calculate factorial of a number
 * @param n Input number (must be >= 0)
 * @param result Pointer to store the factorial result
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_factorial(int n, long long* result);

/* String utilities */

/**
 * @brief Get the length of a string
 * @param str Input string
 * @return Length of the string, or 0 if str is NULL
 */
size_t libdummy_strlen(const char* str);

/**
 * @brief Copy a string to a buffer
 * @param dest Destination buffer
 * @param src Source string
 * @param dest_size Size of destination buffer
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_strcpy(char* dest, const char* src, size_t dest_size);

/**
 * @brief Convert string to uppercase
 * @param str String to convert (modified in-place)
 * @param len Maximum length to process
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_toupper(char* str, size_t len);

/* Array utilities */

/**
 * @brief Find the sum of an integer array
 * @param arr Input array
 * @param size Number of elements in the array
 * @param result Pointer to store the sum
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_array_sum(const int* arr, size_t size, long long* result);

/**
 * @brief Find the maximum value in an integer array
 * @param arr Input array
 * @param size Number of elements in the array
 * @param result Pointer to store the maximum value
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_array_max(const int* arr, size_t size, int* result);

/**
 * @brief Sort an integer array in ascending order (bubble sort)
 * @param arr Array to sort (modified in-place)
 * @param size Number of elements in the array
 * @return LIBDUMMY_SUCCESS on success, error code otherwise
 */
libdummy_error_t libdummy_array_sort(int* arr, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* LIBDUMMY_H */
