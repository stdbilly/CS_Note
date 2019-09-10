#include <iostream>
using std::cout;
using std::endl;

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。
class Solution {
   public:
    int getDuplication(const int* nums, int length) {
        if (!nums || length <= 0) return -1;
        int start = 1;
        int end = length - 1;
        while (start <= end) {
            int middle = start + ((end - start) >> 1);
            int count = countRange(nums, length, start, middle);
            if (start == end) {
                if (count > 1)
                    return start;
                else
                    break;
            }

            if (count > (middle - start + 1)) {
                end = middle;
            } else {
                start = middle + 1;
            }
        }
        return -1;
    }

   private:
    int countRange(const int* nums, int length, int start, int end) {
        int count = 0;
        for (int i = 0; i < length; ++i) {
            if (nums[i] >= start && nums[i] <= end) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution solution;
    int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
    cout << solution.getDuplication(numbers, sizeof(numbers) / sizeof(int)) << endl;
    return 0;
}