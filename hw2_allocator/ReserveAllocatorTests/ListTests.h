#pragma once

#include <ReserveAllocator/List.h>
#include <ReserveAllocator/ReserveAllocator.h>

#include <gtest/gtest.h>
#include <ReserveAllocator/ReserveAllocator.h>

namespace test {

class ListTests : public testing::Test {

};

TEST_F(ListTests, StdAllocator) {
   using namespace hw2;

    List<int> list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    for (auto it = list.begin(); it != list.end(); it = it->next) {
           std::cout << it->value << " ";
    }
    std::cout << std::endl;

    EXPECT_TRUE(true);
}

TEST_F(ListTests, CustomAllocator) {
    using namespace hw2;

    List<int, ReserveAllocator<int>> list;

    list.push_front(3);
    list.push_front(2);
    list.push_front(1);

    for (auto it = list.begin(); it != list.end(); it = it->next) {
        std::cout << it->value << " ";
    }
    std::cout << std::endl;

    EXPECT_TRUE(true);
}

}
