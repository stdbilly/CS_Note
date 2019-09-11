#include "MyUtility.h"
#include <ctime>
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;

int binarySearch(int arr[], int n, int target) {
    int l = 0, r = n - 1;  //在[l...r]寻找target
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            l = mid + 1;  // target在[mid+1...r]中
        } else {
            r = mid - 1;
        }
    }
    return -1;
}

int main() { 
    int n = pow(10, 7);
    int* data = MyUtil::generateOrderedArray(n);

    clock_t startTime = clock();
    for(int i = 0 ; i < n ; i ++)
        assert(i == binarySearch(data, n, i));
    clock_t endTime = clock();

    cout << "Binary Search test complete." << endl;
    cout << "Time cost: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0; }
