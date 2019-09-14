#include <iostream>
#include <stack>
using std::cout;
using std::endl;
using std::stack;

class Solution {
   public:
    void push(int node) { stack1.push(node); }

    int pop() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                int data = stack1.top();
                stack1.pop();
                stack2.push(data);
            }
        }
        
        if(stack2.empty()) {
            throw std::exception();
        }
        
        int ret = stack2.top();
        stack2.pop();
        return ret;
    }

   private:
    stack<int> stack1;
    stack<int> stack2;
};

int main() {
    Solution solution;
    solution.push(1);
    solution.push(2);
    solution.push(3);
    cout << solution.pop() << endl;
    return 0;
}