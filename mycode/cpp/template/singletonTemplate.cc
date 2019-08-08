#include <pthread.h>
#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton{
public:
    static T* getInstance(){
        pthread_once(&_once, init);
        return _pInstance;
    }

    static void init() {
        _pInstance = new T();
        ::atexit(destroy);

    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
        }
    }
private:
        Singleton() { 
            cout<<"Singleton()"<<endl; 
        }

    ~Singleton(){ 
        cout<<"~Singleton()"<<endl;  
    }
private:
    static T* _pInstance;
    static pthread_once_t _once;
};

template<typename T>
T* Singleton<T>::_pInstance = nullptr;
template<typename T>
pthread_once_t Singleton<T>::_once = PTHREAD_ONCE_INIT;

class Point {
public:
    Point(int ix = 0, int iy = 0)
        : _ix(ix)
          , _iy(iy)
    {   cout << "Point(int,int)" << endl;    }   

    void init(int ix, int iy) {   
        _ix = ix; 
        _iy = iy; 

    }   

    ~Point(){   cout << "~Point()" << endl;  }
private:                                                                                                                                                                                   
    int _ix;
    int _iy;
};


void test1() {
    Point* p3 = Singleton<Point>::getInstance();
    Point* p4 = Singleton<Point>::getInstance();
    p3->init(2,3);
    cout << "p3 = " << p3 << endl
        << "p4= " << p4 << endl; 
}

int main(){
    test1();
    return 0;
}

