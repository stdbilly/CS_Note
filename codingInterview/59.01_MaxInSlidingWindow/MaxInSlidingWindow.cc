#include <deque>
#include <iostream>
#include <vector>
using std::cout;
using std::deque;
using std::endl;
using std::vector;

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
// 如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
// 滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

class Solution {
   public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> maxWindow;
        if (num.size() < size || size < 1) {
            return maxWindow;
        }
        //队列中保存数字的小标
        deque<int> index;
        for (unsigned int i = 0; i < size; ++i) {
            //如果index非空,并且新添加的数字大于等于队列中最小的数字,则删除队列中最小的数字
            while (!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            index.push_back(i);
        }

        for (unsigned int i = size; i < num.size(); ++i) {
            maxWindow.push_back(num[index.front()]);

            while (!index.empty() && num[i] >= num[index.back()]) {
                index.pop_back();
            }
            //控制窗口大小为size
            if (!index.empty() && index.front() <= (int)(i - size)) {
                index.pop_front();
            }
            index.push_back(i);
        }
        maxWindow.push_back(num[index.front()]);
        return maxWindow;
    }
};

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

int main() {
    Solution solution;
    vector<int> nums{2, 3, 4, 2, 6, 2, 5, 1};
    vector<int> ret = solution.maxInWindows(nums, 3);
    display(ret);
    return 0;
}