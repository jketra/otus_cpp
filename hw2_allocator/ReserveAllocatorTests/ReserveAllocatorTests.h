#pragma once

#include <ReserveAllocator/ReserveAllocator.h>
#include <ReserveAllocator/ClassicAllocator.h>

#include <list>
#include <vector>

#include <gtest/gtest.h>

namespace test {

class ReserveAllocatorTests : public ::testing::Test {

};

TEST_F(ReserveAllocatorTests, SimpleStdList) {
    using namespace hw2;
    std::list<int, ClassicAllocator<int>> firstList;

    firstList.push_back(0);
    firstList.emplace_back(1);
    firstList.push_back(2);
    firstList.pop_back();

    EXPECT_EQ(firstList.back(), 1);

    auto secondList{ firstList };
    EXPECT_EQ(secondList.front(), 0);
    EXPECT_EQ(secondList.back(), 1);

    std::list<int, ClassicAllocator<int>> thirdList;
    thirdList.push_back(2);
    thirdList.push_back(3);

    std::swap(secondList, thirdList);
    EXPECT_EQ(secondList.front(), 2);
    EXPECT_EQ(secondList.back(), 3);
    EXPECT_EQ(thirdList.front(), 0);
    EXPECT_EQ(thirdList.back(), 1);
}

    TEST_F(ReserveAllocatorTests, Simple) {
        using namespace hw2;
        std::list<int, ReserveAllocator<int, 5>> firstList;

        firstList.push_back(100);
        firstList.emplace_back(200);
        firstList.push_back(300);
        //firstList.pop_back();

        //EXPECT_EQ(firstList.back(), 1);

        //auto secondList{ firstList };
        //EXPECT_EQ(secondList.front(), 0);
        //EXPECT_EQ(secondList.back(), 1);
//
        //std::list<int, ClassicAllocator<int>> thirdList;
        //thirdList.push_back(2);
        //thirdList.push_back(3);
//
        //std::swap(secondList, thirdList);
        //EXPECT_EQ(secondList.front(), 2);
        //EXPECT_EQ(secondList.back(), 3);
        //EXPECT_EQ(thirdList.front(), 0);
        //EXPECT_EQ(thirdList.back(), 1);
    }

}
