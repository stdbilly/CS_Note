#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
// （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
// 者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
// 算你最多能拿到多少价值的礼物？

class Solution {
   public:
    int getMaxValue(vector<vector<int>>& values) {
        if (values.empty()) return 0;
        
        vector<int> maxValues(values[0].size(), 0);

        for (int i = 0; i < values.size(); ++i) {
            for (int j = 0; j < values[0].size(); ++j) {
                int up = 0;
                int left = 0;
                //[j-1...]保存着i-1行,n-j个格子礼物的最大价值,也就是对应上边格子的最大价值
                if (i > 0) {
                    up = maxValues[j];
                }
                //[0...j]为当前i行前面n个格子礼物的最大价值
                if (j > 0) {
                    left = maxValues[j - 1];
                }

                maxValues[j] = std::max(up, left) + values[i][j];
            }
        }

        // maxValues的最后一个元素就是最大值
        return maxValues[values[0].size() - 1];
    }
};

int main() {
    Solution solution;
    // 29
    vector<vector<int>> values{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    cout << solution.getMaxValue(values) << endl;
    return 0;
}