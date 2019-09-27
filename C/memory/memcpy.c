#include <assert.h>
#include <stdio.h>

//方法一:不考虑内存重叠
void *memcpy1(void *dest, const void *src, size_t n) {
    assert(dest && src);

    char *pdest = (char *)dest;
    char *psrc = (char *)src;

    while (n--) {
        *pdest = *psrc;
        ++pdest;
        ++psrc;
    }
    return dest;
}

//方法一:考虑内存重叠
void *memcpy2(void *dest, const void *src, size_t n) {
    assert(dest && src);

    char *pdest = (char *)dest;
    char *psrc = (char *)src;

    //当pdest< psrc时，即pdest的首地址小于psrc的首地址（图1），正序拷贝
    if (pdest < psrc) {
        for (size_t i = 0; i < n; ++i) {
            *pdest = *psrc;
            ++pdest;
            ++psrc;
        }
    } else {
    //当pdest> psrc时，即pdest的首地址大于psrc的首地址（图2），倒叙拷贝
        pdest += n - 1;
        psrc += n - 1;
        for (size_t i = 0; i < n; ++i) {
            *pdest = *psrc;
            --pdest;
            --psrc;
        }
    }
    return dest;
}

void *memmove(void *dest, const void *src, size_t n) {
    assert(dest && src);

    char *pdest = (char *)dest;
    char *psrc = (char *)src;

    if (pdest < psrc) {
        for (size_t i = 0; i < n; ++i) {
            *pdest = *psrc;
            ++pdest;
            ++psrc;
        }
    } else {
        pdest += n - 1;
        psrc += n - 1;
        for (size_t i = 0; i < n; ++i) {
            *pdest = *psrc;
            --pdest;
            --psrc;
        }
    }
    return dest;
}

void test1() {
    char strSrc[] = "Hello World!";
    char strDest[20];
    memcpy1(strDest, strSrc, 4);
    strDest[4] = '\0';
    printf("赋值结果为：%s\n", strDest);
}

void test2() {
    char str[] = "0123456789";
    memcpy2(str, str + 2, 4);
    printf("%s\n", str);

    memcpy2(str, str + 5, 4);
    printf("%s\n", str);
}

int main() {
    test1();
    printf("\n");
    test2();
    return 0;
}
