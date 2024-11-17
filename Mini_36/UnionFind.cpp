//
// Created by modnick on 03.10.2024.
//

#include "UnionFind.h"

UnionFind::UnionFind(int size) {
    rank = new Vector<int>(size);
    count = new Vector<int>(size);  //count using field in union
    parent = new Vector<int>(size); //parent elements
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
    int IndMaxPar = (*rank)[Find(firstElem)] >(*rank)[Find(SecondElem)] ?
            Find(firstElem) : Find(SecondElem);
    int IndMinPar = (*rank)[Find(firstElem)] <= (*rank)[Find(SecondElem)] ?
            Find(firstElem) : Find(SecondElem);
    if ((*rank)[IndMaxPar] == (*rank)[IndMinPar])(*rank)[IndMaxPar]++;
    (*parent)[IndMinPar] = IndMaxPar;
    if (IndMinPar < IndMaxPar || (IndMaxPar - (*count)[IndMaxPar]) == IndMinPar){
        (*count)[IndMaxPar] += (*count)[IndMinPar];
    }
}

int UnionFind::GetFree(int elem) {
    int oldParent = Find(elem);
    int newElem = oldParent - (*count)[oldParent];
    if (newElem < 0) {
        return GetFree(rank->size() - 1);
    }
    int newParent = Find(newElem);

    if ((*count)[newParent] == 0) {
        (*count)[newParent]++;
        return newParent;
    }
    Union(oldParent, newParent);
    return GetFree(Find(newParent));
}

UnionFind::~UnionFind() {
    delete rank;
    delete count;
    delete parent;
}