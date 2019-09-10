#include <iostream>
#include <vector>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    //一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法（先后次序不同算不同的结果）。
    int jumpFloor(int number) {
        if (number <= 2) return number;
        int nMinusOne = 2;
        int nMinusTwo = 1;
        int ret = 0;
        for (int i = 3; i <= number; ++i) {
            ret = nMinusOne + nMinusTwo;
            nMinusTwo = nMinusOne;
            nMinusOne = ret;
        }
        return ret;
    }

    //一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
    /* 
    f(1) = 1
    f(n-1) = f(n-2) + f(n-3) + ... + f(1)
    f(n) = f(n-1) + f(n-2) + ... + f(1)
    综上可得, f(n) - f(n-1) = f(n-1)
    即, f(n) = 2*f(n-1) = 2^(n-1)
     */
    int jumpFloorII(int number) {
        return  (int)pow(2, number -1);
    }
};

int main() {
    Solution solution;
    cout << solution.jumpFloor(4) << endl;
    return 0;
}