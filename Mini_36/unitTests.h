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


TEST(Luba1, test){
    Vector<Pair<int, int>>arr{5};
    arr[0] = Pair<int, int>(5, 0);
    arr[1] = Pair<int, int>(4, 0);
    arr[2] = Pair<int, int>(3, 0);
    arr[3] = Pair<int, int>(2, 0);
    arr[4] = Pair<int, int>(1, 0);
    ASSERT_EQ(g_scheduleFine(arr), 10);

}

TEST(rost1, test){
    Vector<Pair<int, int>>arr {
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1,11),
    Pair<int, int>(1, 11)};
    ASSERT_EQ(g_scheduleFine(arr), 0);

}

TEST(rost2, test){
    Vector<Pair<int, int>>arr {
            Pair<int, int>(1,11),
            Pair<int, int>(11,1),
            Pair<int, int>(11,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1,1),
            Pair<int, int>(1, 1)};
    ASSERT_EQ(g_scheduleFine(arr), 9);

}
TEST(rost3, test){
    Vector<Pair<int, int>>arr {
            Pair<int, int>(12,0),
            Pair<int, int>(12,1),
            Pair<int, int>(12,2),
            Pair<int, int>(12,3),
            Pair<int, int>(12,4),
            Pair<int, int>(12,5),
            Pair<int, int>(12,6),
            Pair<int, int>(11,8),
            Pair<int, int>(12,8),
            Pair<int, int>(12,8),
            Pair<int, int>(12,9),
            Pair<int, int>(1,9)};
    ASSERT_EQ(g_scheduleFine(arr), 12);
}

TEST(rost4, test){
    Vector<Pair<int, int>>arr {
            Pair<int, int>(6,0),
            Pair<int, int>(7,1),
            Pair<int, int>(8,2),
            Pair<int, int>(9,3),
            Pair<int, int>(10,4),
            Pair<int, int>(11,5),
            Pair<int, int>(12,6),
            Pair<int, int>(11,8),
            Pair<int, int>(12,8),
            Pair<int, int>(13,8),
            Pair<int, int>(12,9),
            Pair<int, int>(1,9)};
    ASSERT_EQ(g_scheduleFine(arr), 7);
}


TEST(rost5, test){
    Vector<Pair<int, int>>arr {
            Pair<int, int>(12, 0),
            Pair<int, int>(12, 1),
            Pair<int, int>(12,2),
            Pair<int, int>(12,3),
            Pair<int, int>(12,4),
            Pair<int, int>(12,5),
            Pair<int, int>(12,6),
            Pair<int, int>(11,6),
            Pair<int, int>(10,6),
            Pair<int, int>(9,6),
            Pair<int, int>(8,6),
            Pair<int, int>(1,11),};
    ASSERT_EQ(g_scheduleFine(arr), 38);
}


TEST(rost6, test){
    Vector<Pair<int, int>>arr {
            Pair<int, int>(8, 0),
            Pair<int, int>(38, 0),};
    ASSERT_EQ(g_scheduleFine(arr), 8);
}

#endif //MINI_36_TESTS_H
