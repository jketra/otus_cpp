cmake_minimum_required(VERSION 3.7)

project(PrintIp)

set(_headers PrintIp.h Bits.h PrintBits.h)
set(_sources PrintIp.cpp)

add_library(${PROJECT_NAME} ${_headers} ${_sources})

target_link_libraries(${PROJECT_NAME}
	PUBLIC TypeTraits
)

target_include_directories(${PROJECT_NAME} INTERFACE ../src)
