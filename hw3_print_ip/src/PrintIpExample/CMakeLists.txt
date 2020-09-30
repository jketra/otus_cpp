cmake_minimum_required(VERSION 3.7)

project(PrintIpExample)

set(_sources example.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME}
	PRIVATE PrintIp
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME print_ip)

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} print_ip)

if (DEPLOY_PRINT_IP)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
endif()

