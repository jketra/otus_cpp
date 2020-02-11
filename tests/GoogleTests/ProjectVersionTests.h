#pragma once

#include "version.h"

#include <gtest/gtest.h>

namespace test
{
	
TEST(ProjectVersionTests, PatchNumber)
{
	EXPECT_TRUE(info::getProjectVersion() > 0);
}

}
