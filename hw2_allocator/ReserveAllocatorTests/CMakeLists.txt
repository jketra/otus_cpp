cmake_minimum_required(VERSION 3.7)

project(ReserveAllocatorTests)

set(_sources ReserveAllocatorTests.cpp)
set(_headers ListTests.h
             ReserveAllocatorTests.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
        GTest::GTest
        ReserveAllocator
        )

add_test(${PROJECT_NAME} ${PROJECT_NAME})

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} ${PROJECT_NAME})
