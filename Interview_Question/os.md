### 主机字节序与网络字节序

#### 主机字节序（CPU 字节序）

主机字节序又叫 CPU 字节序，其不是由操作系统决定的，而是由 CPU 指令集架构决定的。主机字节序分为两种：

- 大端字节序（Big Endian）：高序字节存储在低位地址，低序字节存储在高位地址
- 小端字节序（Little Endian）：高序字节存储在高位地址，低序字节存储在低位地址

32 位整数 `0x12345678` 是从起始位置为 `0x00` 的地址开始存放，则：

| 内存地址 | 0x00 | 0x01 | 0x02 | 0x03 |
| -------- | ---- | ---- | ---- | ---- |
| 大端     | 12   | 34   | 56   | 78   |
| 小端     | 78   | 56   | 34   | 12   |

判断大小端

```C
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
```

#### 网络字节序

网络字节顺序是 TCP/IP 中规定好的一种数据表示格式，它与具体的 CPU 类型、操作系统等无关，从而可以保证数据在不同主机之间传输时能够被正确解释。

网络字节顺序采用：大端（Big Endian）排列方式。