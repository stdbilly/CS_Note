#include <memory.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int movingCount(int threshold, int rows, int cols) {
        if (threshold < 0 || rows < 1 || cols < 1) return 0;

        bool visited[rows * cols];
        memset(visited, 0, rows * cols);
        
        int count = movingCountCore(threshold, rows, cols, 0, 0, visited);

        return count;
    }

   private:
    int movingCountCore(int threshold, int rows, int cols, int row, int col,
                        bool* visited) {
        int count = 0;
        if (check(threshold, rows, cols, row, col, visited)) {
            visited[row*cols + col] = true;

            count =
                1 +
                movingCountCore(threshold, rows, cols, row, col - 1, visited) +
                movingCountCore(threshold, rows, cols, row - 1, col, visited) +
                movingCountCore(threshold, rows, cols, row, col + 1, visited) +
                movingCountCore(threshold, rows, cols, row + 1, col, visited);
        }
        return count;
    }

    bool check(int threshold, int rows, int cols, int row, int col,
               bool* visited) {
        if (row >= 0 && row < rows && col >= 0 && col < cols &&
            getDigitSum(row) + getDigitSum(col) <= threshold &&
            !visited[row * cols + col]) {
            return true;
        }
        return false;
    }

    int getDigitSum(int number) {
        int sum = 0;
        while (number > 0) {
            sum += number % 10;
            number /= 10;
        }
        return sum;
    }
};

int main() {
    Solution solution;
    //21
    cout << solution.movingCount(5, 10, 10) << endl;
    return 0;
}