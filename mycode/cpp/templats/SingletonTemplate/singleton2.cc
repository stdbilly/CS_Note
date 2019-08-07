#include "Point3.h"
#include "Computer5.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Singleton{
public:
    template<typename... Args>
        static T* getInstance(Args... args){
            if(_pInstance==nullptr){
                ::atexit(destroy);
                _pInstance=new Singleton(args...);
            }
            return _pInstance->_data;
        }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
        }
    }
private:
    template<typename... Args>
        Singleton(Args... args) 
        : _data(new T(args...)){ 
            cout<<"Singleton()"<<endl; 
        }
    ~Singleton(){ 
        delete _data;
        cout<<"~Singleton()"<<endl;  
    }
private:
    static Singleton * _pInstance;
    T* _data;
};

template<typename T>
Singleton<T>* Singleton<T>::_pInstance = nullptr;

void test1() {
    Computer * p1 = Singleton<Computer>::getInstance("Xiaomi", 6666);
    Computer * p2 = Singleton<Computer>::getInstance("Xiaomi", 6666);
    
    printf("p1 = %p, p2 = %p\n", p1, p2);
    p1->print();

    Point* p3 = Singleton<Point>::getInstance(1, 2);
    Point* p4 = Singleton<Point>::getInstance(1, 2);

    printf("p3 = %p, p4 = %p\n", p3, p4);
    p3->print();
}

int main(){
    test1();
    return 0;
}

