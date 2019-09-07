#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

struct ListNode {
        int val;
        struct ListNode *next;
        ListNode(int x) :
              val(x), next(NULL) {
        }
  };

class Solution {
public:
     vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret;
        ListNode* p = head;
        while (p!=nullptr)
        {
            ret.insert(ret.begin(), p->val);
            p = p->next;
        }
        return ret;
    }
};

int main(){
   Solution solution;
   
   return 0;
}