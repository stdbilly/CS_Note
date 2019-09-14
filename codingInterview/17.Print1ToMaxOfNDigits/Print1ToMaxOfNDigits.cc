#include <memory.h>
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Solution {
   public:
    //方法1: 用字符串表示数
    void Print1ToMaxOfNDigits_1(int n) {
        if (n < 0) return;

        char number[n + 1];
        memset(number, '0', n);

        while (!increment(number)) {
            printNumber(number);
        }
    }

    //方法2: 全排列
    void Print1ToMaxOfNDigits_2(int n) {
        if (n < 0) return;
        char number[n + 1];
        number[n] = '\0';

        for (int i = 0; i < 10; ++i) {
            number[0] = i + '0';
            Print1ToMaxOfNDigitsRecursively(number, n, 0);
        }
    }

   private:
    bool increment(char* number) {
        bool isOverFlow = false;
        int nTakeOver = 0;
        int nLength = strlen(number);
        //从最后一位开始加1, 如果有进位继续向前加, 在第一位产生进位则停止加1
        for (int i = nLength - 1; i >= 0; --i) {
            int nSum = number[i] - '0' + nTakeOver;
            //在最后一位加+1
            if (i == nLength - 1) {
                ++nSum;
            }

            if (nSum >= 10) {
                if (i == 0)
                    isOverFlow = true;
                else {
                    nSum -= 10;
                    nTakeOver = 1;
                    number[i] = '0' + nSum;
                }

            } else {
                number[i] = '0' + nSum;
                break;
            }
        }
        return isOverFlow;
    }

    //打印数字并忽略开头的0
    void printNumber(char* number) {
        bool isBeginning0 = true;
        int nLength = strlen(number);
        for (int i = 0; i < nLength; ++i) {
            if (isBeginning0 && number[i] != '0') {
                isBeginning0 = false;
            }

            if (!isBeginning0) {
                cout << number[i];
            }
        }
        cout << '\t';
    }

    void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index) {
        //递归的终止条件是已设置了最后一位
        if (index == length - 1) {
            printNumber(number);
            return;
        }

        for (int i = 0; i < 10; ++i) {
            number[index + 1] = i + '0';
            Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
        }
    }
};

int main() {
    Solution solution;
    //solution.Print1ToMaxOfNDigits_1(3);
    solution.Print1ToMaxOfNDigits_2(2);
    return 0;
}