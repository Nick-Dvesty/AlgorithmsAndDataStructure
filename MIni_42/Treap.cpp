//
// Created by modnick on 30.10.2024.
//

#include "Treap.h"
#include <random>
#include <algorithm>

template<typename T, bool (*K)(T, T)>
Treap<T, K>::Treap(T *key) : key(key), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {
    c = 1;
    prior = rand() % 1000;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K>::Treap(std::vector<T>* keys) {
    //std::sort(keys->begin(), keys->end(), compareT);
    std::vector<Treap<T, K>*> elements;
    for (int i = 0; i < keys->size(); ++i) {
        auto teat = new Treap<T,K>(&(*keys)[i]);
        elements.push_back(teat);
    }
    for (int i = 1; i < elements.size(); ++i) {
        Treap<T,K>* nowElement = elements[i];
        Treap<T,K>* pastParent = nullptr;
        Treap<T,K>* nowParent = elements[i - 1];
        bool is = false;
        do {
            if (nowElement->prior > nowParent->prior && !is) {
                if (pastParent != nullptr){
                    nowElement->leftChild = pastParent;
                    nowElement->leftChild->parent = nowElement;
                }
                nowParent->rightChild = nowElement;
                nowElement->parent = nowParent;
                is = true;
            }
            if (!is)
                nowElement->c+=(nowParent->c - nowElement->c + 1);
            else
                nowParent->c++;
            pastParent = nowParent;
            nowParent = nowParent->parent;
        } while (nowParent != nullptr);
        if (!is) {
            nowElement->leftChild = pastParent;
            nowElement->leftChild->parent = nowElement;
        }
    }
    Treap<T,K>* nowEl = elements[0];
    while (nowEl->parent != nullptr) {
        nowEl = nowEl->parent;
    }
    key = nowEl->key;
    parent = nowEl->parent;
    leftChild = nowEl->leftChild;
    rightChild = nowEl->rightChild;
    prior = nowEl->prior;
    c = nowEl->c;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K> *Treap<T, K>::getParent() {
    return parent;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K> *Treap<T, K>::getLeftChild() {
    return leftChild;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K> *Treap<T, K>::getRightChild() {
    return rightChild;
}

template<typename T, bool (*K)(T, T)>
T Treap<T, K>::getKey() {
    return key;
}

template<typename T, bool (*K)(T, T)>
pairTreaps<T, K> Treap<T, K>::splitBySize(Treap<T, K>* rootPart, unsigned int size) {
    if (rootPart == nullptr) return pairTreaps<T,K>(nullptr, nullptr);
    unsigned int leftC = rootPart->leftChild != nullptr ? rootPart->leftChild->c : 0;
    if (size <= leftC) {
        auto ans = splitBySize(rootPart->leftChild, size);
        Treap<T, K>* LL = ans.first, *LR = ans.second;
        rootPart->leftChild = LR;
        rootPart->parent = nullptr;
        if (LL != nullptr) LL->parent = nullptr;
        if (LR != nullptr) LR->parent = rootPart;
        updateC(*rootPart);
        return pairTreaps<T, K>(LL, rootPart);
    } else {
        auto ans = splitBySize(rootPart->rightChild, size - leftC - 1);
        Treap<T, K>* RL = ans.first, *RR = ans.second;
        rootPart->rightChild = RL;
        rootPart->parent = nullptr;
        if (RL != nullptr) RL->parent = rootPart;
        if (RR != nullptr) RR->parent = nullptr;
        updateC(*rootPart);
        return pairTreaps<T, K>(rootPart, RR);
    }
}

template<typename T, bool (*K)(T, T)>
void Treap<T, K>::updateC(Treap<T, K> &rootPart) {
    unsigned int left = rootPart.leftChild != nullptr ? rootPart.leftChild->c : 0;
    unsigned int right = rootPart.rightChild != nullptr ? rootPart.rightChild->c : 0;
    rootPart.c = left + right + 1;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K>* Treap<T, K>::merge(Treap<T, K>*left, Treap<T, K>*right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->prior < right->prior) {
        left->rightChild = merge(left->rightChild, right);
        if (left->rightChild != nullptr) left->rightChild->parent = left;
        return left;
    } else {
        right->leftChild = merge(left, right->leftChild);
        if (right->leftChild != nullptr) right->leftChild->parent = right;
        return right;
    }
}

template<typename T, bool (*K)(T, T)>
bool Treap<T,K>::compareT(T left, T right){
    return !K(left, right);
}

template<typename T, bool (*K)(T, T)>
void Treap<T, K>::insert(T& newElem, unsigned int pos) {
    auto newNode = new Treap(&newElem);
    pairTreaps<T,K> r = splitBySize(this, pos - 1);
    auto ans = merge(merge(r.first, newNode), r.second);
    this->key = ans->key;
    this->parent = ans->parent;
    this->rightChild = ans->rightChild;
    this->leftChild = ans->leftChild;
    this->prior = ans->prior;
    this->c = ans->c;
}

template<typename T, bool (*K)(T, T)>
void Treap<T, K>::erase(unsigned int pos) {
    pairTreaps<T,K> r = splitBySize(this, pos -1);
    pairTreaps<T,K> r2 = splitBySize(r.second, 1);
    auto ans = merge(r.first, r2.second);
    this->key = ans->key;
    this->parent = ans->parent;
    this->rightChild = ans->rightChild;
    this->leftChild = ans->leftChild;
    this->prior = ans->prior;
    this->c = ans->c;
}


