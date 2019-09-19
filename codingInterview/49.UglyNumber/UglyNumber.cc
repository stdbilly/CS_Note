#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
// 大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
// 习惯上我们把1当做第一个丑数。

class Solution {
   public:
    int GetUglyNumber_Solution(int index) {
        if (index <= 0) return 0;

        vector<int> uglyNums(index);
        uglyNums[0] = 1;
        auto iterMultiply2 = uglyNums.begin();
        auto iterMultiply3 = uglyNums.begin();
        auto iterMultiply5 = uglyNums.begin();
        //每个丑数都是前面的丑数乘以2,3或5得到的
        for (int i = 1; i < index; ++i) {
            int min = tripleMin(*iterMultiply2 * 2, *iterMultiply3 * 3,
                                *iterMultiply5 * 5);
            uglyNums[i] = min;

            while (*iterMultiply2 * 2 <= uglyNums[i]) {
                ++iterMultiply2;
            }
            while (*iterMultiply3 * 3 <= uglyNums[i]) {
                ++iterMultiply3;
            }
            while (*iterMultiply5 * 5 <= uglyNums[i]) {
                ++iterMultiply5;
            }
        }
        return uglyNums[index - 1];
    }

   private:
    int tripleMin(const int& a, const int& b, const int& c) {
        return a < b ? (a < c ? a : c) : (b < c ? b : c);
    }
};

// ====================测试代码====================
void Test(int index, int expected) {
    Solution solution;
    if (solution.GetUglyNumber_Solution(index) == expected)
        printf("solution2 passed\n");
    else
        printf("solution2 failed\n");
}

int main(int argc, char* argv[]) {
    Test(1, 1);

    Test(2, 2);
    Test(3, 3);
    Test(4, 4);
    Test(5, 5);
    Test(6, 6);
    Test(7, 8);
    Test(8, 9);
    Test(9, 10);
    Test(10, 12);
    Test(11, 15);

    Test(1500, 859963392);

    Test(0, 0);

    return 0;
}