// 测试四：钻石型虚继承

//虚基指针所指向的虚基表的内容：
//	1. 虚基指针的第一条内容表示的是该虚基指针距离所在的子对象的首地址的偏移
//	2. 虚基指针的第二条内容表示的是该虚基指针距离虚基类子对象的首地址的偏移

#pragma vtordisp(off)
#include <iostream>
using std::cout;
using std::endl;

/*  测试四：钻石型虚继承,
    1. 没有采用虚继承的情况
    > 存储二义性问题：顶层基类B在存储空间中出现了2份

1>class D	size(48):
1>	+---
1> 0	| +--- (base class B1)
1> 0	| | +--- (base class B)
1> 0	| | | {vfptr}
1> 4	| | | _ib
1> 8	| | | _cb
1>  	| | | <alignment member> (size=3)
1>	| | +---
1>12	| | _ib1
1>16	| | _cb1
1>  	| | <alignment member> (size=3)
1>	| +---
1>20	| +--- (base class B2)
1>20	| | +--- (base class B)
1>20	| | | {vfptr}
1>24	| | | _ib
1>28	| | | _cb
1>  	| | | <alignment member> (size=3)
1>	| | +---
1>32	| | _ib2
1>36	| | _cb2
1>  	| | <alignment member> (size=3)
1>	| +---
1>40	| _id
1>44	| _cd
1>  	| <alignment member> (size=3)
1>	+---
 */

/*
虚继承，没有新的虚函数 
1>class D	size(44):
1>	+---
1> 0	| +--- (base class B1)
1> 0	| | {vbptr}
1> 4	| | _ib1
1> 8	| | _cb1
1>  	| | <alignment member> (size=3)
1>	| +---
1>12	| +--- (base class B2)
1>12	| | {vbptr}
1>16	| | _ib2
1>20	| | _cb2
1>  	| | <alignment member> (size=3)
1>	| +---
1>24	| _id
1>28	| _cd
1>  	| <alignment member> (size=3)
1>	+---
1>	+--- (virtual base B)
1>32	| {vfptr}
1>36	| _ib
1>40	| _cb
1>  	| <alignment member> (size=3)
1>	+---
 */

class B {
   public:
    B() : _ib(10), _cb('B') {}

    virtual void f() { cout << "B::f()" << endl; }

    virtual void Bf() { cout << "B::Bf()" << endl; }

   private:
    int _ib;
    char _cb;
};

class B1 : virtual public B {
   public:
    B1() : _ib1(100), _cb1('1') {}

    virtual void f() { cout << "B1::f()" << endl; }

#if 1
    virtual void f1() { cout << "B1::f1()" << endl; }
    virtual void Bf1() { cout << "B1::Bf1()" << endl; }
#endif

   private:
    int _ib1;
    char _cb1;
};

class B2 : virtual public B {
   public:
    B2() : _ib2(1000), _cb2('2') {}

    virtual void f() { cout << "B2::f()" << endl; }
#if 1
    virtual void f2() { cout << "B2::f2()" << endl; }
    virtual void Bf2() { cout << "B2::Bf2()" << endl; }
#endif
   private:
    int _ib2;
    char _cb2;
};

/* 
测试四：钻石型虚继承
2. 采用虚继承

虚基指针所指向的虚基表的内容：
	1. 虚基指针的第一条内容表示的是该虚基指针距离所在的子对象的首地址的偏移
	2. 虚基指针的第二条内容表示的是该虚基指针距离虚基类子对象的首地址的偏移

1>class D	size(52):
1>	+---
1> 0	| +--- (base class B1)
1> 0	| | {vfptr}                        GNU GCC中会把这两个指针合并成一个指针
1> 4	| | {vbptr}
1> 8	| | _ib1
1>12	| | _cb1
1>  	| | <alignment member> (size=3)
1>	| +---
1>16	| +--- (base class B2)
1>16	| | {vfptr}
1>20	| | {vbptr}
1>24	| | _ib2
1>28	| | _cb2
1>  	| | <alignment member> (size=3)
1>	| +---
1>32	| _id
1>36	| _cd
1>  	| <alignment member> (size=3)
1>	+---
1>	+--- (virtual base B)
1>40	| {vfptr}
1>44	| _ib
1>48	| _cb
1>  	| <alignment member> (size=3)
1>	+---

1>D::$vbtable@B1@:
1> 0	| -4              //虚基指针距离所在的子对象的首地址的偏移
1> 1	| 36 (Dd(B1+4)B)  //虚基指针距离虚基类子对象的首地址的偏移
1>
1>D::$vbtable@B2@:
1> 0	| -4
1> 1	| 20 (Dd(B2+4)B)

1>D::$vftable@B1@:
1>	| &D_meta
1>	|  0
1> 0	| &D::f1
1> 1	| &B1::Bf1
1> 2	| &D::Df

1>D::$vftable@B2@:
1>	| -16
1> 0	| &D::f2
1> 1	| &B2::Bf2

1>D::$vftable@B@:
1>	| -40
1> 0	| &D::f
1> 1	| &B::Bf
 */

class D : public B1, public B2 {
   public:
    D() : _id(10000), _cd('3') {}

    virtual void f() { cout << "D::f()" << endl; }

#if 1
    virtual void f1() { cout << "D::f1()" << endl; }
    virtual void f2() { cout << "D::f2()" << endl; }

    virtual void Df() { cout << "D::Df()" << endl; }
#endif
   private:
    int _id;
    char _cd;
};

int main(void) {
    D d;
    cout << sizeof(d) << endl;
    return 0;
}
