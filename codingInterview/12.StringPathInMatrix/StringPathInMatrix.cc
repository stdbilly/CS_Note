#include <memory.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    bool hasPath(const char* matrix, int rows, int cols, const char* str) {
        if (!matrix || rows < 1 || cols < 1 || !str) return false;
        bool visited[rows * cols];
        memset(visited, 0, rows * cols);
        int pathLen = 0;
        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                cout << "row = " << row << " , col = " << col << endl
                     << "matrix[row*cols + col] = " << matrix[row * cols + col] << ", "
                     << "str[pathLen] = " << str[pathLen] << endl;

                if (hasPathCore(matrix, rows, cols, row, col, str, pathLen,
                                visited)) {
                    return true;
                }
            }
        }
        return false;
    }

   private:
    bool hasPathCore(const char* matrix, int rows, int cols, int row, int col,
                     const char* str, int& pathLen, bool* visited) {
        if (str[pathLen] == '\0') return true;

        bool hasPath = false;
        if (row >= 0 && row < rows && col >= 0 && col < cols &&
            matrix[row * cols + col] == str[pathLen] &&
            !visited[row * cols + col]) {
            ++pathLen;
            visited[row * cols + col] = true;

            hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str,
                                  pathLen, visited) ||
                      hasPathCore(matrix, rows, cols, row - 1, col, str,
                                  pathLen, visited) ||
                      hasPathCore(matrix, rows, cols, row, col + 1, str,
                                  pathLen, visited) ||
                      hasPathCore(matrix, rows, cols, row + 1, col, str,
                                  pathLen, visited);

            if (!hasPath) {
                --pathLen;
                visited[row * cols + col] = false;
                cout << "回到前一个字符" << endl;
                cout << "row = " << row << " , col = " << col << endl
                     << "matrix[row*cols + col] = " << matrix[row * cols + col] << ", "
                     << "str[pathLen + 1] = " << str[pathLen + 1] << endl;
            }
        }

        return hasPath;
    }
};

int main() {
    Solution solution;
    // false
    // const char* matrix = "ABCESFCSADEE";
    // const char* str = "ABCB";
    // true
    const char* matrix = "ABTGCFCSJDEH";
    const char* str = "BFCE";
    cout << solution.hasPath(matrix, 3, 4, str) << endl;
    return 0;
}