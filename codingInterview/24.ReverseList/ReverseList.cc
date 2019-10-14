#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

class Solution {
   public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* pre = nullptr;
        ListNode* cur = pHead;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.ReverseList(head);
    printLinkedList(head2);
    destroyLinkedList(head2);

    return 0;
}