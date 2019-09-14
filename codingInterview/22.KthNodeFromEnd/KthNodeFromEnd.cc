#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

class Solution {
   public:
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        if (!pListHead || k == 0) return nullptr;
        ListNode* pAhead = pListHead;
        ListNode* pBehind = pListHead;
        for (int i = 0; i < k - 1; ++i) {
            if (pAhead->next) {
                pAhead = pAhead->next;
            } else {
                return nullptr;
            }
        }

        while (pAhead->next) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pBehind;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 6, 3, 4, 5, 6};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* pNode = solution.FindKthToTail(head, 4);
    cout << pNode->val << endl;
    destroyLinkedList(head);
    return 0;
}