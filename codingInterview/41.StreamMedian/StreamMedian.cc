#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using std::priority_queue;
using std::cout;
using std::endl;
using std::vector;

// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
// 中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
// 那么中位数就是所有数值排序之后中间两个数的平均值。

class Solution {
   public:
    void Insert(int num) {
        if ((getSize() & 1) == 0) {
            if (max.size() > 0 && num < max[0]) {
                max.push_back(num);
                std::push_heap(max.begin(), max.end());
                num = max[0];                           //取出堆顶元素
                std::pop_heap(max.begin(), max.end());  //将堆顶元素移动到尾部
                max.pop_back();  //真正移除堆顶元素(尾部元素)
            }

            min.push_back(num);
            std::push_heap(min.begin(), min.end(), std::greater<int>());
        } else {
            if (min.size() > 0 && num > min[0]) {
                min.push_back(num);
                std::push_heap(min.begin(), min.end(), std::greater<int>());
                num = min[0];
                std::pop_heap(min.begin(), min.end(), std::greater<int>());
                min.pop_back();
            }
            max.push_back(num);
            std::push_heap(max.begin(), max.end());
        }
    }

    double GetMedian() {
        size_t size = getSize();
        if (size == 0) throw std::invalid_argument("No solution are available");

        double median = 0.0;
        if (size & 1) {
            median = (double)min[0];
        } else {
            median = (double)(min[0] + max[0]) / 2;
        }
        return median;
    }

   private:
    size_t getSize() { return min.size() + max.size(); }

   private:
    vector<int> min;  //最小堆,最小堆中的元素都大于最大堆
    vector<int> max;  //最大堆
};

//使用priority_queue
class Solution2 {
   public:
    void Insert(int num) {
        if ((getSize() & 1) == 0) {
            if (max.size() > 0 && num < max.top()) {
                max.push(num);
                num = max.top();                           //取出堆顶元素
                max.pop();  //移除堆顶元素(尾部元素)
            }

            min.push(num);
        } else {
            if (min.size() > 0 && num > min.top()) {
                min.push(num);
                num = min.top();
                min.pop();
            }
            max.push(num);
        }
    }

    double GetMedian() {
        size_t size = getSize();
        if (size == 0) throw std::invalid_argument("No solution are available");

        double median = 0.0;
        if (size & 1) {
            median = (double)min.top();
        } else {
            median = (double)(min.top() + max.top()) / 2;
        }
        return median;
    }

   private:
    size_t getSize() { return min.size() + max.size(); }

   private:
    priority_queue<int, vector<int>, std::greater<int>> min;  //最小堆,最小堆中的元素都大于最大堆
    priority_queue<int> max;  //最大堆
};

// ====================测试代码====================
void Test(char* testName, Solution2& solution, double expected) {
    if (testName != nullptr) printf("%s begins: ", testName);

    if (abs(solution.GetMedian() - expected) < 0.0000001)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

int main(int argc, char* argv[]) {
    Solution2 solution;

    printf("Test1 begins: ");
    try {
        solution.GetMedian();
        printf("FAILED.\n");
    } catch (const std::exception&) {
        printf("Passed.\n");
    }

    solution.Insert(5);
    Test("Test2", solution, 5);

    solution.Insert(2);
    Test("Test3", solution, 3.5);

    solution.Insert(3);
    Test("Test4", solution, 3);

    solution.Insert(4);
    Test("Test6", solution, 3.5);

    solution.Insert(1);
    Test("Test5", solution, 3);

    solution.Insert(6);
    Test("Test7", solution, 3.5);

    solution.Insert(7);
    Test("Test8", solution, 4);

    solution.Insert(0);
    Test("Test9", solution, 3.5);

    solution.Insert(8);
    Test("Test10", solution, 4);

    return 0;
}