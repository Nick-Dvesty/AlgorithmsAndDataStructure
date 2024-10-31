//
// Created by modnick on 30.10.2024.
//

#include "Treap.h"
#include <random>
#include <algorithm>

template<typename T, bool (*K)(T, T)>
Treap<T, K>::Treap(T *key) : key(key), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {
    prior = rand() % 1000;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K>::Treap(Treap<T, K> &&treap) {
    this->key = treap.key;
    this->parent = treap.parent;
    this->rightChild = treap.rightChild;
    this->leftChild = treap.leftChild;
    this->prior = treap.prior;
    treap.prior = 0;
    treap.parent = nullptr;
    treap.leftChild = nullptr;
    treap.rightChild = nullptr;
}

template<typename T, bool (*K)(T, T)>
Treap<T, K>::Treap(std::vector<T>* keys) {
    std::sort(keys->begin(), keys->end(), compareT);
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
            if (nowElement->prior > nowParent->prior) {
                if (pastParent != nullptr){
                    nowElement->leftChild = pastParent;
                    nowElement->leftChild->parent = nowElement;
                }
                nowParent->rightChild = nowElement;
                nowElement->parent = nowParent;
                is = true;
                break;
            }
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
pairTreaps<T, K> Treap<T, K>::split(Treap<T, K>* rootPart, T key) {
    if (rootPart == nullptr) return pairTreaps<T,K>(nullptr, nullptr);
    if(K(key, *rootPart->key)) {
        auto ans = split(rootPart->rightChild, key);
        Treap<T, K>* RL = ans.first, *RR = ans.second;
        rootPart->rightChild = RL;
        rootPart->parent = nullptr;
        if (RL != nullptr) RL->parent = rootPart;
        if (RR != nullptr) RR->parent = nullptr;
        return pairTreaps<T, K>(rootPart, RR);
    } else {
        auto ans = split(rootPart->leftChild, key);
        Treap<T, K>* LL = ans.first, *LR = ans.second;
        rootPart->leftChild = LR;
        rootPart->parent = nullptr;
        if (LL != nullptr) LL->parent = nullptr;
        if (LR != nullptr) LR->parent = rootPart;
        return pairTreaps<T, K>(LL, rootPart);
    }
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
void Treap<T, K>::insert(T& newElem) {
    auto newNode = new Treap(&newElem);
    pairTreaps<T,K> r = split(this, newElem);
    auto ans = merge(merge(r.first, newNode), r.second);
    this->key = ans->key;
    this->parent = ans->parent;
    this->rightChild = ans->rightChild;
    this->leftChild = ans->leftChild;
    this->prior = ans->prior;
}

template<typename T, bool (*K)(T, T)>
void Treap<T, K>::remove(T delElem) {
    pairTreaps<T,K> r = split(this, delElem);
    auto ans = merge(r.first, r.second->getRightChild());
    this->key = ans->key;
    this->parent = ans->parent;
    this->rightChild = ans->rightChild;
    this->leftChild = ans->leftChild;
    this->prior = ans->prior;
}


