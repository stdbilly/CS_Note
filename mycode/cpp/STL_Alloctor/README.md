## 算法库中有哪些类型的操作？什么是函数对象？

| 类型             | 函数                                                   |
| ---------------- | ------------------------------------------------------ |
| 非修改式序列操作 | `for_each()` `count()` `find()` `search()`             |
| 修改式序列操作   | `copy()` `remove()/remove_if()` `replace()` `swap()`   |
| 排序和相关操作   | `sort()` `partition()` `upper_bound()` `equal_range()` |
| 数字操作         | `itoa()` `accumulate()`                                |

函数对象是可以以函数方式与()结合使用的任意对象，包括：(functor-仿函数)  函数名；指向函数的指针；重载了`operator()`的类对象（即定义了operator()(函数的类）

## 容器、迭代器、算法之间的关系是怎样的？他们是如何结合在一起的？

STL的中心思想在于：将容器和算法分开，彼此独立设计，最后再用迭代器将他们结合在一起，算法通过迭代器存取容器的内容, STL的算法都是通过模板形式实现的，对所有容器都适用，通过迭代器访问容器元素

## 什么是迭代器失效问题？该问题是如何产生的？怎样避免产生迭代器失效问题？

向容器中添加元素和从容器中删除元素的操作可能会使指向容器元素的迭代器失效，一个失效的迭代器将不再表示任何元素。

在remove过程中直接删除元素，可能会导致迭代器范围出现问题。对于vector，在遍历元素的过程中，做了添加元素的操作，如果存储空间被重新分配，会导致底层数据存放的位置反生变化，从而导致迭代器失效的问题。

一般情况下，在遍历元素过程中，不要轻易做添加或删除元素的操作

## 什么是回调函数，注册回调函数，执行回调函数？(掌握std::bind用法,非常重要)

回调函数是指通过函数参数传递到其它代码的，某一块可执行代码的引用，被主调函数调用后会返回主函数。

回调函数的注册是将函数的入口地址赋值给函数指针。

执行回调函数是使用函数指针调用回调函数

## 了解std::allocator的用法之后,实现自定义的Vector类

接口形式： 

```C++
    template<typename T>
    class Vector
    {
    public:
        Vector();
        ~Vector();
    void push_back(const T &); 
    void pop_back();    
    
    int size();
    int capacity();
private:
    void reallocate();//重新分配内存,动态扩容要用的
private:    
    static std::allocator<T> _alloc;
    
    T * _start;      //指向数组中的第一个元素
    T * _finish; //指向最后一个实际元素之后的那个元素
    T * _end_of_storage;        //指向数组本身之后的位置
};

Vector模型
 ______________________________
|_|_|_|_|_|____________________|
 ↑         ↑                    ↑
  _start   _finish            _end_of_storage
```
```C++
#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
using std::cout;
using std::endl;
using std::string;

template <typename T>
class MyVector {
   public:
    using iterator = T*;
    using const_iterator = const T*;

    MyVector() : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

    ~MyVector() {
        if (_start) {
            while (_finish != _start) {
                _alloc.destroy(--_finish);
            }

            _alloc.deallocate(_start, capacity());
        }
    }
    size_t size() const { return _finish - _start; }
    size_t capacity() const { return _end_of_storage - _start; }

    iterator begin() { return _start; }
    iterator end() { return _finish; }

    const_iterator begin() const { return _start; }
    const_iterator end() const { return _finish; }

    void push_back(const T& t);
    void pop_back();

    T& operator[](size_t idx) { return _start[idx]; }

   private:
    void reallocate();

   private:
    static std::allocator<T> _alloc;
    T* _start;
    T* _finish;
    T* _end_of_storage;
};

template <typename T>
std::allocator<T> MyVector<T>::_alloc;

template <typename T>
void MyVector<T>::push_back(const T& t) {
    if (size() == capacity()) {
        reallocate();
    }
    //构造对象
    _alloc.construct(_finish++, t);
}

template <typename T>
void MyVector<T>::pop_back() {
    if (size() > 0) {
        _alloc.destroy(--_finish);
    }
}

template <typename T>
void MyVector<T>::reallocate() {
    size_t capa = capacity();
    size_t newCapa = capa * 2 > 0 ? capa * 2 : 1;
    //开辟新空间
    T* ptmp = _alloc.allocate(newCapa);  //没有任何元素的空间
    if (_start) {
        //这里不能使用copy,其内部会调用赋值运算符，对象存在的的情况下使用
        std::uninitialized_copy(_start, _finish, ptmp);  //内部使用定位new表达式

        //销毁原来空间的对象
        while (_finish != _start) {
            _alloc.destroy(--_finish);
        }
        //回收空间
        _alloc.deallocate(_start, capa);
    }

    _start = ptmp;
    _finish = ptmp + capa;
    _end_of_storage = ptmp + newCapa;
}

template <typename Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

template <typename Container>
void showCapacity(const Container& c) {
    cout << "c.size() = " << c.size() << endl
         << "c.capacity() = " << c.capacity() << endl;
}

void test1() {
    MyVector<string> str;
    showCapacity(str);
    str.push_back("hello");
    str.push_back("world");
    str.push_back("wd");
    str.push_back("shenzhen");
    str.push_back("aaa");
    showCapacity(str);
    display(str);
}

int main() {
    test1();
    return 0;
}
```


