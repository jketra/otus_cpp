#pragma once

#include <ReserveAllocator/ReserveAllocator.h>

#include <gtest/gtest.h>

namespace test {

class ReserveAllocatorTests : public ::testing::Test {

};

TEST_F(ReserveAllocatorTests, Create) {
    EXPECT_TRUE(true);
}

};
