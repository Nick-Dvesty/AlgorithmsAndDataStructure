#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int val;
    int freq;
    struct Node* next;
} Node;

typedef struct FreqStack {
    Node* dict[20000];
    Node* same_freq[20000];
    int maxfr;
} FreqStack;

FreqStack* freqStackCreate() {
    FreqStack* obj = (FreqStack*)malloc(sizeof(FreqStack));
    memset(obj->dict, 0, sizeof(obj->dict));
    memset(obj->same_freq, 0, sizeof(obj->same_freq));
    obj->maxfr = 0;
    return obj;
}

void freqStackPush(FreqStack* obj, int val) {
    int valOld = val;
    while (val > 20000) val /= 10;
    if (obj->dict[val] == NULL) {
        obj->dict[val] = (Node*)malloc(sizeof(Node));
        obj->dict[val]->val = valOld;
        obj->dict[val]->freq = 1;
        obj->dict[val]->next = NULL;
    } else {
        obj->dict[val]->freq++;
    }

    int freq = obj->dict[val]->freq;
    if (obj->same_freq[freq] == NULL) {
        obj->same_freq[freq] = (Node*)malloc(sizeof(Node));
        obj->same_freq[freq]->val = valOld;
        obj->same_freq[freq]->freq = freq;
        obj->same_freq[freq]->next = NULL;
    } else {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->val = valOld;
        newNode->freq = freq;
        newNode->next = obj->same_freq[freq];
        obj->same_freq[freq] = newNode;
    }

    obj->maxfr = (freq > obj->maxfr) ? freq : obj->maxfr;
}

int freqStackPop(FreqStack* obj) {
    int val = obj->same_freq[obj->maxfr]->val;
    int valOld = val;
    while (val > 20000) val /= 10;
    obj->dict[val]->freq--;

    if (obj->dict[val]->freq == 0) {
        free(obj->dict[val]);
        obj->dict[val] = NULL;
    }

    Node* temp = obj->same_freq[obj->maxfr];
    obj->same_freq[obj->maxfr] = obj->same_freq[obj->maxfr]->next;
    free(temp);

    if (obj->same_freq[obj->maxfr] == NULL) {
        obj->maxfr--;
    }

    return val;
}

void freqStackFree(FreqStack* obj) {
    for (int i = 0; i < 10001; i++) {
        if (obj->dict[i] != NULL) {
            free(obj->dict[i]);
        }
        if (obj->same_freq[i] != NULL) {
            Node* temp = obj->same_freq[i];
            while (temp != NULL) {
                Node* next = temp->next;
                free(temp);
                temp = next;
            }
        }
    }
    free(obj);
}

