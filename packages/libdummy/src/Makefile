# Makefile for libdummy
# Supports both native compilation and Emscripten cross-compilation

# Compiler and tools
CC ?= gcc
AR ?= ar
RANLIB ?= ranlib

# Project configuration
LIBRARY_NAME = libdummy
VERSION = 1.0.0
STATIC_LIB = lib$(LIBRARY_NAME).a

# Directories
SRCDIR = .
OBJDIR = obj
LIBDIR = lib
INCDIR = .
TESTDIR = .

# Source files
SOURCES = libdummy.c
OBJECTS = $(SOURCES:%.c=$(OBJDIR)/%.o)
TEST_SOURCES = test_libdummy.c
TEST_OBJECTS = $(TEST_SOURCES:%.c=$(OBJDIR)/%.o)
TEST_EXECUTABLE = test_$(LIBRARY_NAME)

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -std=c99 -O2 -fPIC
CPPFLAGS = -I$(INCDIR) -DLIBDUMMY_VERSION_STRING=\"$(VERSION)\"
LDFLAGS = 
LIBS = 

# Installation directories
PREFIX ?= /usr/local
INSTALL_LIBDIR = $(PREFIX)/lib
INSTALL_INCDIR = $(PREFIX)/include

# Default target
.PHONY: all
all: $(LIBDIR)/$(STATIC_LIB)

# Create static library
$(LIBDIR)/$(STATIC_LIB): $(OBJECTS) | $(LIBDIR)
	$(AR) rcs $@ $^
	$(RANLIB) $@
	@echo "✓ Created static library: $@"

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "✓ Compiled: $<"

# Create directories
$(OBJDIR):
	mkdir -p $(OBJDIR)

$(LIBDIR):
	mkdir -p $(LIBDIR)

# Build test executable
.PHONY: test
test: $(TEST_EXECUTABLE)
	@echo "Running tests..."
	./$(TEST_EXECUTABLE)

$(TEST_EXECUTABLE): $(TEST_OBJECTS) $(LIBDIR)/$(STATIC_LIB)
	$(CC) $(LDFLAGS) $^ -o $@ $(LIBS)
	@echo "✓ Created test executable: $@"

# Install library and headers
.PHONY: install
install: $(LIBDIR)/$(STATIC_LIB)
	mkdir -p $(INSTALL_LIBDIR) $(INSTALL_INCDIR)
	cp $(LIBDIR)/$(STATIC_LIB) $(INSTALL_LIBDIR)/
	cp libdummy.h $(INSTALL_INCDIR)/
	@echo "✓ Installed to $(PREFIX)"

# Clean build artifacts
.PHONY: clean
clean:
	rm -rf $(OBJDIR) $(LIBDIR) $(TEST_EXECUTABLE)
	@echo "✓ Cleaned build artifacts"

# Display help
.PHONY: help
help:
	@echo "Available targets:"
	@echo "  all      - Build the static library (default)"
	@echo "  test     - Build and run tests"
	@echo "  install  - Install library and headers"
	@echo "  clean    - Remove build artifacts"
	@echo "  help     - Show this help message"
	@echo ""
	@echo "Variables:"
	@echo "  CC       - C compiler (default: gcc)"
	@echo "  AR       - Archiver (default: ar)"
	@echo "  PREFIX   - Installation prefix (default: /usr/local)"
	@echo "  CFLAGS   - Additional compiler flags"
	@echo ""
	@echo "For Emscripten build:"
	@echo "  emmake make"
	@echo "  emmake make install PREFIX=\$$(pwd)/install"

# Show configuration
.PHONY: config
config:
	@echo "Build Configuration:"
	@echo "  Library: $(LIBRARY_NAME) v$(VERSION)"
	@echo "  CC:      $(CC)"
	@echo "  AR:      $(AR)"
	@echo "  CFLAGS:  $(CFLAGS)"
	@echo "  PREFIX:  $(PREFIX)"

# Development targets
.PHONY: debug
debug: CFLAGS += -g -DDEBUG -O0
debug: all

.PHONY: release
release: CFLAGS += -O3 -DNDEBUG
release: all

# Check for required tools
.PHONY: check-tools
check-tools:
	@which $(CC) > /dev/null || (echo "Error: $(CC) not found" && exit 1)
	@which $(AR) > /dev/null || (echo "Error: $(AR) not found" && exit 1)
	@echo "✓ Required tools found"
