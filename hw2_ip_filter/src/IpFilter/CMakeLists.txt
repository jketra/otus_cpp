cmake_minimum_required(VERSION 3.7)

project(IpFilter)

set(_sources IpV4.cpp
			 IpStorage.cpp
			 IpStoragePrinter.cpp)
set(_headers IpV4.h
			 IpStorage.h
			 IpStoragePrinter.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME}
	PUBLIC  OperationResult
	PRIVATE StringAddOns
	PRIVATE TypeTraits
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)

