#include <math.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    //动态规划
    int cutRope1(int length) {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;

        int products[length + 1];
        products[0] = 0;
        products[1] = 1;
        products[2] = 2;
        products[3] = 3;

        int max = 0;
        for (int i = 4; i <= length; ++i) {
            max = 0;
            for (int j = 1; j <= i / 2; ++j) {
                int product = products[j] * products[i - j];
                if (max < product) max = product;
            }
            products[i] = max;
        }
        return products[length];
    }

    int cutRope2(int length) {
        if (length < 2) return 0;
        if (length == 2) return 1;
        if (length == 3) return 2;

        //尽可能减去长度为3的绳子段
        int timesOf3 = length / 3;

        // 当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段。
        // 此时更好的方法是把绳子剪成长度为2的两段，因为2*2 > 3*1。
        if (length - timesOf3 * 3 == 1) {
            --timesOf3;
        }

        int timesOf2 = (length - timesOf3 * 3) / 2;
        return (int)pow(3, timesOf3) * (int)pow(2, timesOf2);
    }
};

int main() {
    Solution solution;
    cout << solution.cutRope1(8) << endl;
    cout << solution.cutRope2(8) << endl;
    return 0;
}