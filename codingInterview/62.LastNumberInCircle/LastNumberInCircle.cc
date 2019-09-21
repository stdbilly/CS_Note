#include <iostream>
#include <list>
#include <vector>
using std::cout;
using std::endl;
using std::list;
using std::vector;

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
// 删除第m个数字。求出这个圆圈里剩下的最后一个数字。

class Solution {
   public:
    int LastRemaining_Solution(int n, int m) {
        if (n < 1 || m < 1) return -1;

        list<int> numbers;
        for (int i = 0; i < n; ++i) {
            numbers.push_back(i);
        }
        list<int>::iterator current = numbers.begin();

        while (numbers.size() > 1) {
            for (int i = 1; i < m; ++i) {
                ++current;
                if (current == numbers.end()) {
                    current = numbers.begin();
                }
            }

            list<int>::iterator next = ++current;
            if (next == numbers.end()) {
                next = numbers.begin();
            }
            --current;
            numbers.erase(current);
            current = next;
        }

        return *current;
    }
};

int main() {
    Solution solution;
    cout << solution.LastRemaining_Solution(5, 3) << endl;
    return 0;
}