 ///
 /// @file    inline.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 17:50:30
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//#define multiply(x, y)   ((x)*(y))
#define multiply(x, y)   x*y


//函数调用是有开销的
//
//inline函数是可以取代带参数的宏定义的
inline int divide(int x, int y);//函数声明
 
int main(void)
{
	int a = 5, b = 4;
	cout << multiply(a, b) << endl;
	//   a+b*b = 3 +4 * 4 = 19
	cout << multiply(a + b, b) << endl;//(a + b) * b  运行时错误
 
	cout << divide(a, b) << endl;
	return 0;
}

inline int divide(int x, int y) //函数实现
{
	return x / y;
}
