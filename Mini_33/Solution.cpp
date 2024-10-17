//
// Created by modnick on 11.09.2024.
//

#include "Solution.h"

int Solution::maxProfit(std::vector<int>& prices){
    int money = 0;
    for (int i = 1; i < prices.size(); ++i) {
        if (prices[i - 1] < prices[i]) money += (prices[i] - prices[i - 1]);
    }
    return money;
}
