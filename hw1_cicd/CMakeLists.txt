cmake_minimum_required(VERSION 3.2)

set(PROJECT_HOME_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

configure_file(config.h.in "${CMAKE_BINARY_DIR}/hw1_cicd/config.h")

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)
