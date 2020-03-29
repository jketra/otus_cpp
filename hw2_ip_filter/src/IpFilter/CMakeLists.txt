cmake_minimum_required(VERSION 3.2)

project(IpFilter)

set(_sources IpV4.cpp
			 IpStorage.cpp)
set(_headers IpV4.h
			 IpStorage.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	OperationResult
	StringAddOns
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)
