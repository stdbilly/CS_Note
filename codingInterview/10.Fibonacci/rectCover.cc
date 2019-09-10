#include <iostream>
using std::cout;
using std::endl;

class Solution {
   public:
    int rectCover(int number) {
        if (number <= 2) return number;
        int nMinusTwo = 1;
        int nMinusOne = 2;
        int ret = 0;
        for (int i = 3; i <= number; ++i) {
            ret = nMinusOne + nMinusTwo;
            nMinusTwo = nMinusOne;
            nMinusOne = ret;
        }
        return ret;
    }
};

int main() {
    Solution solution;

    return 0;
}