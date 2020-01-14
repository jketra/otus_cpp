cmake_minimum_required(VERSION 3.2)

project(BoostTests)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

add_executable(${PROJECT_NAME} ${sources} ${headers})

set_target_properties(${PROJECT_NAME} PROPERTIES
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
