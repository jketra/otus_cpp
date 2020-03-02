#pragma once

#include "IpFilter/IpV4.h"

#include <sstream>

#include <gtest/gtest.h>

namespace test
{

TEST(IpV4Tests, GetBytes)
{
	std::array<int, 4u> expValues{ 10, 11, 13, 15 };

	bl::IpV4 ip = bl::IpV4{ expValues[0], expValues[1], expValues[2], expValues[3] };

	EXPECT_EQ(ip.byte<1>(), expValues[0]);
	EXPECT_EQ(ip.byte<2>(), expValues[1]);
	EXPECT_EQ(ip.byte<3>(), expValues[2]);
	EXPECT_EQ(ip.byte<4>(), expValues[3]);
}

TEST(IpV4Tests, Comparison)
{
	bl::IpV4 lhs = bl::IpV4{ 10, 11, 13, 15 };
	bl::IpV4 rhs = bl::IpV4{ 12 };

	EXPECT_TRUE(lhs < rhs) << lhs << " < " << rhs;
	EXPECT_FALSE(rhs < lhs) << lhs << " < " << rhs;
	EXPECT_FALSE(!(lhs < rhs) && !(rhs < lhs)) << lhs << " == " << rhs;
	EXPECT_TRUE(!(lhs < lhs) && !(lhs < lhs)) << lhs << " == " << lhs;
}

TEST(IpV4Tests, Output)
{
	bl::IpV4 ip = bl::IpV4{ 10, 11, 13, 15 };
	
	std::stringstream actOutput;
	actOutput << ip;

	EXPECT_EQ(actOutput.str(), "10.11.13.15");
}

}
