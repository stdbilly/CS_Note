#include "Point.cc"
#include "Noncopyable.h"
#include <boost/core/noncopyable.hpp>
#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton : boost::noncopyable {
   public:
    static T& getInstance() {
        pthread_once(&_once, init);
        return *_pInstance;
    }

    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
        }
    }

   private:
    static void init() {
        ::atexit(destroy);
        _pInstance = new T();
    }

    //Singleton(const Singleton&) = delete ;
    //Singleton& operator=(const Singleton&) = delete ;

    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }

   private:
    static T* _pInstance;
    static pthread_once_t _once;
};

//必须在头文件中定义static变量
template<typename T>
T* Singleton<T>::_pInstance = nullptr;

template<typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

int main() {
    Point& p1 = Singleton<Point>::getInstance();
    Point& p2 = Singleton<Point>::getInstance();
   
    Point& p3(p1);
    cout << "p1 = " << &p1 << endl << "p2 = " << &p2 << endl;
    cout << "p3 = " << &p3 << endl; 
    return 0;
}
