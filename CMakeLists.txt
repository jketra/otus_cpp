cmake_minimum_required(VERSION 3.2)

if (WIN32)
	set(BIN_DIR ${CMAKE_BINARY_DIR}/bin)
else()
	set(BIN_DIR bin)
endif()

set(CMAKE_MODULES_DIR "${CMAKE_SOURCE_DIR}/cmakeModules")
include("${CMAKE_MODULES_DIR}/CompilerOptions.cmake")
if (NOT ${CMAKE_VERSION} VERSION_LESS 3.7)
	include("${CMAKE_MODULES_DIR}/Functions.cmake")
endif()

# subprojects names
#
set(CICD "CICD")
set(IP_FILTER "IP_FILTER")

# options
#
option(BUILD_${CICD} "Build Homework 1" ON)
option(BUILD_${IP_FILTER} "Build Homework 2" ON)

option(TESTING_GTEST "Build Google Tests" ON)
option(TESTING_BOOST_TESTS "Build Boost Tests" OFF)

# pre deploy
#
include("${CMAKE_MODULES_DIR}/PreDeploy.cmake")

# project
#
if ($ENV{TRAVIS_BUILD_NUMBER})
	project(OTUS_CPP VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
	project(OTUS_CPP VERSION 0.0.1)
endif()

# tests
#
if (TESTING_BOOST_TESTS)
	find_package(Boost COMPONENTS unit_test_framework REQUIRED)
endif()
if (TESTING_GTEST)
	find_package(GTest REQUIRED)
endif()
enable_testing()

# directories
#
if (BUILD_${CICD})
	add_subdirectory(hw1_cicd)
endif()

if (BUILD_${IP_FILTER})
	add_subdirectory(hw2_ip_filter)
endif()

# folder filter for IDE
#
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
if (NOT ${CMAKE_VERSION} VERSION_LESS 3.7)
	apply_folder_filter("OTUS_CPP" ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# package
#
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT js@goloschapova.com)

include(CPack)
