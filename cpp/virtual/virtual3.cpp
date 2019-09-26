#pragma vtordisp(off)
#include <iostream>
using std::cout;
using std::endl;

class Base1 {
   public:
    Base1() : _iBase1(10) {}
    virtual void f() { cout << "Base1::f()" << endl; }

    virtual void g() { cout << "Base1::g()" << endl; }

    virtual void h() { cout << "Base1::h()" << endl; }

   private:
    int _iBase1;
};

class Base2 {
   public:
    Base2() : _iBase2(100) {}
    virtual void f() { cout << "Base2::f()" << endl; }

    virtual void g() { cout << "Base2::g()" << endl; }

    virtual void h() { cout << "Base2::h()" << endl; }

   private:
    int _iBase2;
};

class Base3 {
   public:
    Base3() : _iBase3(1000) {}
    virtual void f() { cout << "Base3::f()" << endl; }

    virtual void g() { cout << "Base3::g()" << endl; }

    virtual void h() { cout << "Base3::h()" << endl; }

   private:
    int _iBase3;
};

/* 
32位系统下
测试三：多重继承（带虚函数）
　 １.　每个基类都有自己的虚函数表
  ２.　派生类如果有自己的虚函数，会被加入到第一个虚函数表之中
  ３.  内存布局中，　其基类的布局按照基类被声明时的顺序进行排列
　４.　派生类会覆盖基类的虚函数，只有第一个虚函数表中存放的是
		真实的被覆盖的函数的地址；其它的虚函数表中存放的并不是真实的
		对应的虚函数的地址，而只是一条跳转指令

1>class Derived	size(28):
1>	+---
1> 0	| +--- (base class Base1)
1> 0	| | {vfptr}
1> 4	| | _iBase1
1>	| +---
1> 8	| +--- (base class Base2)
1> 8	| | {vfptr}
1>12	| | _iBase2
1>	| +---
1>16	| +--- (base class Base3)
1>16	| | {vfptr}
1>20	| | _iBase3
1>	| +---
1>24	| _iDerived
1>	+---

1>Derived::$vftable@Base1@:
1>	| &Derived_meta
1>	|  0
1> 0	| &Derived::f
1> 1	| &Base1::g
1> 2	| &Base1::h
1> 3	| &Derived::g1

1>Derived::$vftable@Base2@:
1>	| -8
1> 0	| &thunk: this-=8; goto Derived::f   跳转指令
1> 1	| &Base2::g
1> 2	| &Base2::h
1>
1>Derived::$vftable@Base3@:
1>	| -16
1> 0	| &thunk: this-=16; goto Derived::f   跳转指令
1> 1	| &Base3::g
1> 2	| &Base3::h
 */

/* 
虚继承Base1
1>class Derived	size(32):
1>	+---
1> 0	| +--- (base class Base2)
1> 0	| | {vfptr}
1> 4	| | _iBase2
1>	| +---
1> 8	| +--- (base class Base3)
1> 8	| | {vfptr}
1>12	| | _iBase3
1>	| +---
1>16	| {vbptr}        ==> 谁虚继承的基类，该虚基指针就跟着谁
1>20	| _iDerived
1>	+---
1>	+--- (virtual base Base1)
1>24	| {vfptr}
1>28	| _iBase1
1>	+---
 */

class Derived : virtual public Base1, public Base2, public Base3 {
   public:
    Derived() : _iDerived(10000) {}
    void f() { cout << "Derived::f()" << endl; }

    virtual void g1() { cout << "Derived::g1()" << endl; }

   private:
    int _iDerived;
};

int main(void) {
    Derived d;
    Base2* pBase2 = &d;
    Base3* pBase3 = &d;
    Derived* pDerived = &d;

    pBase2->f();
    cout << "sizeof(d) = " << sizeof(d) << endl;

    cout << "&Derived = " << &d << endl;    // 这三个地址值是不一样的
    cout << "pBase2 = " << pBase2 << endl;  //
    cout << "pBase3 = " << pBase3 << endl;  //

    return 0;
}
