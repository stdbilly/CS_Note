#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int NumberOf1(int n) {
        int count = 0;
        while (n) {
            ++count;
            //把最右边的1变为0
            n &= (n - 1);
        }
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.NumberOf1(11) << endl;
    cout << solution.NumberOf1(0xFFFFFFFF) << endl;
    return 0;
}