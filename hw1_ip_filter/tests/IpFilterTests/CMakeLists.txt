cmake_minimum_required(VERSION 3.7)

project(IpFilterTests)

set(_sources IpFilterTests.cpp)
set(_headers IpV4Tests.h
			 IpStorageTests.h)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/test_data DESTINATION ${BINARIES_DIR})

add_executable(${PROJECT_NAME} ${_sources} ${_headers})

target_link_libraries(${PROJECT_NAME} PRIVATE
	GTest::GTest
	IpFilter
	StringAddOns
)

add_test(${PROJECT_NAME} ${PROJECT_NAME})

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} ${PROJECT_NAME})
