cmake_minimum_required(VERSION 3.7)

project(PrintIpTests)

set(_sources PrintIpTests.cpp)
set(_headers PrintIpTests.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	PrintIp
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} ${PROJECT_NAME})
