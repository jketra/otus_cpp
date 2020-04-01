cmake_minimum_required(VERSION 3.7)

project(GoogleTests)

set(_sources GoogleTest.cpp)
set(_headers ProjectVersionTests.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_HOME_DIRECTORY}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
