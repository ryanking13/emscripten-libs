/**
 * @file test_libdummy.c
 * @brief Test program for libdummy
 */

#include "libdummy.h"
#include <stdio.h>
#include <assert.h>
#include <string.h>

int main(void) {
    printf("Testing libdummy v%s\n", libdummy_get_version());
    
    /* Initialize library */
    assert(libdummy_init() == LIBDUMMY_SUCCESS);
    
    /* Test basic math operations */
    printf("\n=== Testing Basic Math Operations ===\n");
    assert(libdummy_add(5, 3) == 8);
    assert(libdummy_subtract(10, 4) == 6);
    assert(libdummy_multiply(6, 7) == 42);
    printf("✓ Basic math operations passed\n");
    
    /* Test division */
    int div_result;
    assert(libdummy_divide(15, 3, &div_result) == LIBDUMMY_SUCCESS);
    assert(div_result == 5);
    assert(libdummy_divide(10, 0, &div_result) == LIBDUMMY_ERROR_DIVISION_BY_ZERO);
    printf("✓ Division tests passed\n");
    
    /* Test factorial */
    long long fact_result;
    assert(libdummy_factorial(5, &fact_result) == LIBDUMMY_SUCCESS);
    assert(fact_result == 120);
    assert(libdummy_factorial(-1, &fact_result) == LIBDUMMY_ERROR_INVALID_PARAM);
    printf("✓ Factorial tests passed\n");
    
    /* Test string operations */
    printf("\n=== Testing String Operations ===\n");
    assert(libdummy_strlen("hello") == 5);
    assert(libdummy_strlen("") == 0);
    assert(libdummy_strlen(NULL) == 0);
    
    char buffer[20];
    assert(libdummy_strcpy(buffer, "test", sizeof(buffer)) == LIBDUMMY_SUCCESS);
    assert(strcmp(buffer, "test") == 0);
    
    char upper_test[] = "hello world";
    assert(libdummy_toupper(upper_test, sizeof(upper_test)) == LIBDUMMY_SUCCESS);
    assert(strcmp(upper_test, "HELLO WORLD") == 0);
    printf("✓ String operations passed\n");
    
    /* Test array operations */
    printf("\n=== Testing Array Operations ===\n");
    int test_array[] = {5, 2, 8, 1, 9};
    size_t array_size = sizeof(test_array) / sizeof(test_array[0]);
    
    long long sum;
    assert(libdummy_array_sum(test_array, array_size, &sum) == LIBDUMMY_SUCCESS);
    assert(sum == 25);
    
    int max_val;
    assert(libdummy_array_max(test_array, array_size, &max_val) == LIBDUMMY_SUCCESS);
    assert(max_val == 9);
    
    /* Test sorting */
    int sort_array[] = {5, 2, 8, 1, 9};
    assert(libdummy_array_sort(sort_array, 5) == LIBDUMMY_SUCCESS);
    int expected[] = {1, 2, 5, 8, 9};
    for (size_t i = 0; i < 5; i++) {
        assert(sort_array[i] == expected[i]);
    }
    printf("✓ Array operations passed\n");
    
    /* Cleanup */
    libdummy_cleanup();
    
    printf("\n🎉 All tests passed! libdummy is working correctly.\n");
    return 0;
}
