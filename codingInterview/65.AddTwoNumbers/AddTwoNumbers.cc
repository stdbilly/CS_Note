#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
// 四则运算符号。

class Solution {
   public:
    int Add(int num1, int num2) {
        int sum, carry;
        do {
            sum = num1 ^ num2;
            carry = (num1 & num2) << 1;

            num1 = sum;
            num2 = carry;
        } while (num2 != 0);
        return num1;
    }
};

int main() {
    Solution solution;
    cout << solution.Add(5, 7) << endl;
    return 0;
}