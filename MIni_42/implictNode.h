//
// Created by modnick on 30.10.2024.
//

#ifndef MINI_42_IMPLICTNODE_H
#define MINI_42_IMPLICTNODE_H

template<typename T>
class implictNode {
public:
    implictNode(T* key);
    implictNode<T>* getParent();
    implictNode<T>* getLeftChild();
    implictNode<T>* getRightChild();
    T               getKey();
private:
    implictNode*    parent;
    implictNode*    leftChild;
    implictNode*    rightChild;
    T*               key;
    unsigned int    prior;
};


#endif //MINI_42_IMPLICTNODE_H
