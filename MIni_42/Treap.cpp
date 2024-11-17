//
// Created by modnick on 30.10.2024.
//

#include "Treap.h"
#include <random>
#include <algorithm>

template<typename T>
Treap<T>::Treap(T key) : key(key), parent(nullptr), leftChild(nullptr), rightChild(nullptr) {
    count = 1;
    sum = key;
    prior = rand() % 1000;
}

template<typename T>
Treap<T>::Treap(T* keys, size_t size) {
    std::vector<Treap<T>*> elements;
    for (int i = 0; i < size; ++i) {
        auto teat = new Treap<T>(keys[i]);
        elements.push_back(teat);
    }
    for (int i = 1; i < elements.size(); ++i) {
        Treap<T>* nowElement = elements[i];
        Treap<T>* pastParent = nullptr;
        Treap<T>* nowParent = elements[i - 1];
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
            if (!is) {
                nowElement->count+=(nowParent->count - nowElement->count + 1);
                nowElement->sum+=(nowParent->sum - nowElement->sum + nowElement->key);
            }
            else {
                nowParent->sum += nowElement->key;
                nowParent->count++;
            }
            pastParent = nowParent;
            nowParent = nowParent->parent;
        } while (nowParent != nullptr);
        if (!is) {
            nowElement->leftChild = pastParent;
            nowElement->leftChild->parent = nowElement;
        }
    }
    Treap<T>* nowEl = elements[0];
    while (nowEl->parent != nullptr) {
        nowEl = nowEl->parent;
    }
    moveInThis(*nowEl);
}

template<typename T>
Treap<T> *Treap<T>::getParent() {
    return parent;
}

template<typename T>
Treap<T> *Treap<T>::getLeftChild() {
    return leftChild;
}

template<typename T>
Treap<T> *Treap<T>::getRightChild() {
    return rightChild;
}

template<typename T>
T Treap<T>::getKey() {
    return key;
}

template<typename T>
T Treap<T>::getSum(unsigned int startIndex, unsigned int endIndex) {
    pairTreaps<T> leftPart = splitBySize(this, startIndex);
    pairTreaps<T> rightPart = splitBySize(leftPart.second, endIndex - startIndex + 1);
    auto answer =  rightPart.first->sum;
    auto rightMergePart = merge(rightPart.first, rightPart.second);
    merge(leftPart.first, rightMergePart);
    return answer;
}

template<typename T>
void Treap<T>::insert(T newElem, unsigned int pos) {
    auto newNode = new Treap(T(newElem));
    Treap<T>* ans;
    if (pos == 0) {
        ans = merge(newNode, this);
    } else if (pos == this->count) {
        ans = merge(this, newNode);
    } else {
        pairTreaps<T> r = splitBySize(this, pos - 1);
        ans = merge(merge(r.first, newNode), r.second);
    }
    moveInThis(*ans);
}

template<typename T>
void Treap<T>::erase(unsigned int pos) {
    pairTreaps<T> leftPart = splitBySize(this, pos - 1);
    pairTreaps<T> rightPart = splitBySize(leftPart.second, 1);
    auto ans = merge(leftPart.first, rightPart.second);
    moveInThis(*ans);
}


template<typename T>
Treap<T>* Treap<T>::merge(Treap<T>*left, Treap<T>*right) {
    if (left == nullptr) return right;
    if (right == nullptr) return left;
    if (left->prior < right->prior) {
        left->rightChild = merge(left->rightChild, right);
        if (left->rightChild != nullptr) left->rightChild->parent = left;
        updateC(*left);
        return left;
    } else {
        right->leftChild = merge(left, right->leftChild);
        if (right->leftChild != nullptr) right->leftChild->parent = right;
        updateC(*right);
        return right;
    }
}

template<typename T>
pairTreaps<T> Treap<T>::splitBySize(Treap<T>* rootPart, unsigned int size) {
    if (rootPart == nullptr) return pairTreaps<T>(nullptr, nullptr);
    unsigned int leftC = rootPart->leftChild != nullptr ? rootPart->leftChild->count : 0;
    if (size <= leftC) {
        auto ans = splitBySize(rootPart->leftChild, size);
        Treap<T>* LL = ans.first, *LR = ans.second;
        rootPart->leftChild = LR;
        rootPart->parent = nullptr;
        if (LL != nullptr) {
            LL->parent = nullptr;
        }
        if (LR != nullptr) {
            LR->parent = rootPart;
        }
        updateC(*rootPart);
        return pairTreaps<T>(LL, rootPart);
    } else {
        auto ans = splitBySize(rootPart->rightChild, size - leftC - 1);
        Treap<T>* RL = ans.first, *RR = ans.second;
        rootPart->rightChild = RL;
        rootPart->parent = nullptr;
        if (RL != nullptr) {
            RL->parent = rootPart;
        }
        if (RR != nullptr) {
            RR->parent = nullptr;
        }
        updateC(*rootPart);
        return pairTreaps<T>(rootPart, RR);
    }
}

template<typename T>
void Treap<T>::updateC(Treap<T> &rootPart) {
    unsigned int left = rootPart.leftChild != nullptr ? rootPart.leftChild->count : 0;
    unsigned int right = rootPart.rightChild != nullptr ? rootPart.rightChild->count : 0;
    rootPart.count = left + right + 1;
    updateSum(rootPart);
}

template<typename T>
void Treap<T>::updateSum(Treap<T> &rootPart) {
    rootPart.sum = rootPart.key;
    if (rootPart.leftChild != nullptr) {
        rootPart.sum += rootPart.leftChild->sum;
    }
    if (rootPart.rightChild != nullptr) {
        rootPart.sum += rootPart.rightChild->sum;
    }
}

template<typename T>
void Treap<T>::moveInThis(Treap<T> &rootPart) {
    this->key = rootPart.key;
    this->parent = rootPart.parent;
    this->rightChild = rootPart.rightChild;
    this->leftChild = rootPart.leftChild;
    this->prior = rootPart.prior;
    this->sum = rootPart.sum;
    this->count = rootPart.count;
}