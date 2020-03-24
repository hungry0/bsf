cmake_minimum_required (VERSION 3.12.0)
project(bsf_copy)

set(BSF_SOURCE_DIR ${PROJECT_SOURCE_DIR}/Source)
set(APP_ROOT_DIR ${PROJECT_SOURCE_DIR})
set (BS_IS_BANSHEE3D 0)

include(Source/CMake/Properties.cmake)

add_subdirectory(Source)

add_executable(test "main.cpp")