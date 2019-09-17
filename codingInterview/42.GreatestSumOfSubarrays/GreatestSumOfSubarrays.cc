#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if (array.empty()) return 0;

        int sum = array[0];
        int max = array[0];
        for (int i = 1; i < array.size(); ++i) {
            if (sum <= 0) {
                sum = array[i];
            } else {
                sum += array[i];
            }

            max = std::max(max, sum);
        }
        return max;
    }
};

int main() {
    Solution solution;
    // 18
    vector<int> arr{1, -2, 3, 10, -4, 7, 2, -5};
    cout << solution.FindGreatestSumOfSubArray(arr) << endl;
    return 0;
}