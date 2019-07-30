 ///
 /// @file    brace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 14:57:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Example
{
public:
	//函数调用运算符
	int operator()(int x, int y)
	{
		++_count;
		return x + y;
	}

	int operator()(int x, int y, int z)
	{
		return x * y * z;
	}

	int callTime() const {	return _count;	}

private:
	//函数对象的状态
	int _count = 0;
};

int add(int x, int y)
{	
	static int count = 0;
	++count;
	cout << "count = " << count << endl;
	return x + y;	
}
 
int main(void)
{
	//重载了函数调用运算符的类创建的对象，称为函数对象
	//
	//携带了状态的函数对象 又可以称为闭包 ==> lambda表达式 ==> 匿名函数
	Example e1;

	int a = 3, b = 4, c = 5;
	cout << "e1(a, b) = " << e1(a, b) << endl;
	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "e1(a, b) = " << e1(a, b) << endl;

	cout << "add(a, b) = " << add(a, b) << endl;
	cout << "e1(a, b, c) = " << e1(a, b, c) << endl;
	cout << "e1.calltime() = " << e1.callTime() << endl;

	Example e2;
 

	return 0;
}
