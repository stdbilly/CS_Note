 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-10 09:40:33
 ///
 
#include <string.h>
#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

class String
{
public:
	String()
	: _pstr(new char[1]())
	{
		cout << "String()" << endl;
	}

	String(const char * pstr)
	: _pstr(new char[strlen(pstr) + 1]())
	{
		strcpy(_pstr, pstr);
		cout << "String(const char *)" << endl;
	}

	//当const左值引用作为一个形参时，无法区分出传递过来的实参是左值还是右值的
	//
	//具有复制控制语义的函数
	//复制构造函数
	String(const String & rhs)
	: _pstr(new char[strlen(rhs._pstr) + 1]())
	{
		strcpy(_pstr, rhs._pstr);
		cout << "String(const String & rhs)" << endl;
	}

	//赋值运算符函数
	String & operator=(const String & rhs)
	{
		cout << "String & operator=(const String &)" << endl;
		if(this != &rhs) {
			delete [] _pstr;

			_pstr = new char[strlen(rhs._pstr) + 1]();
			strcpy(_pstr, rhs._pstr);
		}
		return *this;
	}

#if 1
	//具有移动语义的函数 的执行要优先于具有复制控制语义函数的执行
	//移动构造函数
	String(String && rhs)
	: _pstr(rhs._pstr) //使用浅拷贝，完成转移
	{
		rhs._pstr = nullptr;
		cout << "String(String && rhs)" << endl;
	}
	
	//移动赋值函数
	//
	//右值引用本身代表的是左值
	String & operator=(String && rhs)
	{
		cout << "String & operator=(String &&)" << endl;
		if(this != &rhs) {
			delete [] _pstr;

			_pstr = rhs._pstr;
			rhs._pstr = nullptr;
		}
		
		return *this;
	}
#endif


	~String()
	{
		if(_pstr)
			delete [] _pstr;

		cout << "~String()" << endl;
	}

	friend std::ostream & operator<<(std::ostream & os, const String & rhs);

private:
	char * _pstr;
};
 
std::ostream & operator<<(std::ostream & os, const String & rhs)
{
	os << rhs._pstr;
	return os;
}


String str("hello,world");

//当函数的返回值是对象时，如果返回的对象是
//一个局部（即将被销毁的）对象，执行return语句
//时，会调用移动构造函数；当返回的对象其
//生命周期是大于函数的，执行return语句时，会
//调用复制构造函数
String getString()
{
	String str("hello,world");
	cout << "str = " << str << endl;
	return str;
}

int test0(void)
{
	vector<String> strs;
	strs.push_back("hello,world");
	cout << "strs[0] = " << strs[0] << endl << endl;

	String s1 = "hello";
	s1 = String("world");

	String s2 = "shenzhen";
	cout << "s2 = " << s2 << endl;
	//&s2;
	s1 = std::move(s2);//显式将一个左值转换成右值
					   //一般表示在该语句之后，不会再使用该对象
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	cout << "....." << endl;

	s1 = std::move(s1);
 
	return 0;
}

void test1()
{
	getString();
}

//右值引用是一个右值
String && func()
{
	String str("hello");
	return std::move(str);
}

void test2()
{
	int a = 1;
	int b = 2;
	cout << "a = " << a << endl
		 << "b = " << b << endl;

	b = std::move(a);//std::move本质上就是一个强制转换

	cout << "a = " << a << endl
		 << "b = " << b << endl;

}

int main(void)
{
	//test1();


	//String("hello");
	//String s2("world");
	//func();//右值
	
	test2();

	return 0;
}
