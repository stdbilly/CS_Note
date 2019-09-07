#include <iostream>
using std::cout;
using std::endl;

class Solution {
   public:
    void replaceSpace(char *str, int length) {
        if (str == nullptr || length <= 0) {
            return;
        }

        int originalLen = 0;
        int blankNum = 0;
        int i =0;
        while (str[i] != '\0') {
            ++originalLen;
            if (str[i] == ' ') {
                ++blankNum;
            }
            ++i;
        }

        int newLen = originalLen + 2 * blankNum;
        if (newLen > length) {
            return;
        }

        int indexOfOriginal = originalLen;
        int indexOfNew = newLen;
        while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
            if (str[indexOfOriginal] == ' ') {
                str[indexOfNew--] = '0';
                str[indexOfNew--] = '2';
                str[indexOfNew--] = '%';
            } else {
                str[indexOfNew--] = str[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }
};

int main() {
    Solution solution;
    const int length = 50;
    char str[length] = "We are happy.";
    solution.replaceSpace(str, length);
    cout << str << endl;
    return 0;
}