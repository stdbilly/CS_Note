#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

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
    // string s("I am a student.");
    string s;
    while (getline(cin, s)) {
        cout << solution.ReverseSentence(s) << endl;
    }

    return 0;
}