#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

class Solution {
   public:
    void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted) {
        if (!pListHead || !pToBeDeleted) return;

        //要删除的节点不是尾节点
        if (pToBeDeleted->next) {
            ListNode* pNext = pToBeDeleted->next;
            pToBeDeleted->val = pNext->val;
            pToBeDeleted->next = pNext->next;
            delete pNext;
            pNext = nullptr;
        } else if (pToBeDeleted == *pListHead) {
            //链表只有一个节点,要删除的节点为头结点
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
            *pListHead = nullptr;
        } else {
            //链表有多个节点, 删除尾节点
            ListNode* pCur = *pListHead;
            while (pCur->next != pToBeDeleted) {
                pCur = pCur->next;
            }
            pCur->next = nullptr;
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }

};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    solution.DeleteNode(&head, head);
    printLinkedList(head);
    destroyLinkedList(head);
    return 0;
}