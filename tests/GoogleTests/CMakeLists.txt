cmake_minimum_required(VERSION 3.2)

project(GoogleTests)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${sources} ${headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
