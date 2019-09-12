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
        //遍历排序区间找到插入位置
        for (; j >= 0; --j) {
            if (arr[j] > insertVal)
                arr[j + 1] = arr[j];  //数据移动
            else
                break;
        }
        arr[j + 1] = insertVal;
    }
}

template <typename T>
void shellSort(vector<T>& arr) {
    //当gap=1时就是插入排序
    for (int gap = arr.size() >> 2; gap > 0; gap >>= 1) {
        for (int i = gap; i < arr.size(); ++i) {
            T insertVal = arr[i];
            int j = i - gap;
            for (; j >= 0 && arr[j] > insertVal; j -= gap) {
                arr[j + gap] = arr[j];
            }
            arr[j + gap] = insertVal;
        }
    }
}

template <typename T>
void merge(vector<T>& arr, int left, int mid, int right) {
    // Array[left...mid] is sorted
    // Array[mid+1 ... right] is sorted
    // Copy Array[front ... mid] to LeftSubArray
    // Copy Array[mid+1 ... right] to RightSubArray
    vector<int> leftSubArr(arr.begin() + left, arr.begin() + mid + 1);
    vector<int> rightSubArr(arr.begin() + mid + 1, arr.begin() + right + 1);
    // display(leftSubArr);
    // display(rightSubArr);
    int idxLeft = 0, idxRight = 0;
    int k = left;
    while (idxLeft < leftSubArr.size() && idxRight < rightSubArr.size()) {
        arr[k++] = leftSubArr[idxLeft] < rightSubArr[idxRight]
                       ? leftSubArr[idxLeft++]
                       : rightSubArr[idxRight++];
    }
    //两个循环只有一个会执行
    while (idxLeft < leftSubArr.size()) {
        arr[k++] = leftSubArr[idxLeft++];
    }

    while (idxRight < rightSubArr.size()) {
        arr[k++] = rightSubArr[idxRight++];
    }
}

template <typename T>
void mergeSortRecursive(vector<T>& arr, int left, int right) {
    if (left >= right) return;
    int mid = left + ((right - left) >> 1);
    mergeSortRecursive(arr, left, mid);
    mergeSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

template <typename T>
int partition(vector<T>& arr, int left, int right) {
    int k = left;
    //选择最后一个元素作为分割点, [left...k)小于分割点
    for (int i = left; i < right; ++i) {
        if (arr[i] < arr[right]) {
            std::swap(arr[i], arr[k]);
            ++k;
        }
    }
    std::swap(arr[k], arr[right]);
    return k;
}

template <typename T>
void quickSort(vector<T>& arr, int left, int right) {
    if (left >= right) return;
    int pivot = partition(arr, left, right);
    quickSort(arr, left, pivot - 1);
    quickSort(arr, pivot + 1, right);
}

void countingSort(vector<int>& arr, int M) {
    vector<int> count(M + 1);
    for (auto& val : arr) {
        ++count[val];
    }
    int k = 0;
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            arr[k] = i;
            ++k;
        }
    }
}

template <typename T, typename Compare = std::less<T>>
void heapify(vector<T>& arr, int pos, int len, Compare comp = Compare()) {
    //从上往下调整为大根堆
    int parent = pos;
    int child = 2 * parent + 1;
    while (child < len) {
        //左子树和右子树最大的与父节点比较
        if (child + 1 < len && comp(arr[child], arr[child + 1])) {
            ++child;
        }
        if (arr[parent] < arr[child]) {
            std::swap(arr[parent], arr[child]);
            parent = child;
            child = 2 * parent + 1;
        } else {
            break;
        }
    }
}

template <typename T>
void heapSort(vector<T>& arr) {
    //建堆
    for (int i = arr.size() / 2 - 1; i >= 0; --i) {
        heapify(arr, i, arr.size());
    }
    int k = arr.size();
    while (k > 1) {
        std::swap(arr[0], arr[k - 1]);
        --k;
        heapify(arr, 0, k);
    }
}
