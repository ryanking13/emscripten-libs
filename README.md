# Emscripten Static Libraries for Pyodide

This repository provides pre-built static libraries compiled with Emscripten for use with [Pyodide](https://pyodide.org/).
The goal is to simplify the integration of third-party C/C++ libraries into the Pyodide ecosystem by providing ready-to-use static library builds.

## 🎯 Purpose

Similar to [beeware/cpython-android-source-deps](https://github.com/beeware/cpython-android-source-deps) which prebuilds source dependencies for CPython Android builds,
this repository prebuilds static libraries that can be consumed by [pyodide/pyodide-recipes](https://github.com/pyodide/pyodide-recipes).

## 📁 Repository Structure

```
emscripten-libs/
├── .github/
│   └── workflows/
│       └── build-and-release.yml    # CI/CD pipeline
├── packages/                        # Package recipes
│   └── ...                         # Libraries here
├── tools/
│   └── build_and_release.py        # Main build and release script
├── build/                          # Build artifacts (generated)
├── dist/                           # Distribution packages (generated)
└── releases/                       # Release assets (generated)
```

## 🚀 Quick Start

### Adding a New Library

1. Create a new directory under `packages/` with your library name:
   ```bash
   mkdir packages/lib_my_library
   ```

There is no limit on the name of the library, but we recommand using the prefix `lib` followed by the library name.

2. Create a `meta.yaml` file with package metadata:
   ```yaml
   package:
     name: my_library
     version: 1.0.0

   source:
     url: https://github.com/example/my_library/archive/v1.0.0.tar.gz
     sha256: "your_sha256_hash_here"

   build:
     script: |
       # build script here
       emmake make ...
     type: static_library
   ```

### Building Libraries

#### Requirements

- Python 3.13+
- Up-to-date Emscripten
- pyodide-build
- Standard build tools (make, cmake, etc.)

```bash
# Install Python dependencies
pip install pyodide-build

# Install Emscripten SDK
git clone https://github.com/emscripten-core/emsdk.git
cd emsdk
./emsdk install latest
./emsdk activate latest
source ./emsdk_env.sh
```

#### Building

```bash
pyodide build-recipes libdummy
```

## 📋 Available Packages

- `libdummy` - Example/test package demonstrating the build system

## FAQ

- Why only static libraries?

Shared libraries need to be dynamically linked at runtime.
However, dynamic linking is not WASM standard, and Emscripten does not garantee the backward compatibility of the linking libraries.
Therefore, shared libraries need to be built with strictly same compiler flags and version of Emscripten used for Pyodide.

Meanwhile, static libraries can be built with any version of Emscripten (ideally), if the flags are properly set.
