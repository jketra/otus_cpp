cmake_minimum_required(VERSION 3.2)

project(ProjectInfo)

set(_sources version.cpp)
set(_headers version.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

# to include config.h
target_include_directories(${PROJECT_NAME}
	PRIVATE "${CMAKE_BINARY_DIR}/hw1_cicd"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)