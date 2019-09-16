#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(nullptr), random(nullptr) {}
};

void buildNodes(RandomListNode* pNode, RandomListNode* pNext,
                RandomListNode* pRandom) {
    if (pNode) {
        pNode->next = pNext;
        pNode->random = pRandom;
    }
}

void printList(RandomListNode* pHead) {
    RandomListNode* pNode = pHead;
    while (pNode != nullptr) {
        printf("The value of this node is: %d.\n", pNode->label);

        if (pNode->random != nullptr)
            printf("The value of its sibling is: %d.\n", pNode->random->label);
        else
            printf("This node does not have a sibling.\n");

        printf("\n");

        pNode = pNode->next;
    }
}