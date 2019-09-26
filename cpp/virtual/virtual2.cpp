#pragma vtordisp(off)
#include <iostream>
using std::cout;
using std::endl;

class A {
   public:
    A() : _ia(10) {}

    virtual void f() { cout << "A::f()" << endl; }

   private:
    int _ia;
};

/* 
32位系统下
继承， 沒有虚函数
1>class B	size(8):
1>	+---
1> 0	| +--- (base class A)
1> 0	| | _ia
1>	| +---
1> 4	| _ib
1>	+---   
*/

/* 测试一：单个虚继承，不带虚函数
	虚继承与继承的区别
	１.　多了一个虚基指针
	２.　虚基类子对象位于派生类存储空间的最末尾

1>class B	size(12):
1>	+---
1> 0	| {vbptr}   ==> 虚基指针
1> 4	| _ib
1>	+---
1>	+--- (virtual base A)
1> 8	| _ia
1>	+---
 */

/* 
测试二：单个虚继承，带虚函数
  1.如果派生类没有自己的虚函数，此时派生类对象不会产生
　   虚函数指针

1>class B	size(16):
1>	+---
1> 0	| {vbptr}
1> 4	| _ib
1>	+---
1>	+--- (virtual base A)
1> 8	| {vfptr}
1>12	| _ia
1>	+---
 */

/* 
  2.如果派生类拥有自己的虚函数，此时派生类对象就会产生自己本身的虚函数指针，
    并且该虚函数指针位于派生类对象存储空间的开始位置

1>class B	size(20):
1>	+---
1> 0	| {vfptr}
1> 4	| {vbptr}
1> 8	| _ib
1>	+---
1>	+--- (virtual base A)
1>12	| {vfptr}
1>16	| _ia
1>	+---

//B的虚函数表
1>B::$vftable@B@:
1>	| &B_meta
1>	|  0
1> 0	| &B::fb2

//A的虚函数表，被B覆盖
1>B::$vftable@A@:
1>	| -12
1> 0	| &B::f
 */
class B : virtual public A {
   public:
    B() : _ib(20) {}

    void fb() { cout << "A::fb()" << endl; }

    /*virtual*/ void f() { cout << "B::f()" << endl; }

    virtual void fb2() { cout << "B::fb2()" << endl; }

   private:
    int _ib;
};

int main(void) {
    cout << sizeof(A) << endl;
    cout << sizeof(B) << endl;
    B b;
    return 0;
}