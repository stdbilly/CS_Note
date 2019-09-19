#include <chrono>
#include "sort.hpp"

void test1(int N, int M) {
    vector<int> arr(N);
    ::srand(::time(NULL));
    for (int i = 0; i < N; ++i) {
        arr[i] = ::rand() % M;
    }
    display(arr);
    auto start = std::chrono::system_clock::now();
    //selectionSort(arr);
    //insertionSort(arr);
    //shellSort(arr);
    //mergeSort<int, std::greater<int>>(arr);
    //mergeSortRecursive(arr, 0, arr.size() - 1);
    //quickSort(arr, 0, arr.size() - 1);
    //countingSort(arr, M);
    heapSort<int, std::greater<int>>(arr);
    auto end = std::chrono::system_clock::now();
    display(arr);
    std::chrono::duration<double> elapsed_seconds = end - start;
    cout << "use time: " << elapsed_seconds.count() << " sec\n";
}

void test2() {
    vector<double> arr{4.6, 5.7, 2.6, 0.4, 3.7, 1.8, 8.9};
    display(arr);
    //selectionSort(arr);
    //insertionSort(arr);
    shellSort(arr);
    display(arr);
}

int main() {
    test1(10, 100);
    //test2();
    return 0;
}
