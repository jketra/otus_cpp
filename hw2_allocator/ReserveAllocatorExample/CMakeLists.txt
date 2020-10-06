cmake_minimum_required(VERSION 3.7)

project(ReserveAllocatorExample)

set(_sources main.cpp)

add_executable(${PROJECT_NAME} ${_sources})

target_link_libraries(${PROJECT_NAME}
	ReserveAllocator
)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME allocator)

post_build_copy_executable(${CMAKE_CURRENT_BINARY_DIR} ${PROJECT_NAME} allocator)

if (DEPLOY_ALLOCATOR)
	install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${INSTALL_DIR})
endif()
