cmake_minimum_required(VERSION 3.2)

set(PROJECT_HOME_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(src)

if (TESTING_GTEST)
	add_subdirectory(tests)
endif()
