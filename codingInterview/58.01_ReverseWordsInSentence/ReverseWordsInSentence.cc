#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
// 为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
// 则输出"student. a am I"。

class Solution {
   public:
    string ReverseSentence(string str) {
        if (str.empty()) return "";
        //翻转整个句子
        reverse(str.begin(), str.end() - 1);
        //翻转每个单词
        auto beg = str.begin();
        auto end = str.begin();
        while (end < str.end()) {
            if (end == str.end() - 1) {
                reverse(beg, end);
            } else if (*end == ' ') {
                reverse(beg, end - 1);
                ++end;
                beg = end;
            }
            ++end;
        }
        return str;
    }

   private:
    void reverse(string::iterator begin, string::iterator end) {
        while (begin < end) {
            std::swap(*begin, *end);
            ++begin;
            --end;
        }
    }
};

int main() {
    Solution solution;
    string s("I am a student.");
    cout << solution.ReverseSentence(s) << endl;
    return 0;
}