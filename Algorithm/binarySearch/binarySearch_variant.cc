#include <cmath>
#include <ctime>
#include <iostream>
using std::cout;
using std::endl;

//变体一: 查找第一个等于给定值的元素
int binarySearch_1(int arr[], int size, int target) {
    int l = 0, r = size - 1;  //在[l...r]寻找target
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (arr[mid] > target) {
            r = mid - 1;
        } else if (arr[mid] < target) {
            l = mid + 1;  // target在[mid+1...r]中
        } else {
            if (mid == 0 || arr[mid - 1] != target)
                return mid;
            else
                r = mid - 1;
        }
    }
    return -1;
}

//变体二：查找最后一个值等于给定值的元素
int binarySearch_2(int arr[], int size, int target) {
    int l = 0, r = size - 1;  //在[l...r]寻找target
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (arr[mid] > target) {
            r = mid - 1;
        } else if (arr[mid] < target) {
            l = mid + 1;  // target在[mid+1...r]中
        } else {
            if (mid == size - 1 || arr[mid + 1] != target)
                return mid;
            else
                l = mid + 1;
        }
    }
    return -1;
}

//变体三：查找第一个大于等于给定值的元素
int binarySearch_3(int arr[], int size, int target) {
    int l = 0, r = size - 1;  //在[l...r]寻找target
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (arr[mid] >= target) {
            if (mid == 0 || arr[mid - 1] < target)
                return mid;
            else
                r = mid - 1;
        } else {
            l = mid + 1;  // target在[mid+1...r]中
        }
    }
    return -1;
}

//变体四：查找最后一个小于等于给定值的元素
int binarySearch_4(int arr[], int size, int target) {
    int l = 0, r = size - 1;  //在[l...r]寻找target
    int mid = 0;
    while (l <= r) {
        mid = l + ((r - l) >> 1);

        if (arr[mid] > target) {
            r = mid - 1;
        } else {
            if (mid == size - 1 || arr[mid + 1] > target)
                return mid;
            else
                l = mid + 1;  // target在[mid+1...r]中
        }
    }
    return -1;
}

int main() {
    int a[10] = {5, 6, 6, 9, 10, 11, 11, 22, 33, 33};
    int data = 0;
    int i = 0;
    int res = 0;

    printf("\r\n");
    for (i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\r\n");
    printf("\r\n输入一个整数");
    scanf("%d", &data);
    res = binarySearch_1(a, 10, data);
    printf("第一个等于data[%d]，下标是%d", data, res);

    printf("\r\n输入一个整数");
    scanf("%d", &data);
    res = binarySearch_2(a, 10, data);
    printf("最后一个等于data[%d]，下标是%d", data, res);

    printf("\r\n输入一个整数");
    scanf("%d", &data);
    res = binarySearch_3(a, 10, data);
    printf("第一个大于等于data[%d]，下标是%d", data, res);

    printf("\r\n输入一个整数");
    scanf("%d", &data);
    res = binarySearch_4(a, 10, data);
    printf("最后一个小等于data[%d]，下标是%d", data, res);
    return 0;
}
