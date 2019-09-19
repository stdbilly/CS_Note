#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
// 现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
// 1, 3, 5}中，数字3和它的下标相等。

class Solution {
   public:
    int getNumSameAsIndex(vector<int> arr) {
        if (arr.empty()) return 0;

        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] == mid) {
                return mid;
            } else if (arr[mid] > mid) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> arr{-3, -1, 1, 3, 5};
    cout << solution.getNumSameAsIndex(arr) << endl;
    return 0;
}