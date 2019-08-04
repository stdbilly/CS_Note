#include <iostream>
using std::cout;
using std::endl;

class Singleton{
    class AutoRelease {
    public:
        AutoRelease() { cout << "AutoRelease()" << endl; }

        ~AutoRelease() {
            cout << "~AutoRelease()" << endl;
            if(_pInstance) {
                delete _pInstance;
            }
        }
    };

public:
    static Singleton * getInstance(){
        if(_pInstance==nullptr){
            _pInstance=new Singleton();
        }
        return _pInstance;
    }

private:
    Singleton(){ cout<<"Singleton()"<<endl; }
    ~Singleton(){ cout<<"~Singleton()"<<endl;  }
private:
    static Singleton * _pInstance;
    static AutoRelease _auto;
};

Singleton * Singleton::_pInstance=getInstance();
Singleton::AutoRelease Singleton::_auto;

int main(){   
    Singleton* p1=Singleton::getInstance();
    Singleton* p2=Singleton::getInstance();
    cout<<"p1="<<p1<<endl
        <<"p2="<<p2<<endl;
    return 0;
}

