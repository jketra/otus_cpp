cmake_minimum_required(VERSION 3.7)

project(IpFilterTests)

set(_sources IpFilterTests.cpp)
set(_headers IpV4Tests.h
			 IpStorageTests.h)

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	IpFilter
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})
