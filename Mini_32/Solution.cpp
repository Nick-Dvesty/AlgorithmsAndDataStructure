//
// Created by modnick on 05.09.2024.
//

#include "Solution.h"

bool Solution::canJump(std::vector<int> &nums) {
    int elem = 0;
    while (true) {
        if (elem == nums.size() - 1) return true;
        if (nums [elem] == 0) return false;
        elem = indexJmp(nums, elem);
    }
}

 int Solution::indexJmp(std::vector<int> &nums, int& strIndex) {
    int ansIndex = 0, meaning = 0;
    for (int i = strIndex + 1; i <= strIndex + nums[strIndex] && i < nums.size(); ++i) {
        if (meaning < nums[i] + i) {
            ansIndex = i;
            meaning = nums[i] + i;
        }
    }
    return ansIndex;
}

Solution Solution::operator+(const Solution &solution) const {
    return {};
}


