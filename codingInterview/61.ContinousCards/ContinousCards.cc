#include <algorithm>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
// 2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

class Solution {
   public:
    bool IsContinuous(vector<int> numbers) {
        if (numbers.empty()) return false;

        std::sort(numbers.begin(), numbers.end());

        int numberOfZero = 0;
        int numberOfGap = 0;
        //统计0的个数
        for (int i = 0; i < numbers.size() && numbers[i] == 0; i++) {
            ++numberOfZero;
        }
        //统计间隔的个数
        int small = numberOfZero;
        int big = small + 1;
        while (big < numbers.size()) {
            //有对子,不可能是顺子
            if (numbers[small] == numbers[big]) {
                return false;
            }

            numberOfGap += numbers[big] - numbers[small] - 1;
            small = big;
            ++big;
        }

        return numberOfGap > numberOfZero ? false : true;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 3, 0, 5, 0};
    cout << solution.IsContinuous(nums) << endl;
    return 0;
}