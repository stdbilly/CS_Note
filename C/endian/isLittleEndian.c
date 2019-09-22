#include <stdio.h>

union Foo {
    short a;
    char b;
};

int main() {
    //原理：联合体union的存放顺序是所有成员都从低地址开始存放，而且所有成员共享存储空间
    union Foo foo;
    foo.a = 0x1234;
    if (foo.b == 0x34) {  //低地址存放的是低位字节数据
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }

    //方法二
    short num = 0x1234;
    //通过将short(2字节)强制类型转换成char单字节，q指向num的起始字节（低字节）
    char* q = (char*)&num;  
    if (*q = 0x34) {
        printf("little endian\n");
    } else {
        printf("big endian\n");
    }

    return 0;
}