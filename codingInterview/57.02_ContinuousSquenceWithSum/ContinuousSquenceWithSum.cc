#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    vector<vector<int>> FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        if (sum < 3) {
            return ret;
        }
        int small = 1;
        int big = 2;
        int middle = (1 + sum) >> 1;
        int curSum = small + big;
        while (small < middle) {
            if (curSum == sum) {
                ret.push_back(pushContinuousSequence(small, big));
            }

            while (curSum > sum && small < middle) {
                curSum -= small;
                ++small;

                if (curSum == sum) {
                    ret.push_back(pushContinuousSequence(small, big));
                }
            }
            // curSum < sum
            ++big;
            curSum += big;
        }
        return ret;
    }

   private:
    vector<int> pushContinuousSequence(int small, int big) {
        vector<int> temp;
        for (int i = small; i <= big; ++i) {
            temp.push_back(i);
        }
        return temp;
    }
};

// ====================测试代码====================
template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

void Test(const char* testName, int sum) {
    Solution solution;
    if (testName != nullptr) printf("%s for %d begins: \n", testName, sum);

    vector<vector<int>> ret = solution.FindContinuousSequence(sum);
    for (auto& vec : ret) {
        display(vec);
    }
    cout << endl;
}

int main(int argc, char* argv[]) {
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}