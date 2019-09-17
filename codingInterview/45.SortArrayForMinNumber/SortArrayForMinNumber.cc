#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::ostringstream;
using std::string;
using std::to_string;
using std::vector;

class Solution {
   public:
    string PrintMinNumber(vector<int> numbers) {
        if (numbers.empty()) return "";

        std::sort(numbers.begin(), numbers.end(), compare);
        ostringstream oss;
        for (auto& val : numbers) {
            oss << val;
        }
        return oss.str();
    }

   private:
    static bool compare(const int& lhs, const int& rhs) {
        string lr = to_string(lhs) + to_string(rhs);
        string rl = to_string(rhs) + to_string(lhs);
        return lr < rl;
    }
};

int main() {
    Solution solution;
    vector<int> nums{3, 32, 321};
    cout << solution.PrintMinNumber(nums) << endl;
    return 0;
}