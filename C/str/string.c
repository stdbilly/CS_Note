#include "string.h"
#include <assert.h>

int myStrlen(const char* str) {
    assert(str != NULL);

    int length = 0;
    while ((*str++) != '\0') {
        ++length;
    }
    return length;
}

int myStrcmp(const char* str1, const char* str2) {
    assert(str1 != NULL && str2 != NULL);

    int ret = 0;
    //当str1和str2相等时循环继续
    while (!(ret = *(unsigned char*)str1 - *(unsigned char*)str2) && *str1) {
        ++str1;
        ++str2;
    }
    if (ret < 0) {
        ret = -1;
    } else if (ret > 0) {
        ret = 1;
    }
    return ret;
}

char* myStrcat(char* to, const char* from) {
    assert(to != NULL && from != NULL);

    char* dest = to;
    while (*to) {
        ++to;
    }
    while (*to++ = *from++);
    return dest;
}

char* myStrcpy(char* to, const char* from) {
    assert(to != NULL && from != NULL);
    char* dest = to;
    while ((*to++ = *from++) != '\0');
    return dest;
}