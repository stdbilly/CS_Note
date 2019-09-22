#include <stdio.h>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;

const char* intToStr(char buf[], int value) {
    static char digits[19] = {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0',
                              '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    static const char* zero = digits + 9;  // zero 指向'0'

    // works for -2147483648...2147483647
    int i = value;
    char* p = buf;
    do {
        // lsd : least significant digit
        int lsd = i % 10;  // lsd可能小于0
        i /= 10;
        *p++ = zero[lsd];  //下标可能为负
    } while (i != 0);

    if (value < 0) {
        *p++ = '-';
    }
    *p = '\0';
    std::reverse(buf, p);
    return buf;  // p - buf为整数长度
}

int main() {
    char buf[20];
    intToStr(buf, -2147483648);
    cout << buf << endl;
    return 0;
}