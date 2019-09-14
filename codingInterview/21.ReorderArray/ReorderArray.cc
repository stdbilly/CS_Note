#include <functional>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    void reOrderArray(vector<int>& array) {
        reorder(array,
                std::bind(&Solution::isEven, this, std::placeholders::_1));
    }

    //方法2: 不改变数组顺序
    void reOrderArray2(vector<int>& array) {
        vector<int> odd;
        vector<int> even;
        for (auto& i : array) {
            if (i & 1)
                odd.push_back(i);
            else
                even.push_back(i);
        }
        std::swap(array, odd);
        array.insert(array.end(), even.begin(), even.end());
    }

   private:
    void reorder(vector<int>& arr, std::function<bool(int)> isEven) {
        if (arr.empty()) return;

        int left = 0, right = arr.size() - 1;
        while (left < right) {
            //向后移动left, 直到arr[left]为偶数
            while (left < right && !isEven(arr[left])) {
                ++left;
            }

            //向前移动right, 直到rr[right]为奇数
            while (left < right && isEven(arr[right])) {
                --right;
            }

            if (left < right) {
                std::swap(arr[left], arr[right]);
            }
        }
    }

    bool isEven(int num) { return (num & 1) == 0; }
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
    vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8};
    solution.reOrderArray2(arr);
    display(arr);
    return 0;
}