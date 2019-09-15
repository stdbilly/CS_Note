#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    vector<int> printMatrix(vector<vector<int>> matrix) {
        vector<int> ret;
        int startX = 0, endX = matrix[0].size() - 1;
        int startY = 0, endY = matrix.size() - 1;

        while (startX <= endX && startY <= endY) {
            //从左到右
            for (int i = startX; i <= endX; ++i) {
                ret.push_back(matrix[startY][i]);
            }
            //从上到下
            for (int i = startY + 1; i <= endY; ++i) {
                ret.push_back(matrix[i][endX]);
            }
            //从右到左
            if (startY != endY) {
                for (int i = endX - 1; i >= startX; --i) {
                    ret.push_back(matrix[endY][i]);
                }
            }
            //从下到上
            if (startX != endX) {
                for (int i = endY - 1; i >= startY + 1; --i) {
                    ret.push_back(matrix[i][startX]);
                }
            }

            ++startX;
            ++startY;
            --endX;
            --endY;
        }
        return ret;
    }
};

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

int main() {
    Solution solution;
    /*
    1    2    3    4
    5    6    7    8
    9    10   11   12
    13   14   15   16
    */
    vector<vector<int>> matrix{
        {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<int> ret = solution.printMatrix(matrix);
    display(ret);
    return 0;
}