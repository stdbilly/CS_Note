#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
// 找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

class Solution {
   public:
    void FindNumsAppearOnce(vector<int> data, int *num1, int *num2) {
        if (data.size() < 2) return;

        int resultExclusiveOR = 0;
        for (auto &num : data) {
            resultExclusiveOR ^= num;
        }
        // resultExclusiveOR为1的位表示这一位在num1和num2中不同,将num1和num2分开
        unsigned int indexOf1 = findFirstBitIs1(resultExclusiveOR);

        *num1 = *num2 = 0;
        for (auto &val : data) {
            //将所有indexOf1位是1的数相异或,不是1的数相异或
            if (isBit1(val, indexOf1)) {
                *num1 ^= val;
            } else {
                *num2 ^= val;
            }
        }
    }

   private:
    // 找到num从右边数起第一个是1的位
    unsigned int findFirstBitIs1(int num) {
        int indexBit = 0;
        while ((num & 1) == 0 && (indexBit < 8 * sizeof(int))) {
            num >>= 1;
            ++indexBit;
        }
        return indexBit;
    }

    // 判断数字num的第indexBit位是不是1
    bool isBit1(int num, unsigned int indexBit) {
        num >>= indexBit;
        return (num & 1);
    }
};

int main() {
    Solution solution;
    vector<int> arr{2, 4, 3, 6, 3, 2, 5, 5};
    int num1, num2;
    solution.FindNumsAppearOnce(arr, &num1, &num2);
    cout << num1 << " " << num2 << endl;
    return 0;
}