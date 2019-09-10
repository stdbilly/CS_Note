#include "list.h"

class Solution {
   public:
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        ListNode* p = head;
        while (p != nullptr) {
            ret.insert(ret.begin(), p->val);
            p = p->next;
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1,2,3,4,5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    vector<int> list = solution.printListFromTailToHead(head);
    for (auto &i : list)
    {
        cout << i << " -> ";   
    }
    cout << "NULL" << endl;
    return 0;
}