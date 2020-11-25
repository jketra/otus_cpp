cmake_minimum_required(VERSION 3.7)

project(IpFilterExample)

set(_sources main.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME} PRIVATE
	IpFilter
	StringAddOns
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ip_filter)

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} ip_filter)

if (DEPLOY_IP_FILTER)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
endif()
