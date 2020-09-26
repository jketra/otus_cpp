cmake_minimum_required(VERSION 3.7)

project(HelloWorld)

set(_sources main.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME} PRIVATE
	ProjectInfo
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_HOME_DIRECTORY}/lib")

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME cicd)

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} cicd)

if (DEPLOY_${CICD})
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
endif()
