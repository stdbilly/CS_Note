#include <iostream>
#include <vector>
#include "ComplexList.h"
using std::cout;
using std::endl;
using std::vector;

// 面试题35：复杂链表的复制
// 题目：请实现函数RandomListNode* Clone(RandomListNode* pHead)，复
// 制一个复杂链表。在复杂链表中，每个结点除了有一个m_pNext指针指向下一个
// 结点外，还有一个m_pSibling 指向链表中的任意结点或者nullptr。

class Solution {
   public:
    RandomListNode* Clone(RandomListNode* pHead) {
        cloneNodes(pHead);
        connectSiblingNodes(pHead);
        return reconnectNodes(pHead);
    }

   private:
    void cloneNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while (pNode) {
            RandomListNode* pClone = new RandomListNode(pNode->label);
            pClone->next = pNode->next;
            pNode->next = pClone;
            pNode = pClone->next;
        }
    }

    void connectSiblingNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        while (pNode) {
            RandomListNode* pClone = pNode->next;
            if (pNode->random) {
                pClone->random = pNode->random->next;
            }
            pNode = pClone->next;
        }
    }

    RandomListNode* reconnectNodes(RandomListNode* pHead) {
        RandomListNode* pNode = pHead;
        RandomListNode* pCloneHead = nullptr;
        RandomListNode* pCloneNode = nullptr;

        if (pNode) {
            pCloneHead = pCloneNode = pNode->next;
            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }

        while (pNode) {
            pCloneNode->next = pNode->next;
            pCloneNode = pCloneNode->next;

            pNode->next = pCloneNode->next;
            pNode = pNode->next;
        }
        return pCloneHead;
    }
};

// ====================测试代码====================
void Test(const char* testName, RandomListNode* pHead) {
    Solution solution;
    if (testName != nullptr) printf("%s begins:\n", testName);

    printf("The original list is:\n");
    printList(pHead);

    RandomListNode* pClonedHead = solution.Clone(pHead);

    printf("The cloned list is:\n");
    printList(pClonedHead);
}

//          -----------------
//         \|/              |
//  1-------2-------3-------4-------5
//  |       |      /|\             /|\
//  --------+--------               |
//          -------------------------
void Test1() {
    RandomListNode* pNode1 = new RandomListNode(1);
    RandomListNode* pNode2 = new RandomListNode(2);
    RandomListNode* pNode3 = new RandomListNode(3);
    RandomListNode* pNode4 = new RandomListNode(4);
    RandomListNode* pNode5 = new RandomListNode(5);

    buildNodes(pNode1, pNode2, pNode3);
    buildNodes(pNode2, pNode3, pNode5);
    buildNodes(pNode3, pNode4, nullptr);
    buildNodes(pNode4, pNode5, pNode2);

    Test("Test1", pNode1);
}

int main() {
    Test1();
    return 0;
}