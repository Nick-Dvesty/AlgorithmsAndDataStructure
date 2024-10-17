#include <iostream>
#include <vector>
#include "Solution.h"
int main() {
    std::vector<int> vector = {2,0};
    Solution sol{};
    std::cout << sol.canJump(vector);
}
