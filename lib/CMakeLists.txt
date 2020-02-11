project(ProjectInfo)

set(sources version.cpp)
set(headers version.h)

add_library(${PROJECT_NAME} ${sources} ${headers})

# to include config.h
target_include_directories(${PROJECT_NAME}
    PRIVATE "${CMAKE_BINARY_DIR}"
)

set_target_properties(${PROJECT_NAME} PROPERTIES
	CXX_STANDARD 14
	CXX_STANDARD_REQUIRED ON
)