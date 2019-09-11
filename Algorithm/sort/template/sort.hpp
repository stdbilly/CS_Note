#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

template <typename Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    for (; cit != c.end(); ++cit) {
        cout << *cit << " ";
    }
    cout << endl;
}

template <typename T>
void selectionSort(vector<T>& arr) {
    //[0...i-1]未排序区间
    for (int i = arr.size(); i > 1; --i) {  //外层控制无序数的数目
        int maxPos = 0;
        for (int j = 1; j < i; ++j) {
            if (arr[j] > arr[maxPos]) maxPos = j;
        }
        std::swap(arr[maxPos], arr[i - 1]);  //与未排序区间的最后一个数交换
    }
}

template <typename T>
void insertionSort(vector<T>& arr) {
    //[0...i-1]排序区间
    for (int i = 1; i < arr.size(); ++i) {
        T insertVal = arr[i];
        int j = i - 1;
        for (; j >= 0; --j) {
            if (arr[j] > insertVal)
                arr[j + 1] = arr[j];  //数据移动
            else
                break;
        }
        arr[j + 1] = insertVal;
    }
}
