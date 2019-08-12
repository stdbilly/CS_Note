## C++11为什么要引入右值引用？

临时对象的构造和析构带来了不必要的资源拷贝，临时对象拷贝后就立即被销毁了。在旧C++标准中，没有直接的方法移动对象，即使不比拷贝对象的情况下，也不得不拷贝。如果对象较大，或者对象本身要求分配内存空间（如string），进行不必要的拷贝代价非常高。在这些情况下移动而非拷贝对象会大幅度提升性能。

C++11之前，没有语法规则能直接识别出临时对象，只有const引用能够绑定到临时对象(右值)，const引用又能绑定到左值 （const引用是一个万能引用），当const引用作为参数时，无法识别出传递过来的是左值还是右值

右值引用可以在语法层面识别出临时对象，在使用临时对象构造新对象（拷贝构造）的时候，将临时对象所持有的资源转移到新的对象中，就能消除这种不必要的拷贝。当自定义类型定义了移动构造函数和移动赋值运算符函数，传递临时对象(右值)时，具有移动语义的函数会优先调用

## 为深拷贝的String类添加移动构造函数和移动赋值运算符函数

String(String &&rhs);
String & operator=(String &&rhs);

```C++
#include <string.h>
#include <iostream>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
using std::ostream;

class String {
public:
    String():_pstr(new char[1]()) {
        cout<<"String()"<<endl;
    }

    ~String() {
        if(_pstr) {
            delete [] _pstr;
        }
        cout<<"~String()"<<endl;
    }

    String(const char *pstr) 
        : _pstr(new char[strlen(pstr)+1]()) {
            strcpy(_pstr,pstr);
            cout<<"String(const char *)"<<endl;
        }
    
    String(const String& rhs) 
        : _pstr(new char[strlen(rhs._pstr)+1]()) {
            strcpy(_pstr,rhs._pstr);
            cout<<"String(const String& rhs)"<<endl;
        }
    //具有移动语义的函数的执行要优先于具有复制控制语义的函数
    //移动构造函数
    String(String&& rhs) //右值引用本身代表左值
        : _pstr(rhs._pstr) { //使用浅拷贝，完成转移
            rhs._pstr = nullptr;
            cout<<"String(String&& rhs)"<<endl;
        }
    
    String & operator=(const String &rhs) {
        if(this != &rhs) { //避免自复制
            delete [] _pstr; //回收左操作数空间
            _pstr = new char[strlen(rhs._pstr)+1](); //深拷贝
            strcpy(_pstr,rhs._pstr);
        }
        cout<<"String &operator=(const String &)"<<endl;
        return *this;
    }
    //移动赋值函数
    String & operator=(String&& rhs) {
        if(this != &rhs) {
            delete [] _pstr;
            _pstr = rhs._pstr;
            rhs._pstr = nullptr;
        }
        cout<<"String &operator=(String &&)"<<endl;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const String& s);

private:
    char* _pstr;
};

ostream& operator<<(ostream& os, const String& s) {
    os << s._pstr;
    return os;
}

/*当函数的返回值是对象时，如果返回的对象是一个局部（即将被销毁的）对象，
 * 执行return语句时，会调用移动构造函数；
 * 当返回的对象的生命周期大于函数时，执行return语句时，会调用复制构造函数
 */
String getString() {
    String s("hello,world");
    cout << "s = " << s << endl;
    return s;
}

void test2() {
    getString();
}

void test1() {
    String s1("hello");
    s1 = String("shenzhen");
    cout << "s1 = " << s1 << endl;
    vector<String> strs;
    strs.push_back("world");
    cout << "strs[0] = " << strs[0] << endl;
    String s2 = "wangdao";
    s1 = std::move(s2); //std::move将左值引用转换为右值引用,本质上是一个强制转换
    cout << "s1 = " << s1 << endl;
}

int main() {
    test2();
    return 0;
}
```

## std::move的作用是什么？

std::move将左值引用转换为右值引用,本质上是一个强制转换

## 智能指针的实现原理是什么？

资源管理的技术: RAII(Resource Acquisition Is Initialization)

特征: 

- 当申请资源时，用对象托管资源
- 当对象销毁时，释放资源
- 一般情况下，表达对象语义(不能进行复制或赋值)
- 提供若干访问资源的方法

使用存储指向动态分配（堆）对象指针的类来管理资源，资源获得的同时构造对象，在对象生存期间，资源一直保持有效；对象析构时，释放资源

## C++提供了哪几种智能指针，其各自的特点是什么？

- auto_ptr：在构造时获取对某个对象的所有权(ownership),在析构时释放该对象

  在拷贝构造或赋值操作时,会发生所有权的转移，不是真正的复制或赋值操作。该指针存在缺陷，所以不再使用

- unique_ptr：是一个独享所有权的智能指针

  一个unique_ptr拥有它所指向的对象，不支持复制、赋值操作，可以调用release或reset将指针的所有权从一个（非const）的unique_ptr转移给另一个unique_ptr

  具有移动(std::move)语义，内部定义了移动构造函数和移动赋值函数，可做为容器元素

  可以自定义删除器

- shared_ptr：是一个具有引用计数智能指针，用于共享对象的所有权

  引进了一个计数器shared_count,用来表示当前有多少个智能指针对象共享指针指向的内存块

  shared_ptr的析构函数会递减它所指向对象的引用计数。如果引用计数变为0，shared_ptr的析构函数就会销毁对象，并释放它占用的内存

  复制构造与赋值操作符只是提供一般意义上的复制功能,并且将引用计数加1，给shared_ptr赋予一个新值，计数器会递减

- weak_ptr：是一种不控制所指向对象生存期的智能指针，它指向由一个shared_ptr管理的对象。

  将一个weak_ptr绑定到一个shared_ptr不会改变shared_ptr的引用计数。

  通过weak_ptr访问对象时，必须调用lock，此函数检查weak_ptr指向的对象是否仍存在。如果存在，lock返回一个指向共享对象的shared_ptr

