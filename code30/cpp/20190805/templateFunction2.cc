 ///
 /// @file    templateFunction2.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-05 11:34:16
 ///
 
#include <iostream>
using std::cout;
using std::endl;


#define Max 10

//模板形参列表可以存放多个参数的
//模板形参的设置有两种类型:
//1. 类型参数
//2. 非类型参数, 常量表达式, 整型数据(bool/char/short/int/long/long long)
//
//模板形参可以设置默认值
//
template <class T1, class T2>
void func(T1 t1, T2 t2)
{
	cout << "t1 = " << t1 << endl
		 << "t2 = " << t2 << endl;
}

template <class T, int NUMBER = 10>
T func1(T t)
{
	return NUMBER * t;
}

 
int main(void)
{
	int d1 = 2;
	double d2 = 1.1;
	func<int, double>(d1, d2);
	cout << func1<int>(d1) << endl;
	cout << func1<int, 20>(d1) << endl;
 
	return 0;
}
