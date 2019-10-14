#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
// 'b'。

class Solution {
   public:
    int FirstNotRepeatingChar(string str) {
        if (str.empty()) return -1;

        int freq[256] = {0};
        for (auto& c : str) {
            ++freq[c];
        }
        for (int i = 0; i < str.size(); ++i) {
            if (freq[str[i]] == 1) return i;
        }
        return -1;
    }
};

// ====================测试代码====================
void Test(string str, int expected) {
    Solution solution;
    if (solution.FirstNotRepeatingChar(str) == expected)
        printf("Test passed.\n");
    else
        printf("Test failed.\n");
}

int main(int argc, char* argv[]) {
    // 常规输入测试，存在只出现一次的字符
    Test("google", 4);

    // 常规输入测试，不存在只出现一次的字符
    Test("aabccdbd", -1);

    // 常规输入测试，所有字符都只出现一次
    Test("abcdefg", 0);

    // 鲁棒性测试，输入空串
    Test("", -1);

    return 0;
}