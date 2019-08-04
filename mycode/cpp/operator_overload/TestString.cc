#include "String.h"
#include <iostream>
using std::cout;
using std::endl;

void test1() {
    String s1("hello");
    String s2="world";
    String s3 = s1;
    cout << "s1 == s3 ?" << (s1 == s3) << endl;
    cout << "s1=" << s1 << endl;
    s1 += s2;
    cout << "s1=" << s1 << endl;
    s1 += " wd";
    cout << "s1=" << s1 << endl;
    String s4 = s1 + s2;
    cout << "s4=";
    for(size_t idx = 0; idx != s4.size(); ++idx) {
        cout << s4[idx];
    }
    cout << endl;
    cout << "s1 > s2 ?" << (s1 > s2) << endl;
    String s5;
    std::cin >> s5;
    cout<< "s5=" << s5 << endl;
}

int main() {
    test1();
    return 0;
}

