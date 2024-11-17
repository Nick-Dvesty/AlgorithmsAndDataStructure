#include <vector>
#include <algorithm>

template<typename T>
using vector = std::vector<T>;

class UnionFind;
class UnionFind {
public:
    explicit UnionFind(int size);
    int             Find(int elem);
    void            Union(int firstElem, int SecondElem);
    int             GetFree(int elem);
    ~UnionFind();

private:
    vector<int>*     rank;
    vector<int>*     count;
    vector<int>*     parent;
};

UnionFind::UnionFind(int size) {
    rank = new vector<int>(size);
    count = new vector<int>(size);
    parent = new vector<int>(size);
    for (int i = 0; i < parent->size(); ++i) {
        (*parent)[i] = i;
    }
}

int UnionFind::Find(int elem) {
    if ((*parent)[elem] == elem) return elem;
    (*parent)[elem] = Find((*parent)[elem]);
    return (*parent)[elem];
}

void UnionFind::Union(int firstElem, int SecondElem) {
    if (Find(firstElem) == Find(SecondElem)) return;
    int IndMaxPar = (*rank)[Find(firstElem)] >(*rank)[Find(SecondElem)] ?
                    Find(firstElem) : Find(SecondElem);
    int IndMinPar = (*rank)[Find(firstElem)] <= (*rank)[Find(SecondElem)] ?
                    Find(firstElem) : Find(SecondElem);
    if ((*rank)[IndMaxPar] == (*rank)[IndMinPar])(*rank)[IndMaxPar]++;
    (*parent)[IndMinPar] = IndMaxPar;
    if (IndMinPar < IndMaxPar || (IndMaxPar - (*count)[IndMaxPar]) == IndMinPar){
        (*count)[IndMaxPar] += (*count)[IndMinPar];
    }
}

UnionFind::~UnionFind() {
    delete rank;
    delete count;
    delete parent;
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        UnionFind unionFind(edges.size());
        vector<int>* answer = nullptr;
        for (auto & edge : edges) {
            auto in = unionFind.Find(edge.front() - 1);
            auto to = unionFind.Find(edge.back() - 1);
            if (in == to) answer = &edge;
            unionFind.Union(edge.front() - 1, edge.back() - 1);
        }
        return *answer;
    }
};

#include <iostream>

int main() {
    vector<vector<int>> edges;
    edges.push_back(vector<int>{1,2});
    edges.push_back(vector<int>{1,3});
    edges.push_back(vector<int>{2,3});
    Solution sol;
    std::cout << sol.findRedundantDirectedConnection(edges).front()<<" "
                << sol.findRedundantDirectedConnection(edges).back();

    return 0;
}
