﻿cmake_minimum_required(VERSION 3.7)

project(OperationResult)

set(_sources OperationResult.cpp)
set(_headers OperationResult.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
