#include "string.h"

int main() {
    char str1[20] = "hello";
    char str2[20] = "world";
    printf("str1 len = %d\n", myStrlen(str1));
    printf("str1 > str2 ? %d\n", myStrcmp(str1, str2));
    myStrcat(str1, str2);
    printf("str1 = %s\n", str1);
    myStrcpy(str1, str2);
    printf("str1 = %s\n", str1);
    return 0;
}