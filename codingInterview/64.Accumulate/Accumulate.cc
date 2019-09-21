#include <iostream>
#include <vector>
#include <functional>
using std::cout;
using std::endl;
using std::vector;

// 面试题64：求1+2+…+n
// 题目：求1+2+…+n，要求不能使用乘除法、for、while、if、else、switch、case
// 等关键字及条件判断语句（A?B:C）。

//方法一: 虚函数
class A;
A* array[2];

class A {
   public:
    virtual int sum(int n) { return 0; }
};

class B : public A {
   public:
    virtual int sum(int n) { return array[!!n]->sum(n - 1) + n; }
};

class Solution {
   public:
    int Sum_Solution(int n) {
        A a;
        B b;
        array[0] = &a;
        array[1] = &b;
        int value = array[1]->sum(n);
        return value;
    }
};

//方法二:函数指针
using func = std::function<int(int)>;

int sumTeminator(int n) {
    return 0;
}

int sum(int n) {
    static func f[2] = {sumTeminator, sum};
    return n + f[!!n](n - 1);
}

class Solution2 {
   public:
    int Sum_Solution(int n) {
        return sum(n);
    }
};

int main() {
    Solution2 solution;
    cout << solution.Sum_Solution(100) << endl;
    return 0;
}