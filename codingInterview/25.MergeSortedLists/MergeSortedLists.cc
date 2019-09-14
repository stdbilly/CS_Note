#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

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