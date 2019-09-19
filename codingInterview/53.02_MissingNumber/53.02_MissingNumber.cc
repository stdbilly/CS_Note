#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
// 都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
// 中，请找出这个数字。

class Solution {
   public:
    int getMissingNumber(vector<int> arr) {
        if (arr.empty()) return -1;
        int left = 0;
        int right = arr.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (arr[mid] != mid) {
                if (mid == 0 || arr[mid - 1] == mid - 1) {
                    return mid;
                } else {
                    right = mid - 1;
                }
            } else {
                left = mid + 1;
            }
        }

        if (left == arr.size()) {
            return left;
        }
        return -1;
    }
};

int main() {
    Solution solution;
    vector<int> arr{0, 1, 2, 4, 5};
    cout << solution.getMissingNumber(arr) << endl;
    return 0;
}