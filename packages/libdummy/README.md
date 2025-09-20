# libdummy

A simple C library for testing the Emscripten static library build system. This package demonstrates how to create a proper static library that can be built with Emscripten and consumed by Pyodide packages.

## Features

libdummy provides the following functionality:

### Mathematical Operations
- Basic arithmetic (add, subtract, multiply, divide)
- Factorial calculation
- Error handling for edge cases (division by zero, invalid parameters)

### String Utilities
- String length calculation
- Safe string copying
- String case conversion

### Array Operations
- Array sum calculation
- Finding maximum value
- Simple sorting (bubble sort)

## API Reference

### Initialization
```c
#include "libdummy.h"

// Initialize the library
libdummy_error_t result = libdummy_init();

// Use library functions...

// Cleanup when done
libdummy_cleanup();
```

### Basic Math
```c
int sum = libdummy_add(5, 3);        // Returns 8
int diff = libdummy_subtract(10, 4); // Returns 6
int product = libdummy_multiply(6, 7); // Returns 42

int quotient;
libdummy_error_t err = libdummy_divide(15, 3, &quotient);
if (err == LIBDUMMY_SUCCESS) {
    // quotient is now 5
}
```

### String Operations
```c
size_t len = libdummy_strlen("hello"); // Returns 5

char buffer[20];
libdummy_error_t err = libdummy_strcpy(buffer, "test", sizeof(buffer));

char text[] = "hello";
libdummy_toupper(text, sizeof(text)); // text is now "HELLO"
```

### Array Operations
```c
int numbers[] = {5, 2, 8, 1, 9};
size_t count = 5;

long long sum;
libdummy_array_sum(numbers, count, &sum); // sum is 25

int max_value;
libdummy_array_max(numbers, count, &max_value); // max_value is 9

libdummy_array_sort(numbers, count); // numbers is now {1, 2, 5, 8, 9}
```

## Building

### Native Build
```bash
cd src/
make all
make test
```

### Emscripten Build
```bash
cd src/
emmake make all
emmake make install PREFIX=/path/to/install
```

### Build System Integration
This package is designed to work with the automated build system:

```bash
# From repository root
python tools/build_and_release.py --library dummy_library --dry-run
```

## File Structure

```
packages/dummy_library/
├── LICENSE              # MIT license
├── README.md           # This file
├── meta.yaml           # Package metadata
├── build.py            # Build script for Emscripten
└── src/
    ├── Makefile        # Build configuration
    ├── libdummy.h      # Public API header
    ├── libdummy.c      # Implementation
    └── test_libdummy.c # Test program
```

## Error Handling

libdummy uses a consistent error handling approach:

```c
typedef enum {
    LIBDUMMY_SUCCESS = 0,
    LIBDUMMY_ERROR_INVALID_PARAM = -1,
    LIBDUMMY_ERROR_DIVISION_BY_ZERO = -2,
    LIBDUMMY_ERROR_BUFFER_TOO_SMALL = -3
} libdummy_error_t;
```

Always check return values for functions that return `libdummy_error_t`.

## Version Information

```c
const char* version = libdummy_get_version(); // Returns "1.0.0"
```

## License

MIT License - see LICENSE file for details.

## Contributing

This is a test library for the build system. To add new functionality:

1. Add function declarations to `libdummy.h`
2. Implement functions in `libdummy.c`
3. Add tests to `test_libdummy.c`
4. Update this README

## Notes for Pyodide Integration

When consumed by Pyodide packages, this library provides:
- Static library file: `lib/libdummy.a`
- Header file: `include/libdummy.h`
- MIT license compatibility
- Emscripten-compiled WebAssembly compatibility
