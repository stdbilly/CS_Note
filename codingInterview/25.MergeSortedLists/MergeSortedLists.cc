#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。例如输入图3.11中的链表1和链表2，则合并之后的升序链表如链
// 表3所示。

class Solution {
   public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode dummy(-1);
        ListNode* tail = &dummy;
        while (pHead1 && pHead2) {
            if (pHead1->val < pHead2->val) {
                tail->next = pHead1;
                pHead1 = pHead1->next;
            } else {
                tail->next = pHead2;
                pHead2 = pHead2->next;
            }
            tail = tail->next;
        }
        tail->next = pHead1 ? pHead1 : pHead2;
        return dummy.next;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 3, 5, 7};
    vector<int> arr2{2, 4, 6, 8};
    ListNode* head1 = createLinkedList(arr);
    printLinkedList(head1);
    ListNode* head2 = createLinkedList(arr2);
    printLinkedList(head2);
    ListNode* head = solution.Merge(head1, head2);
    printLinkedList(head);
    destroyLinkedList(head);
    destroyLinkedList(head1);
    destroyLinkedList(head2);
    return 0;
}