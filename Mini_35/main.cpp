#include <vector>
#include <algorithm>
#include <iostream>

template<typename T>
using vector = std::vector<T>;

class UnionFind;
class UnionFind {
public:
    explicit UnionFind(int size);
    int             Find(int elem);
    void            Union(int firstElem, int SecondElem);
    ~UnionFind();

private:
    vector<int>*     count;
    vector<int>*     rank;
    vector<int>*     parent;
};

UnionFind::UnionFind(int size) {
    rank = new vector<int>(size);
    count = new vector<int>(size, 1);
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
    int IndMaxPar = Find(firstElem);
    int IndMinPar = Find(SecondElem);
    if ((*rank)[IndMaxPar] == (*rank)[IndMinPar])(*rank)[IndMaxPar]++;
    (*parent)[IndMinPar] = IndMaxPar;
    (*count)[IndMaxPar] += (*count)[IndMinPar];
    (*count)[IndMinPar] = 0;
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
        int d = -1;
        for (auto & edge : edges) {
            auto in = unionFind.Find(edge.front() - 1) + 1;
            auto to = unionFind.Find(edge.back() - 1) + 1;
            if (to != edge.back())
                d = edge.back();
            else {
                unionFind.Union(edge.front() - 1, edge.back() - 1);
            }
            if (in == to) answer = &edge;
        }
            for ( auto & edge : edges) {
                if (edge.back() == d) {
                    auto in = unionFind.Find(edge.front() - 1) + 1;
                    auto to = unionFind.Find(edge.back() - 1) + 1;
                    if (in == to) answer = &edge;
                }
            }
        return *answer;
    }
};

#include <iostream>

int main() {
    vector<vector<int>> edges;
    edges.push_back(vector<int>{5,2});
    edges.push_back(vector<int>{5,1});
    edges.push_back(vector<int>{3,1});
    edges.push_back(vector<int>{3,4});
    edges.push_back(vector<int>{3,5});

    vector<vector<int>> edges2;
    edges2.push_back(vector<int>{2,1});
    edges2.push_back(vector<int>{3,1});
    edges2.push_back(vector<int>{4,2});
    edges2.push_back(vector<int>{1,4});

    vector<vector<int>> edges3;
    edges3.push_back(vector<int>{1,2});
    edges3.push_back(vector<int>{1,3});
    edges3.push_back(vector<int>{2,3});

    vector<vector<int>> edges4;
    edges4.push_back(vector<int>{1,2});
    edges4.push_back(vector<int>{2,3});
    edges4.push_back(vector<int>{3,4});
    edges4.push_back(vector<int>{4,1});
    edges4.push_back(vector<int>{1,5});

    Solution sol;
    auto r = sol.findRedundantDirectedConnection(edges2);
    std::cout<<r.front()<<" "<<r.back();

    return 0;
}
