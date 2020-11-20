cmake_minimum_required(VERSION 3.7)

add_subdirectory(ReserveAllocator)
add_subdirectory(ReserveAllocatorExample)

if (TESTS_GTEST)
    add_subdirectory(ReserveAllocatorTests)
endif()
