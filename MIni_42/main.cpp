#include <iostream>
#include "Treap.h"

bool compare(int left, int right) {
    return left > right;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto t = new std::vector<int>();
    t->push_back(1);
    t->push_back(2);
    t->push_back(3);
    t->push_back(4);
    Treap<int, compare> treap(t);
    auto t2 = Treap<int, compare>::split(&treap, 2);
    auto t3 = Treap<int, compare>::merge(t2.first, t2.second);
    auto t5 = new int(23);
    t3->insert(*t5);
    t3->remove(23);
    return 0;
}
