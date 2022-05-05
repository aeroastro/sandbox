cmake_minimum_required(VERSION 3.20)
project(Tutorial VERSION 0.1)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# For debugging
include(CMakePrintHelpers)

# CMake-generated file
configure_file(config.h.in config.h)

# building target console
add_executable(console console.cpp)
target_include_directories(console PUBLIC
                           "${PROJECT_BINARY_DIR}"
                           )

cmake_print_variables(PROJECT_BINARY_DIR PROJECT_SOURCE_DIR)
