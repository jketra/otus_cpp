#pragma once

#include "version.h"

#include <gtest/gtest.h>

/// Unit-tests
namespace test{

TEST(ProjectVersionTests, PatchNumber)
{
	EXPECT_TRUE(hw1::getProjectVersion() > 0);
}

}
