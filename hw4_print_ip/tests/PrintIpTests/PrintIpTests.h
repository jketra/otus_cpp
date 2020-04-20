#pragma once

#include <PrintIp/PrintIp.h>

#include <sstream>
#include <vector>
#include <string>

#include <gtest/gtest.h>

namespace test {

class PrintIpTests : public ::testing::Test {
// protected for GTest
protected:

	std::stringstream _actOutput;
	std::stringstream _expOutput;
};

TEST_F(PrintIpTests, Zero) {
	
	hw4::printIp("42.42.42.42");

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

}
