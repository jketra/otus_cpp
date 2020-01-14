#pragma once

#include <gtest/gtest.h>

#include "version.h"

namespace test
{
	
TEST(ProjectVersionTests, PatchNumber)
{
	EXPECT_TRUE(info::getProjectVersion() > 0);
}

}
