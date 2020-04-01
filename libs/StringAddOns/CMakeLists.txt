cmake_minimum_required(VERSION 3.2)

project(StringAddOns)

set(_sources StringFunctions.cpp)
set(_headers StringFunctions.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)