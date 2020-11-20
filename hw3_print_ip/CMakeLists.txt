cmake_minimum_required(VERSION 3.7)

set(PROJECT_HOME_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(PrintIp)
add_subdirectory(PrintIpExample)

if (TESTS_GTEST)
    add_subdirectory(PrintIpTests)
endif()
