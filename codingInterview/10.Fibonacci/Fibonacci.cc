#include <iostream>
using std::cout;
using std::endl;

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项

class Solution {
   public:
    int Fibonacci(int n) {
        int result[2] = {0, 1};
        if (n < 2) return result[n];
        int fibNMinusOne = 1;
        int fibNMinusTwo = 0;
        int fibN = 0;
        for (int i = 2; i <= n; ++i) {
            fibN = fibNMinusOne + fibNMinusTwo;
            fibNMinusTwo = fibNMinusOne;
            fibNMinusOne = fibN;
        }
        return fibN;
    }
};

int main() {
    Solution solution;
    cout << solution.Fibonacci(10) << endl;
    return 0;
}