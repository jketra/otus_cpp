cmake_minimum_required(VERSION 3.2)

project(BoostTests)

set(sources ProjectVersionTests.cpp)

add_executable(${PROJECT_NAME} ${sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_SOURCE_DIR}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
