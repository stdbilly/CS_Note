#include <iostream>
using std::cout;
using std::endl;

class Singleton{
public:
    static Singleton * getInstance(){
        if(_pInstance==nullptr){
            _pInstance=new Singleton();
        }
        return _pInstance;
    }

    static void destroy(){
        if(_pInstance){
            delete _pInstance;
        }
    }
private:
    Singleton(){ cout<<"Singleton()"<<endl; }
    ~Singleton(){ cout<<"~Singleton()"<<endl;  }
private:
    static Singleton * _pInstance;
};

Singleton * Singleton::_pInstance=nullptr;

int main(){   
    Singleton* p1=Singleton::getInstance();
    Singleton* p2=Singleton::getInstance();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    Singleton::destroy();
    return 0;
}

