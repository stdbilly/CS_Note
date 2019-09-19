#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int FindNumberAppearingOnce(vector<int>& arr) {
        if (arr.empty()) {
            throw std::invalid_argument("invalid input");
        }
        int bitSum[32] = {0};
        for (auto& num : arr) {
            int bitMask = 1;
            //将所有数字的每一位加起来
            for (int j = 31; j >= 0; --j) {
                int bit = num & bitMask;
                if (bit != 0) {
                    bitSum[j] += 1;
                }
                bitMask <<= 1;
            }
        }
        int result = 0;
        for (int i = 0; i < 32; ++i) {
            result <<= 1;
            //出现一次数字的这一位如果是1,不能被3整除
            result += bitSum[i] % 3;
        }
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 1, 2, 2, 2, 1, 3};
    cout << solution.FindNumberAppearingOnce(arr) << endl;
    return 0;
}