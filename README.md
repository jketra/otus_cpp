# OTUS c++ homeworks

OTUS_CPP is a set of small projects for practice after the theoretical lessons of the course.

## Table of Contents
- [Dependencies](#dependencies)
- [Building](#building)
- [Installing dependencies](#installing-dependencies)

<a name="dependencies"></a>
## Dependencies
`OTUS_CPP` depends on:

* C++14 compatible compiler (GCC 4.9+, MSVC 19.0+ (Visual Studio 2015+))
* CMake (3.0.2+, build only)
* GTest (optional, for tests)
* Boost tests (optional, for part of the tests of the frist homework)

<a name="building"></a>
## Building

In general, you need to install all `OTUS_CPP` [dependencies](#dependencies) as described in [Installing dependencies](#installing-dependencies).
Then enter directory containing `OTUS_CPP` sources and compile them using CMake:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

<a name="installing-dependencies"></a>
### Installing dependencies

<a name="windows"></a>
#### Windows
* Download and install Microsoft Visual Studio 2015 or later.
* Install [vcpkg](https://github.com/Microsoft/vcpkg#quick-start).
* Run the following commands to install `OTUS_CPP` dependencies using vcpkg:
```
cd <path to vcpkg>
.\vcpkg.exe install gtest:x64-windows gtest:x86-windows
```
* Download and install [CMake](https://cmake.org/download/); choose "Add CMake to the system PATH" option while installing.
* Build `OTUS_CPP` with CMake as explained in [building](#building), but instead of `cmake -DCMAKE_BUILD_TYPE=Release ..` use
```
cmake -DCMAKE_TOOLCHAIN_FILE=<path to vcpkg>/scripts/buildsystems/vcpkg.cmake ..
```

To build 32-bit/64-bit `OTUS_CPP` using MSVC, you will need to additionally specify parameter `-A Win32`/`-A x64` to CMake.
To build `OTUS_CPP` in Release mode using MSVC, you will need to additionally specify parameter `--config Release` to the `cmake --build .` command.

<a name="linux"></a>
#### Linux
* Install all [dependencies](#dependencies) using your package manager.
