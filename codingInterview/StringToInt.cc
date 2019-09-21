#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Solution {
   public:
    int StrToInt(string str) {
        gStatus = invalid;
        long long num = 0;

        string::iterator cur = str.begin();
        if (!str.empty() && *cur != '\0') {
            bool minus = false;

            if (*cur == '+') {
                ++cur;
            } else if (*cur == '-') {
                ++cur;
                minus = true;
            }

            if (*cur != '\0') {
                num = strToIntCore(cur, minus);
            }
        }

        return (int)num;
    }

   private:
    long long strToIntCore(string::iterator iter, bool minus) {
        long long num = 0;
        while (*iter != '\0') {
            if (*iter >= '0' && *iter <= '9') {
                int flag = minus ? -1 : 1;
                num = num * 10 + flag * (*iter - '0');

                if ((!minus && num > 0x7FFFFFFF) ||
                    (minus && num < (signed int)0x80000000)) {
                    num = 0;
                    break;
                }

                ++iter;
            } else {
                num = 0;
                break;
            }
        }
        if (*iter == '\0') {
            gStatus = valid;
        }

        return num;
    }

   public:
    int gStatus = valid;

   private:
    enum status { valid = 0, invalid };
};

int main() {
    Solution solution;
    string s("-1234");
    cout << solution.StrToInt(s) << endl;
    return 0;
}