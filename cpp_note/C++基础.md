#### 1.const关键字与宏定义的区别是什么？

- 编译器处理方式不同，宏定义是在预处理阶段展开，进行简单的字符串替换；const关键字是在编译时
- 类型和安全检查不同，宏定义没有类型，不作任何安全检查；const常量有具体的类型，在编译时会执行类型检查

#### 2.引用与指针的区别是什么？

- 引用是一个变量的别名，可以当做一种被限制的指针，声明引用的同时必须进行初始化，引用一经初始化，不能再改变指向
- 指针存放的是变量的地址，表示指向这个变量

#### 3.malloc的底层实现是怎样的？free是怎么回收内存的？

- malloc ()函数的实质是它有一个将可用的内存块连接为一个长长的列表的所谓空闲链表。 调用 malloc()函数时，它沿着连接表寻找一个大到足以满足用户请求所需要的内存块。 然后，将该内存块一分为二（一块的大小与用户申请的大小相等，另一块的大小就是剩下来的字节）。 接下来，将分配给用户的那块内存存储区域传给用户，并将剩下的那块（如果有的话）返回到连接表上。 调用 free 函数时，它将用户释放的内存块连接到空闲链表上。 到最后，空闲链会被切成很多的小内存片段，如果这时用户申请一个大的内存片段， 那么空闲链表上可能没有可以满足用户要求的片段了。于是，malloc()函数请求延时，并开始在空闲链表上检查各内存片段，对它们进行内存整理，将相邻的小空闲块合并成较大的内存块。
- free() 不会改变指针变量本身的值，调用 free() 后它仍然会指向相同的内存空间，但是此时该内存已无效，不能被使用。

#### 4.new/delete与malloc/free的区别是什么？

- malloc/free是C/C++的标准库函数，new/delete是C++的运算符
- new能够自动分配空间大小，同时还对空间进行初始化；malloc需要传入参数，不能初始化
- new/delete能对对象进行构造和析构函数的调用，进而对内存进行更加详细的工作，而malloc/free不行

#### 5.inline函数与带参数的宏定义的区别？

- 宏定义不可调试，内联函数是可以调试的
- 在调用内联函数时，编译器会进行类型安全检查或自动类型转换，如果正确，内联函数的代码就会直接替换函数调用语句；宏定义不会进行类型安全检查和自动类型转换，无法操作类的私有数据成员

#### 6.C++内存布局分为几个区域，各自具备什么特点？

- 栈区：由编译器自动分配释放，存放函数的参数值，局部变量的值，向下增长
- 堆区：一般由程序员分配释放，若程序员不释放，结束时可能由OS回收，向上增长
- 全局/静态区：存放全局变量和静态变量，在程序编译时分配
- 文字常量区：存放常量字符串
- 程序代码区：存放函数体(普通函数、类的成员函数)的二进制代码

#### 7.什么是浅拷贝, 什么是深拷贝?

- 浅拷贝：对指针变量直接传递地址，造成两个对象的指针都指向了同一块内存，当两个对象释放时，对同一块内存执行了delete操作
- 深拷贝：先为指针变量开辟空间，然后再进行复制，两个对象都有独立的堆空间

#### 8.实现一个自定义的String类，保证main函数对正确执行

```C++
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
    String() : _pstr(nullptr) { cout<<"String()"<<endl; }

    String(const char *pstr)
        : _pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
        cout << "String(const char *pstr)" << endl;
    }
    //拷贝构造函数
    String(const String & rhs)
        :_pstr ( new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
        cout<<"String(const String & rhs)"<<endl;
    }
    //赋值运算符函数
    String & operator=(const String & rhs)
    {
        if(this != &rhs)
        {
            if(_pstr){
                delete [] _pstr;
            }
            _pstr=new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
            cout << "String & operator=(const String & rhs)" << endl;
        }
        return *this;
    }

    ~String()
    {
        if(_pstr)
        {
            delete [] _pstr;
        }
        cout << "~String()" << endl;
    }

    void print()
    {
        if(_pstr){
            cout << _pstr << endl;
        }
    }
private:
    char *_pstr;
};

void test1(void)
{
    String str1;
    cout << "str1:";
    str1.print();
    String str2 = "Hello,world";
    String str3("wangdao");

    cout << "str2:";
    str2.print();       
    cout << "str3:";
    str3.print();   

    String str4 = str3;
    cout << "str4:";
    str4.print();

    str4 = str2;
    cout << "str4:";
    str4.print();
}

int main()
{
    test1();
    return 0;
}
```

