#include <iostream>
#include <stack>
#include <vector>
using std::cout;
using std::endl;
using std::stack;
using std::vector;

class Solution {
   public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        if (pushV.empty()) return false;

        stack<int> pushSeq;
        int j = 0;
        for (int i = 0; i < pushV.size(); ++i) {
            pushSeq.push(pushV[i]);
            while (!pushSeq.empty() && pushSeq.top() == popV[j]) {
                pushSeq.pop();
                ++j;
            }
        }
        return pushSeq.empty();
    }
};

int main() {
    Solution solution;
    vector<int> pushV{1, 2, 3, 4, 5};
    vector<int> popV{4, 5, 3, 2, 1};
    cout << solution.IsPopOrder(pushV, popV) << endl;
    return 0;
}