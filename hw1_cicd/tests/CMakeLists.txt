cmake_minimum_required(VERSION 3.2)

if (TESTING_BOOST_TESTS)
	add_subdirectory(BoostTests)
endif()

if (TESTING_GTEST)
	add_subdirectory(GoogleTests)
endif()