#pragma once

#include "IpFilter/IpV4.h"

#include <sstream>

#include <gtest/gtest.h>

namespace test {

TEST(IpV4Tests, GetBytes) {
	std::array<hw2::IpV4::Byte, 4u> expValues{ 10, 11, 13, 15 };

	hw2::IpV4 ip = hw2::IpV4{ expValues[0], expValues[1], expValues[2], expValues[3] };

	for (size_t i = 0; i < hw2::IpV4::bytesNumber(); ++i) {
		EXPECT_EQ(ip.byte(i), expValues[i]);
	}
}

TEST(IpV4Tests, Comparison) {
	hw2::IpV4 lhs{ 10, 11, 13, 15 };
	hw2::IpV4 rhs{ 12 };

	EXPECT_TRUE(lhs < rhs) << lhs << " < " << rhs;
	EXPECT_FALSE(rhs < lhs) << lhs << " < " << rhs;
	EXPECT_FALSE(!(lhs < rhs) && !(rhs < lhs)) << lhs << " == " << rhs;
	EXPECT_TRUE(!(lhs < lhs) && !(lhs < lhs)) << lhs << " == " << lhs;

	lhs = hw2::IpV4{ 46, 70, 225, 39 };
	rhs = hw2::IpV4{ 46, 70, 147, 26 };
	EXPECT_TRUE(lhs > rhs) << lhs << " > " << rhs;
	EXPECT_TRUE(rhs < lhs) << lhs << " < " << rhs;
}

TEST(IpV4Tests, Output) {
	hw2::IpV4 ip = hw2::IpV4{ 10, 11, 13, 15 };
	
	std::stringstream actOutput;
	actOutput << ip;

	EXPECT_EQ(actOutput.str(), "10.11.13.15");
}

}
