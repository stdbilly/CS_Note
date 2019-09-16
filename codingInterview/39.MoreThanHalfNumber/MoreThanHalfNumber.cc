#include <iostream>
#include <vector>
#include "array.h"
using std::cout;
using std::endl;
using std::vector;

// 面试题39：数组中出现次数超过一半的数字
// 题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
// 如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
// 出现了5次，超过数组长度的一半，因此输出2。

class Solution {
   public:
    //方法一: 基于partition函数, 时间复杂度O(n), 会修改数组元素
    int MoreThanHalfNum_Solution1(vector<int> numbers) {
        if (numbers.empty()) return 0;

        int mid = numbers.size() >> 1;
        int start = 0;
        int end = numbers.size() - 1;
        int index = partition(numbers, start, end);
        while (index != mid) {
            if (index > mid) {
                end = index - 1;
                index = partition(numbers, start, end);
            } else {
                start = index + 1;
                index = partition(numbers, start, end);
            }
        }

        int result = numbers[mid];
        if (!checkMoreThanHalf(numbers, result)) result = 0;

        return result;
    }

    //方法2:根据数组特点找出,时间复杂度O(n),不会修改数组元素
    int MoreThanHalfNum_Solution2(vector<int> numbers) {
        if (numbers.empty()) return 0;

        int result = numbers[0];
        int times = 1;
        for (int i = 1; i < numbers.size(); ++i) {
            if (times == 0) {
                result = numbers[i];
                times = 1;
            } else if (numbers[i] == result) {
                ++times;
            } else {
                --times;
            }
        }
        if (!checkMoreThanHalf(numbers, result)) result = 0;

        return result;
    }

   private:
    bool checkMoreThanHalf(vector<int>& nums, int number) {
        int times = 0;
        for (auto& i : nums) {
            if (i == number) {
                ++times;
            }
        }

        bool isMoreThanHalf = true;
        if (times * 2 <= nums.size()) {
            isMoreThanHalf = false;
        }
        return isMoreThanHalf;
    }
};

// ====================测试代码====================
void Test(char* testName, vector<int>& numbers, int expectedValue) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: \n", testName);

    vector<int> copy(numbers);

    printf("Test for solution1: ");
    int result = solution.MoreThanHalfNum_Solution1(numbers);
    if (result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");

    printf("Test for solution2: ");
    result = solution.MoreThanHalfNum_Solution2(copy);
    if(result == expectedValue)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 存在出现次数超过数组长度一半的数字
void Test1() {
    vector<int> numbers{1, 2, 3, 2, 2, 2, 5, 4, 2};
    Test("Test1", numbers, 2);
}

// 不存在出现次数超过数组长度一半的数字
void Test2() {
    vector<int> numbers{1, 2, 3, 2, 4, 2, 5, 2, 3};
    Test("Test2", numbers, 0);
}

// 出现次数超过数组长度一半的数字都出现在数组的前半部分
void Test3() {
    vector<int> numbers{2, 2, 2, 2, 2, 1, 3, 4, 5};
    Test("Test3", numbers, 2);
}

int main() {
    Test1();
    Test2();
    Test3();
    return 0;
}