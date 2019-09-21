#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    string LeftRotateString(string str, int n) {
        if (n >= str.size() || str.empty() || n <= 0) return str;

        auto firstStart = str.begin();
        auto firstEnd = str.begin() + n - 1;
        auto secondStart = str.begin() + n;
        auto secondEnd = str.end() - 1;
        //翻转字符串前面n个字符
        reverse(firstStart, firstEnd);
        //翻转字符串的后面部分
        reverse(secondStart, secondEnd);
        //翻转整个字符串
        reverse(firstStart, secondEnd);

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
    string s("abcdefg");
    cout << solution.LeftRotateString(s, 2) << endl;
    return 0;
}