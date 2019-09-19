#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
// 的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

class Solution {
   public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        if (array.empty()) return {};
        int left = 0;
        int right = array.size() - 1;

        while (left < right) {
            if (array[left] + array[right] == sum) {
                return vector<int>{array[left], array[right]};
            } else if (array[left] + array[right] > sum) {
                --right;
            } else {
                ++left;
            }
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 4, 7, 11, 15};
    vector<int> ret = solution.FindNumbersWithSum(arr, 15);
    for (auto &val : ret) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}