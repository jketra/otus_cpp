cmake_minimum_required(VERSION 3.7)

project(CicdBoostTests)

set(_sources ProjectVersionTests.cpp)

add_executable(${PROJECT_NAME} ${_sources})

set_target_properties(${PROJECT_NAME} PROPERTIES
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
)

target_link_libraries(${PROJECT_NAME}
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
    ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_HOME_DIRECTORY}/lib")

add_test(${PROJECT_NAME} ${PROJECT_NAME})
