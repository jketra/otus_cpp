cmake_minimum_required(VERSION 3.7)

if (TESTS_BOOST)
	add_subdirectory(BoostTests)
endif()

if (TESTS_GTEST)
	add_subdirectory(GoogleTests)
endif()
