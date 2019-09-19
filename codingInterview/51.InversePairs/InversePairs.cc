#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
// 成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

class Solution {
   public:
    int InversePairs(vector<int> data) {
        tempArr.resize(data.size());
        mergeSort(data, 0, data.size() - 1);
        return count % 1000000007;
    }

   private:
    void mergeSort(vector<int>& arr, int start, int end) {
        if (start >= end) return;
        int mid = start + ((end - start) >> 1);

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }

    void merge(vector<int>& arr, int start, int mid, int end) {
        int idxLeft = start, idxRight = mid + 1;
        for (int k = start; k <= end; ++k) {
            if (idxLeft > mid) {
                tempArr[k] = arr[idxRight];
                ++idxRight;
            } else if (idxRight > end) {
                tempArr[k] = arr[idxLeft];
                ++idxLeft;
            } else if (arr[idxLeft] <= arr[idxRight]) {
                tempArr[k] = arr[idxLeft];
                ++idxLeft;
            } else {
                tempArr[k] = arr[idxRight];
                ++idxRight;
                // arr[idxLeft] > arr[idxRight]，说明 arr[idxLeft...mid] 都大于arr[idxRight]
                count += mid - idxLeft + 1;
            }
        }

        for (int i = start; i <= end; i++) {
            arr[i] = tempArr[i];
        }
    }

   private:
    long count;
    vector<int> tempArr;
};

int main() {
    Solution solution;
    // vector<int> arr{1,2,3,4,5,6,7,0};
    vector<int> arr{364, 637, 341, 406, 747, 995, 234, 971, 571, 219, 993, 407,
                    416, 366, 315, 301, 601, 650, 418, 355, 460, 505, 360, 965,
                    516, 648, 727, 667, 465, 849, 455, 181, 486, 149, 588, 233,
                    144, 174, 557, 67,  746, 550, 474, 162, 268, 142, 463, 221,
                    882, 576, 604, 739, 288, 569, 256, 936, 275, 401, 497, 82,
                    935, 983, 583, 523, 697, 478, 147, 795, 380, 973, 958, 115,
                    773, 870, 259, 655, 446, 863, 735, 784, 3,   671, 433, 630,
                    425, 930, 64,  266, 235, 187, 284, 665, 874, 80,  45,  848,
                    38,  811, 267, 575};
    cout << solution.InversePairs(arr) << endl;
    return 0;
}