//
// Created by modnick on 03.10.2024.
//

#ifndef MINI_36_UNIONFIND_H
#define MINI_36_UNIONFIND_H

#include <vector>

template<typename T> using Vector = std::vector<T>;
class UnionFind;
class UnionFind {
public:
                    explicit UnionFind(int size);
    int             Find(int elem);
    void            Union(int firstElem, int SecondElem);
    int             GetFree(int elem);
                    ~UnionFind();

private:
    Vector<int>*     rank;
    Vector<int>*     count;
    Vector<int>*     parent;
};


#endif //MINI_36_UNIONFIND_H
