#include <iostream>
using std::cout;
using std::endl;

//应用场景:
  //1. 可以用单例模式替换掉全局变量
  //2. 配置文件中的存储都是程序的输入信息
  //3. 词典库， 网页库

class Singleton {
   public:
    static Singleton* getInstance() {
        if (_pInstance == nullptr) {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destroy() {
        if (_pInstance) {
            delete _pInstance;
        }
    }

   private:
    Singleton() { cout << "Singleton()" << endl; }
    ~Singleton() { cout << "~Singleton()" << endl; }

   private:
    static Singleton* _pInstance;
};

Singleton* Singleton::_pInstance = nullptr;

int main() {
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    cout << "p1=" << p1 << endl << "p2=" << p2 << endl;
    Singleton::destroy();
    return 0;
}
