//
// Created by modnick on 03.10.2024.
//

#ifndef MINI_36_SHEDULEFINE_H
#define MINI_36_SHEDULEFINE_H

#include <utility>
#include <algorithm>

#include "UnionFind.h"

template<typename T> using Vector = std::vector<T>;
template<typename T, typename T2> using Pair = std::pair<T,T2>;
int g_scheduleFine(Vector<Pair<int, int>> tasks){
    std::sort(tasks.begin(), tasks.end(), std::greater<std::pair<int,int>>());
    ulong size = tasks.size();
    auto search = new UnionFind((int)size);
    Vector<Pair<int, int>>answer{size};
    for (int i = 0; i < size; i++) {
        int deadline = tasks[i].second;
        int parent = search->Find(deadline);
        int free = search->GetFree(parent);
        answer[free] = tasks[i];
        search->Union(free, parent);
    }

    int result = 0;
    for (int i = 0; i < size; i++) {
        int fine = answer[i].first;
        int deadline = answer[i].second;
        if (deadline < i) result += fine;
    }
    delete search;
    return result;
}
#endif //MINI_36_SHEDULEFINE_H
