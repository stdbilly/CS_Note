#include <cassert>
#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

class Solution {
   public:
    void push(int value) {
        sData.push(value);
        if (sMin.empty() || value < sMin.top()) {
            sMin.push(value);
        } else {
            sMin.push(sMin.top());
        }
    }
    void pop() {
        assert(!sData.empty() && !sMin.empty());
        sData.pop();
        sMin.pop();
    }
    int top() { return sData.top(); }
    int min() { return sMin.top(); }

   private:
    stack<int> sData;
    stack<int> sMin;
};

int main() {
    Solution solution;
    solution.push(4);
    solution.push(3);
    solution.push(5);
    cout << solution.min() << endl;
    solution.push(2);
    cout << solution.min() << endl;
    return 0;
}