#include <iostream>
#include <set>
#include <vector>
#include "array.h"
using std::cout;
using std::endl;
using std::multiset;
using std::vector;

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
// 这8个数字，则最小的4个数字是1、2、3、4。

class Solution {
   public:
    //方法一: 基于partition函数, 时间复杂度O(n), 会修改数组元素
    vector<int> GetLeastNumbers_Solution1(vector<int> input, int k) {
        if (input.empty() || k <= 0 || k > input.size()) return {};

        int start = 0;
        int end = input.size() - 1;
        int index = partition(input, start, end);

        while (index != k - 1) {
            if (index > k - 1) {
                end = index - 1;
                index = partition(input, start, end);
            } else {
                start = index + 1;
                index = partition(input, start, end);
            }
        }
        vector<int> ret;
        for (int i = 0; i < k; ++i) {
            ret.push_back(input[i]);
        }
        return ret;
    }

    //方法二: 使用std::multiset(最大堆), 时间复杂度O(nlogk),
    //不需要修改数组,适合海量数据
    vector<int> GetLeastNumbers_Solution2(vector<int> input, int k) {
        if (input.empty() || k <= 0 || k > input.size()) return {};

        for (auto& val : input) {
            if (leastNums.size() < k) {
                leastNums.insert(val);
            } else {
                auto iterGreatest = leastNums.begin();
                if (val < *iterGreatest) {
                    leastNums.erase(iterGreatest);
                    leastNums.insert(val);
                }
            }
        }
        vector<int> ret(leastNums.begin(), leastNums.end());
        return ret;
    }

   private:
    multiset<int, std::greater<int>> leastNums;
};

// ====================测试代码====================
void Test(char* testName, vector<int>& data, vector<int>& expectedResult,
          int k) {
    Solution solution;
    if (testName != nullptr) printf("%s begins: \n", testName);

    if (expectedResult.empty())
        printf("The input is invalid, we don't expect any result.\n");
    else {
        printf("Expected result: \n");
        display(expectedResult);
    }

    printf("Result for solution1:\n");
    vector<int> ret = solution.GetLeastNumbers_Solution1(data, k);

    if (!expectedResult.empty()) {
        display(ret);
    }

    if (expectedResult.empty())
        printf("The input is invalid, we don't expect any result.\n");
    else {
        printf("Expected result: \n");
        display(expectedResult);
    }

    printf("Result for solution2:\n");
    ret = solution.GetLeastNumbers_Solution2(data, k);

    if (!expectedResult.empty()) {
        display(ret);
    }

    cout << endl;
}

// k小于数组的长度
void Test1() {
    vector<int> data{4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected{1, 2, 3, 4};
    Test("Test1", data, expected, expected.size());
}

// k等于数组的长度
void Test2() {
    vector<int> data{4, 5, 1, 6, 2, 7, 3, 8};
    vector<int> expected{1, 2, 3, 4, 5, 6, 7, 8};
    Test("Test2", data, expected, expected.size());
}

int main() {
    Test1();
    Test2();
    return 0;
}