cmake_minimum_required(VERSION 3.7)

project(IpFilter)

set(_sources
		Restrictions.cpp)
set(_headers
		Boundaries.h
		GenericIp.h
		IpFunctions.h
		IpStorage.h
		IpStoragePrinter.h
		IpV4.h
		Restrictions.h)

add_library(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME}
	PUBLIC  OperationResult
	PRIVATE StringAddOns
	PRIVATE TypeTraits
)

target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/..)
