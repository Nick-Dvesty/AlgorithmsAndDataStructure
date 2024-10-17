#include <iostream>
#include <gtest/gtest.h>

#include "Solution.h"

TEST(TrageTest, OneArr) {
    std::vector data{1};
    ASSERT_EQ(Solution::maxProfit(data), 0);
}

TEST(TrageTest, increasingyArr) {
    std::vector data{1,2,3,4,5,6,7,8};
    ASSERT_EQ(Solution::maxProfit(data), 7);
}

TEST(TrageTest, decreasingArr) {
    std::vector data{8,7,6,5,4,3,2,1};
    ASSERT_EQ(Solution::maxProfit(data), 0);
}

TEST(TrageTest, MixedArr) {
    std::vector data{1,2,3,2,1};
    ASSERT_EQ(Solution::maxProfit(data), 2);
}
