//
// Created by modnick on 30.10.2024.
//

#include <random>

#include "implictNode.h"


template<typename T>
implictNode<T>::implictNode(T* key) : leftChild(nullptr), rightChild(nullptr), parent(nullptr), key(key) {
    prior = rand();
}

template<typename T>
implictNode<T> *implictNode<T>::getLeftChild() { return leftChild; }

template<typename T>
implictNode<T> *implictNode<T>::getRightChild() { return rightChild; }

template<typename T>
implictNode<T> *implictNode<T>::getParent() { return parent; }

template<typename T>
T implictNode<T>::getKey() { return key; }