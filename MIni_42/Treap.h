//
// Created by modnick on 30.10.2024.
//

#ifndef MINI_42_IMPLICITTREE_H
#define MINI_42_IMPLICITTREE_H

#include <iostream>
#include <vector>

#include "implictNode.h"

template<typename T, bool (*K)(T, T)> class Treap;
template<typename T, bool (*K)(T, T)> using pairTreaps = std::pair<Treap<T,K>*, Treap<T,K>*>;

template<typename T, bool (*K)(T, T)>
class Treap {
public:
                            Treap(T* key);
                            Treap(std::vector<T>* keys);
                            Treap(Treap&& treap);
    Treap<T, K>*            getParent();
    Treap<T, K>*            getLeftChild();
    Treap<T, K>*            getRightChild();
    T                       getKey();
    void                    insert(T& newElem);
    void                    remove(T delElem);
    static Treap<T, K>*     merge(Treap<T, K>* left, Treap<T, K>* right);
    static pairTreaps<T, K> split(Treap<T, K>* rootPart, T key);
    static bool             compareT(T left, T right);
private:
    T*                      key;
    Treap<T, K>*            parent;
    Treap<T, K>*            leftChild;
    Treap<T, K>*            rightChild;
    unsigned int            prior;

};

#include "Treap.cpp"

#endif //MINI_42_IMPLICITTREE_H
