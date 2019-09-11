/* 二分查找求一个数的平方根,精确到小数点后 6 位 */
#include <stdio.h>

//精度设置
#define E 0.000001

double mySqrt(double num) {
    double start = 1.0;
    double end = num;
    double mid = 0.0;
    while (1)
    {
        mid = (start + end) / 2;
        if((mid*mid) - num <= E && (mid*mid -num) >= -E) {
            return mid;
        }

        if((mid*mid - num) > E) {
            end = mid;
        } else {
            start = mid;
        }
    }
    return 0;
}

int main() {
    double num = 0.0;
    scanf("%lf", &num);
    printf("\rsqrt(%lf) = %lf\n", num, mySqrt(num));
    return 0;
}