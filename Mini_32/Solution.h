//
// Created by modnick on 05.09.2024.
//

#ifndef MINI_32_SOLUTION_H
#define MINI_32_SOLUTION_H
#include <vector>
class Solution;
class Solution{
private:
    int     indexJmp(std::vector<int>& nums, int& strIndex);
public:
    bool    canJump(std::vector<int>& nums);
    Solution operator + (const Solution& solution) const;
};
#endif //MINI_32_SOLUTION_H
