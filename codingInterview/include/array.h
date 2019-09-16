#pragma once
#include <stdlib.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int randomInRange(int min, int max) {
    int random = rand() % (max -min + 1) + min;
    return random;
}

template <typename T>
int partition(vector<T>& arr, int left, int right) {
    int index = randomInRange(left, right);
    std::swap(arr[index], arr[right]);

    int small = left;
    //选择最后一个元素作为分割点, [left...small)小于分割点
    for (index = left; index < right; ++index) {
        if (arr[index] < arr[right]) {
            if(small != index)
                std::swap(arr[index], arr[small]);
            ++small;
        }
    }
    std::swap(arr[small], arr[right]);
    return small;
}

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}