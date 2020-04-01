cmake_minimum_required(VERSION 3.7)

project(StringAddOns)

set(_sources StringFunctions.cpp)
set(_headers StringFunctions.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
