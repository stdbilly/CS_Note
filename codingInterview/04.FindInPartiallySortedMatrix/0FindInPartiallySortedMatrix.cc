#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    bool Find(int target, vector<vector<int>> array) {
        int row = array.size();        //行数
        int column = array[0].size();  //列数
        int j = column - 1, i = 0;
        while (i < row && j >= 0) {
            if (array[i][j] == target) {
                return true;
            } else if (array[i][j] > target) {
                --j;
            } else {
                ++i;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    cout << solution.Find(7, matrix) << endl;
    return 0;
}