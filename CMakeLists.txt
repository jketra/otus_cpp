cmake_minimum_required(VERSION 3.2)

if (WIN32)
	if (NOT CMAKE_TOOLCHAIN_FILE)
		set(CMAKE_TOOLCHAIN_FILE "C:/Tools/vcpkg/scripts/buildsystems/vcpkg.cmake")
	endif()
	set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
else()
	set(BIN_DIR bin)
endif()

include("${CMAKE_SOURCE_DIR}/CompilerOptions.cmake")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if ($ENV{TRAVIS_BUILD_NUMBER})
	project(CICD VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
	project(CICD VERSION 0.0.1)
endif()

configure_file(config.h.in "${CMAKE_BINARY_DIR}/config.h")

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
find_package(GTest REQUIRED)

enable_testing()

add_subdirectory(lib)
add_subdirectory(src)
add_subdirectory(tests)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT js@goloschapova.com)

include(CPack)
