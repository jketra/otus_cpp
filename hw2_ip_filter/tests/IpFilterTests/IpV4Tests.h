#pragma once

#include "IpFilter/IpV4.h"

#include <sstream>

#include <gtest/gtest.h>

namespace test {

TEST(IpV4Tests, GetBytes) {
	std::array<bl::IpV4::Byte, 4u> expValues{ 10, 11, 13, 15 };

	bl::IpV4 ip = bl::IpV4{ expValues[0], expValues[1], expValues[2], expValues[3] };

	for (size_t i = 0; i < 4u; ++i) {
		EXPECT_EQ(ip.byte(i), expValues[i]);
	}
}

TEST(IpV4Tests, Comparison) {
	bl::IpV4 lhs{ 10, 11, 13, 15 };
	bl::IpV4 rhs{ 12 };

	EXPECT_TRUE(lhs < rhs) << lhs << " < " << rhs;
	EXPECT_FALSE(rhs < lhs) << lhs << " < " << rhs;
	EXPECT_FALSE(!(lhs < rhs) && !(rhs < lhs)) << lhs << " == " << rhs;
	EXPECT_TRUE(!(lhs < lhs) && !(lhs < lhs)) << lhs << " == " << lhs;

	lhs = bl::IpV4{ 46, 70, 225, 39 };
	rhs = bl::IpV4{ 46, 70, 147, 26 };
	EXPECT_TRUE(lhs > rhs) << lhs << " > " << rhs;
	EXPECT_TRUE(rhs < lhs) << lhs << " < " << rhs;
}

TEST(IpV4Tests, Output) {
	bl::IpV4 ip = bl::IpV4{ 10, 11, 13, 15 };
	
	std::stringstream actOutput;
	actOutput << ip;

	EXPECT_EQ(actOutput.str(), "10.11.13.15");
}

}
