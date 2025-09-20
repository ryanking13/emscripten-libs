/**
 * @file libdummy.c
 * @brief Implementation of the dummy C library
 * @version 1.0.0
 * @date 2025
 */

#include "libdummy.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Internal state */
static int g_initialized = 0;

const char* libdummy_get_version(void) {
    return LIBDUMMY_VERSION_STRING;
}

libdummy_error_t libdummy_init(void) {
    if (g_initialized) {
        return LIBDUMMY_SUCCESS; /* Already initialized */
    }
    
    g_initialized = 1;
    printf("libdummy v%s initialized\n", LIBDUMMY_VERSION_STRING);
    return LIBDUMMY_SUCCESS;
}

void libdummy_cleanup(void) {
    if (g_initialized) {
        g_initialized = 0;
        printf("libdummy cleaned up\n");
    }
}

/* Basic mathematical operations */

int libdummy_add(int a, int b) {
    return a + b;
}

int libdummy_subtract(int a, int b) {
    return a - b;
}

int libdummy_multiply(int a, int b) {
    return a * b;
}

libdummy_error_t libdummy_divide(int a, int b, int* result) {
    if (result == NULL) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    if (b == 0) {
        return LIBDUMMY_ERROR_DIVISION_BY_ZERO;
    }
    
    *result = a / b;
    return LIBDUMMY_SUCCESS;
}

libdummy_error_t libdummy_factorial(int n, long long* result) {
    if (result == NULL) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    if (n < 0) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    *result = 1;
    for (int i = 2; i <= n; i++) {
        *result *= i;
    }
    
    return LIBDUMMY_SUCCESS;
}

/* String utilities */

size_t libdummy_strlen(const char* str) {
    if (str == NULL) {
        return 0;
    }
    
    size_t len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

libdummy_error_t libdummy_strcpy(char* dest, const char* src, size_t dest_size) {
    if (dest == NULL || src == NULL || dest_size == 0) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    size_t src_len = libdummy_strlen(src);
    if (src_len >= dest_size) {
        return LIBDUMMY_ERROR_BUFFER_TOO_SMALL;
    }
    
    for (size_t i = 0; i <= src_len; i++) {
        dest[i] = src[i];
    }
    
    return LIBDUMMY_SUCCESS;
}

libdummy_error_t libdummy_toupper(char* str, size_t len) {
    if (str == NULL) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    for (size_t i = 0; i < len && str[i] != '\0'; i++) {
        str[i] = (char)toupper((unsigned char)str[i]);
    }
    
    return LIBDUMMY_SUCCESS;
}

/* Array utilities */

libdummy_error_t libdummy_array_sum(const int* arr, size_t size, long long* result) {
    if (arr == NULL || result == NULL) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    *result = 0;
    for (size_t i = 0; i < size; i++) {
        *result += arr[i];
    }
    
    return LIBDUMMY_SUCCESS;
}

libdummy_error_t libdummy_array_max(const int* arr, size_t size, int* result) {
    if (arr == NULL || result == NULL || size == 0) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    *result = arr[0];
    for (size_t i = 1; i < size; i++) {
        if (arr[i] > *result) {
            *result = arr[i];
        }
    }
    
    return LIBDUMMY_SUCCESS;
}

libdummy_error_t libdummy_array_sort(int* arr, size_t size) {
    if (arr == NULL) {
        return LIBDUMMY_ERROR_INVALID_PARAM;
    }
    
    /* Bubble sort implementation */
    for (size_t i = 0; i < size - 1; i++) {
        for (size_t j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                /* Swap elements */
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    return LIBDUMMY_SUCCESS;
}
