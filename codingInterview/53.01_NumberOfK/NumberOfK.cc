#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
// 3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

class Solution {
   public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty()) return 0;

        int number = 0;
        int first = getFirstK(data, k);
        int last = getLastK(data, k);
        if (first != -1 && last != -1) {
            number = last - first + 1;
        }
        return number;
    }

   private:
    //找到数组中第一个k的下标,如果数组中不存在k返回-1
    int getFirstK(vector<int> data, int k) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = start + ((end - start) >> 1);
            if (data[mid] == k) {
                if ((mid > 0 && data[mid - 1] != k) || mid == 0) {
                    return mid;
                } else {
                    end = mid - 1;
                }
            } else if (data[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }

    //找到数组中最后一个k的下标,如果数组中不存在k返回-1
    int getLastK(vector<int> data, int k) {
        int start = 0;
        int end = data.size() - 1;
        while (start <= end) {
            int mid = start + ((end - start) >> 1);
            if (data[mid] == k) {
                if ((mid < data.size() - 1 && data[mid + 1] != k) ||
                    mid == data.size() - 1) {
                    return mid;
                } else {
                    start = mid + 1;
                }
            } else if (data[mid] > k) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    };
};

int main() {
    Solution solution;
    vector<int> data{1, 2, 3, 3, 3, 3, 4, 5};
    cout << solution.GetNumberOfK(data, 3) << endl;
    return 0;
}