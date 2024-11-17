//
// Created by modnick on 30.10.2024.
//

#ifndef MINI_42_IMPLICITTREE_H
#define MINI_42_IMPLICITTREE_H

#include <iostream>
#include <vector>

template<typename T> class Treap;
template<typename T> using pairTreaps = std::pair<Treap<T>*, Treap<T>*>;

template<typename T>
class Treap {
public:
                            Treap(T key);
                            Treap(T* keys, size_t size);
    Treap<T>*               getParent();
    Treap<T>*               getLeftChild();
    Treap<T>*               getRightChild();
    T                       getKey();
    T                       getSum(unsigned int startIndex, unsigned int endIndex);
    void                    insert(T newElem, unsigned int pos);
    void                    erase(unsigned int pos);

private:
    static Treap<T>*        merge(Treap<T>* left, Treap<T>* right);
    static pairTreaps<T>    splitBySize(Treap<T>* rootPart, unsigned int size);
    static void             updateC(Treap<T>& rootPart);
    static void             updateSum(Treap<T> &rootPart);
    void                    moveInThis(Treap<T> &rootPart);

    T                       key;
    Treap<T>*               parent;
    Treap<T>*               leftChild;
    Treap<T>*               rightChild;
    unsigned int            count;
    T                       sum;
    unsigned int            prior;

};

#include "Treap.cpp"

#endif //MINI_42_IMPLICITTREE_H
