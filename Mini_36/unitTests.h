//
// Created by modnick on 03.10.2024.
//
#ifndef MINI_36_TESTS_H
#define MINI_36_TESTS_H

#include<utility>
#include<vector>

#include"gtest/gtest.h"
#include "sheduleFine.h"

template<typename T> using Vector = std::vector<T>;
template<typename T, typename T2> using Pair = std::pair<T, T2>;

TEST(test1, basename){
    Vector<Pair<int, int>>arr{5};
    arr[0] = Pair<int, int>(25, 2);
    arr[1] = Pair<int, int>(30, 0);
    arr[2] = Pair<int, int>(50, 2);
    arr[3] = Pair<int, int>(10, 3);
    arr[4] = Pair<int, int>(15, 2);
    ASSERT_EQ(g_scheduleFine(arr), 15);

}

TEST(test2, basename){
    Vector<Pair<int, int>>arr{7};
    arr[0] = Pair<int, int>(0, 5);
    arr[1] = Pair<int, int>(2005, 4);
    arr[2] = Pair<int, int>(23126, 3);
    arr[3] = Pair<int, int>(1997, 3);
    arr[4] = Pair<int, int>(420, 2);
    arr[5] = Pair<int, int>(69, 1);
    arr[6] = Pair<int, int>(42, 0);
    ASSERT_EQ(g_scheduleFine(arr), 42);
}

TEST(test3, basename){
    Vector<Pair<int, int>>arr{0};
    ASSERT_EQ(g_scheduleFine(arr), 0);
}

#endif //MINI_36_TESTS_H
