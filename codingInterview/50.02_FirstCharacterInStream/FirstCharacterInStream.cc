#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;

//// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
// 字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
// 符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

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