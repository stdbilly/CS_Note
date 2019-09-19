#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

// 面试题52：两个链表的第一个公共结点
// 题目：输入两个链表，找出它们的第一个公共结点。

class Solution {
   public:
    ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2) {
        unsigned int len1 = getListLen(pHead1);
        unsigned int len2 = getListLen(pHead2);
        int lenDif = len1 - len2;

        ListNode* pHeadLong = pHead1;
        ListNode* pHeadShort = pHead2;
        if (len2 > len1) {
            pHeadLong = pHead2;
            pHeadShort = pHead1;
            lenDif = len2 - len1;
        }
        //先在长链表上走几步,再同时开始遍历
        for (int i = 0; i < lenDif; i++) {
            pHeadLong = pHeadLong->next;
        }

        while (pHeadLong && pHeadShort && pHeadLong != pHeadShort) {
            pHeadLong = pHeadLong->next;
            pHeadShort = pHeadShort->next;
        }
        return pHeadLong;
    }

   private:
    unsigned int getListLen(ListNode* pHead) {
        unsigned int len = 0;
        while (pHead) {
            ++len;
            pHead = pHead->next;
        }
        return len;
    }
};

// ====================测试代码====================
void DestroyNode(ListNode* pNode) {
    delete pNode;
    pNode = nullptr;
}

void Test(char* testName, ListNode* pHead1, ListNode* pHead2,
          ListNode* pExpected) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: ", testName);

    ListNode* pResult = solution.FindFirstCommonNode(pHead1, pHead2);
    if (pResult == pExpected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 第一个公共结点在链表中间
// 1 - 2 - 3 \
//            6 - 7
//     4 - 5 /
void Test1() {
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);
    ListNode* pNode6 = new ListNode(6);
    ListNode* pNode7 = new ListNode(7);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode6);
    connectListNodes(pNode4, pNode5);
    connectListNodes(pNode5, pNode6);
    connectListNodes(pNode6, pNode7);

    Test("Test1", pNode1, pNode4, pNode6);

    DestroyNode(pNode1);
    DestroyNode(pNode2);
    DestroyNode(pNode3);
    DestroyNode(pNode4);
    DestroyNode(pNode5);
    DestroyNode(pNode6);
    DestroyNode(pNode7);
}

int main() {
    Test1();
    return 0;
}