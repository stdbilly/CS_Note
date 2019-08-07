#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::swap;

template <typename T, typename Compare = std::less<T> >
class HeapSort {
public:
    void heapAdjust(vector<T>& arr, int pos, int arrLen) {
        while(true) {
            int maxPos = pos;
            if(pos * 2 + 1 < arrLen && compare(arr[pos], arr[pos * 2 + 1]))
                maxPos = pos * 2 + 1;
            if(pos * 2 + 2 < arrLen && compare(arr[maxPos], arr[pos * 2 + 2]))
                maxPos = pos * 2 + 2;

            if(maxPos == pos) 
                break;
            swap(arr[pos], arr[maxPos]);
            pos = maxPos;
        }
    }

    bool compare(const T& lhs, const T& rhs, Compare com = Compare()) {
        return com(lhs,rhs);
    }

    void sort(vector<T>& arr) {
        for(int i = arr.size()/2 - 1; i >= 0; --i) {
            heapAdjust(arr, i, arr.size());
        }

        int k = arr.size();
        while(k > 0) {
            swap(arr[0], arr[k-1]);
            --k;
            heapAdjust(arr, 0, k);
        }
    }
};

void test1() {
    vector<int> nums({3,6,2,5,12,4,8,15,11});
    //HeapSort<int> heap;
    HeapSort<int,std::greater<int> > heap;
    heap.sort(nums);
    for(int& i:nums) {
        cout << i << " " ;
    }
    cout << endl;
}

int main() {
    test1();
    return 0;
}

