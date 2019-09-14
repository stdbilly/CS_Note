#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty()) throw std::invalid_argument("empty array");
        int left = 0;
        int right = rotateArray.size() - 1;
        int mid = left;
        while (rotateArray[left] >= rotateArray[right]) {
            // 如果left和right指向相邻的两个数，
            // 则left指向第一个递增子数组的最后一个数字，
            // right指向第二个子数组的第一个数字，也就是数组中的最小数字
            if (right - left == 1) {
                mid = right;
                break;
            }
            mid = (left + right) >> 1;
            //如果left mid right指向的数字相等,则只能顺序查找
            if (rotateArray[left] == rotateArray[mid] &&
                rotateArray[mid] == rotateArray[right])
                return minInOrder(rotateArray, left, right);
            //缩小查找范围
            if (rotateArray[mid] >= rotateArray[left]) {
                left = mid;
            } else if (rotateArray[mid] <= rotateArray[right]) {
                right = mid;
            }
        }

        return rotateArray[mid];
    }

   private:
    int minInOrder(vector<int> arr, int left, int right) {
        int ret = arr[left];
        for (int i = left + 1; i <= right; ++i) {
            if (arr[i] < ret) ret = arr[i];
        }
        return ret;
    }
};

int main() {
    Solution solution;
    vector<int> nums1{ 3, 4, 5, 1, 2 };
    vector<int> nums2{ 1, 0, 1, 1, 1 };
    vector<int> nums3{ 1, 2, 3, 4, 5 };
    cout << solution.minNumberInRotateArray(nums1) << endl;
    cout << solution.minNumberInRotateArray(nums2) << endl;
    cout << solution.minNumberInRotateArray(nums3) << endl;
    return 0;
}