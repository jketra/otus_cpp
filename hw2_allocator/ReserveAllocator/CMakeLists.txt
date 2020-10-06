cmake_minimum_required(VERSION 3.7)

project(ReserveAllocator)

set(_headers ReserveAllocator.h)

add_library(${PROJECT_NAME} INTERFACE)

add_custom_target(${PROJECT_NAME}_lib SOURCES ${_headers})
add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_lib)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
