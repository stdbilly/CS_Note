#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

class Solution {
   public:
    ListNode* deleteDuplication(ListNode* head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val != cur->next->val) {
                pre = cur;
                cur = cur->next;
            } else {
                int val = cur->val;
                while (cur && cur->val == val) {
                    ListNode* delNode = cur;
                    cur = cur->next;
                    delete delNode;
                    delNode = nullptr;
                }
                pre->next = cur;
            }
        }
        return dummy.next;
    }
};

int main() {
    Solution solution;
    //vector<int> arr{1, 2, 3, 3, 4, 4, 5};
    vector<int> arr{3, 3, 3};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.deleteDuplication(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}