cmake_minimum_required(VERSION 3.2)

project(GoogleTests)

set(sources GoogleTest.cpp)
set(headers ProjectVersionTests.h)

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
