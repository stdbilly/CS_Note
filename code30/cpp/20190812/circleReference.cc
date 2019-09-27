 ///
 /// @file    circleReference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 09:59:02
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;

class Child;

class Parent
{
public:
	Parent() {cout << "Parent()" << endl;	}
	~Parent() {	cout << "~Parent()" << endl;	}

	shared_ptr<Child> _pChild;
};

class Child
{
public:
	Child(){	cout << "Child()" << endl;	}
	~Child(){	cout << "~Child()" << endl;	}

	shared_ptr<Parent> _pParent;
};
 
int main(void)
{
	//shared_ptr的循环引用会导致内存泄漏
	shared_ptr<Parent> pParent(new Parent);
	shared_ptr<Child> pChild(new Child);
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;
	pParent->_pChild = pChild;// 引用计数加1
	pChild->_pParent = pParent;// 引用计数加1
 
	cout << "pParent's use_count = " << pParent.use_count() << endl;
	cout << "pChild's use_count = " << pChild.use_count() << endl;

	return 0;
}
