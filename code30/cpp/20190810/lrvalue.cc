 ///
 /// @file    lrvalue.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-10 09:47:42
 ///
 
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector; 
using std::string;

int main(void)
{
	int a = 1;
	int b = 2;
	int * p = &a;
	vector<int> numbers;
	numbers.push_back(1);

	//&(a + b);//error 右值
	//&(a++);////error 右值
	&(++a);

	&p;
	&*p;
	&numbers[0];
	//&100;//error  右值, 字面值常量
	
	//&string("hello");//error 临时对象 右值
	string s1 = "hello";
	string s2 = "world";

	//&(s1 + s2);//error 临时对象 右值

	int & ref1 = a;
	//int & ref2 = 100;//error
	const int & ref3 = 100;//const左值引用可以绑定到右值
	const int & ref4 = b;// const左值引用可以绑定到左值
	//当const左值引用作为一个形参时，无法区分出传递过来的实参是左值还是右值的
	
	
	//C++11新特性: 右值引用 ==> 解决移动语义，所以一定会产生修改
	int && ref5 = 100;//右值引用只能绑定到右值, 不能绑定到左值 
	//int && ref6 = a;//error
	const int && ref6 = 100;//没有意义


 
	return 0;
}
