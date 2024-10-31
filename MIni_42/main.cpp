#include <iostream>
#include "Treap.h"

bool compare(int left, int right) {
    return left > right;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto t = new std::vector<int>();
    t->push_back(5);//
    t->push_back(24);//
    t->push_back(42);//
    t->push_back(13);//
    t->push_back(99);//
    t->push_back(2);//
    t->push_back(17);//
    Treap<int, compare> treap(t);
    auto t1 = Treap<int, compare>::splitBySize(&treap,2);
    return 0;
}
