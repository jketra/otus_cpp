cmake_minimum_required(VERSION 3.2)

project(RequiredOutputsModule)

set(_sources main.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	IpFilter
	StringAddOns
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ip_filter)

if (DEPLOY_IP_FILTER)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${BIN_DIR})
endif()
