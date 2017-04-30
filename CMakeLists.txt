cmake_minimum_required(VERSION 3.7)
project(make-project)

set(PROJECT_NAME make-project)
set(CMAKE_CXX_STANDARD 14)

# The version number.
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)

configure_file(
        "include/version.h.in"
        "${PROJECT_BINARY_DIR}/version.h"
)

include_directories("${PROJECT_BINARY_DIR}")

set(SOURCE_FILES source/main.cpp)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})