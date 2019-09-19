#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

class Solution {
   public:
    // Insert one char from stringstream
    void Insert(char ch) {
        ++freq[ch];
        que.push(ch);
        while (!que.empty() && freq[que.front()] > 1) {
            que.pop();
        }
    }
    // return the first appearence once char in current stringstream
    char FirstAppearingOnce() { return que.empty() ? '#' : que.front(); }

   private:
    int freq[256];
    queue<char> que;
};

// ====================测试代码====================
void Test(const char* testName, Solution& solution, char expected) {
    if (testName != nullptr) printf("%s begins: ", testName);

    if (solution.FirstAppearingOnce() == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[]) {
    Solution solution;

    Test("Test1", solution, '#');

    solution.Insert('g');
    Test("Test2", solution, 'g');

    solution.Insert('o');
    Test("Test3", solution, 'g');

    solution.Insert('o');
    Test("Test4", solution, 'g');

    solution.Insert('g');
    Test("Test5", solution, '#');

    solution.Insert('l');
    Test("Test6", solution, 'l');

    solution.Insert('e');
    Test("Test7", solution, 'l');

    return 0;
}