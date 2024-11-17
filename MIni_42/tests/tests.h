//
// Created by modnick on 15.11.2024.
//
#include "gtest/gtest.h"
#include "../Treap.h"

#ifndef MINI_42_TESTS_H
#define MINI_42_TESTS_H

TEST(GetSumTest,first){
    int t[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    Treap<int> treap(t, 14);
    for (int i = 0; i < 14; ++i) {
        ASSERT_EQ(treap.getSum(i,i), i + 1);
    }
}

TEST(GetSumTest,second){
    int t[] = {14,13,12,11,10,9, 8,7,6,5,4,3,2,1};
    Treap<int> treap(t, 14);
    for (int i = 0; i < 14; ++i) {
        ASSERT_EQ(treap.getSum(i,i), 14 - i);
    }
}

TEST(GetSumTest,thirt){
    int t[] = {1,14,2,13,3,12,4,11,5,10,6,9,7,8};
    Treap<int> treap(t, 14);
    for (int i = 0; i < 14; ++i) {
        ASSERT_EQ(treap.getSum(i,i), t[i]);
    }
}

TEST(GetSumTest,fouth){
    int t[] = {1,14,2,13,3,12,4,11,5,10,6,9,7,8};
    Treap<int> treap(t, 14);
    for (int i = 0; i < 13; ++i) {
        ASSERT_EQ(treap.getSum(i,i + 1), t[i] + t[i + 1]);
    }
}

TEST(GetSumTest,fifth){
    int t[] = {1,2,3,4,5,6,7};
    Treap<int> treap(t, 14);
    treap.erase(1);
    ASSERT_EQ(treap.getSum(0,5),27);
}


#endif //MINI_42_TESTS_H
