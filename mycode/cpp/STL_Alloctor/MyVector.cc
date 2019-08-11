#include <iostream>
#include <memory>
#include <algorithm>
#include <string>
using std::string;
using std::cout;
using std::endl;

template<typename T>
class MyVector {
public:
    using iterator = T*;
    using const_iterator = const T*;

    MyVector() 
        :_start(nullptr)
        ,_finish(nullptr)
        ,_end_of_storage(nullptr) {}

    ~MyVector() {
        if(_start) {
            while(_finish != _start) {
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

    T& operator[](size_t idx) {
        return _start[idx];
    }
private:
    void reallocate();
private:
    static std::allocator<T> _alloc;
    T* _start;
    T* _finish;
    T* _end_of_storage;
};

template<typename T>
std::allocator<T> MyVector<T>::_alloc;

template<typename T>
void MyVector<T>::push_back(const T& t) {
    if(size() == capacity()) {
        reallocate();
    }
    //构造对象
    _alloc.construct(_finish++, t);
}

template<typename T>
void MyVector<T>::pop_back() {
    if(size() > 0) {
        _alloc.destroy(--_finish);
    }
}

template<typename T>
void MyVector<T>::reallocate() {
    size_t capa = capacity();
    size_t newCapa = capa * 2 > 0 ? capa * 2 : 1;
    //开辟新空间
    T* ptmp = _alloc.allocate(newCapa); //没有任何元素的空间
    if(_start) {
        //这里不能使用copy,其内部会调用赋值运算符，对象存在的的情况下使用
        std::uninitialized_copy(_start, _finish, ptmp); //内部使用定位new表达式
        
        //销毁原来空间的对象
        while(_finish != _start) {
            _alloc.destroy(--_finish);
        }
        //回收空间
        _alloc.deallocate(_start, capa);
    }

    _start = ptmp;
    _finish = ptmp + capa;
    _end_of_storage = ptmp + newCapa;
}

template<typename Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while(cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
}

template<typename Container>
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

