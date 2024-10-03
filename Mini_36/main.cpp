#include <iostream>
#include "UnionFind.h"
#include <utility>
#include <algorithm>

template<typename T> using Vector = std::vector<T>;
template<typename T, typename T2> using Pair = std::pair<T,T2>;
int Test(Vector<Pair<int, int>> tasks){
    std::sort(tasks.begin(), tasks.end(), std::greater<std::pair<int,int>>());
    ulong size = tasks.size();
    auto search = new UnionFind((int)size);
    auto answer = new Vector<Pair<int, int>>(size);
    for (int i = 0; i < size; i++) {
        int deadline = tasks[i].second;
        int parent = search->Find(deadline);
        int free = search->GetFree(parent);
        (*answer)[free] = tasks[i];
        search->Union(free, parent);
    }

    int result = 0;
    for (int i = 0; i < size; i++) {
        int fine = (*answer)[i].first;
        int deadline = (*answer)[i].second;
        if (deadline < i) result += fine;
    }
    return result;
}

int main() {
    Vector<Pair<int,int>>* test = new Vector<Pair<int,int>>(5);
    (*test)[0] = Pair<int,int>(25,2);
    (*test)[1] = Pair<int,int>(30,0);
    (*test)[2] = Pair<int,int>(50,2);
    (*test)[3] = Pair<int,int>(10,3);
    (*test)[4] = Pair<int,int>(15,2);
    std::cout<<Test(*test);
    return 0;
}

