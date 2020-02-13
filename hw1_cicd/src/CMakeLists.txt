cmake_minimum_required(VERSION 3.2)

project(HelloWorld)

set(_sources main.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME} PRIVATE
	ProjectInfo
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

target_include_directories(${PROJECT_NAME} PRIVATE "${PROJECT_HOME_DIRECTORY}/lib")

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME cicd)

if (DEPLOY_${CICD})
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${BIN_DIR})
endif()
