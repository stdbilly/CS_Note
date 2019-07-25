 ///
 /// @file    Point.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 14:40:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//构造函数的作用：创建对象, 初始化数据成员
	//
	//当没有定义任何构造函数时，系统会自动提供一个
	//默认构造函数;
	//
	//一旦显式提供了一个构造函数时，默认构造函数就
	//不会再自动提供, 此时必须显式提供
	//
	//
	
//	Point() = default;

#if 1
	//构造函数可以进行重载
	Point()
	: _ix(0)   //初始化表达式(列表)
	, _iy(0)
	{
		//_ix = 0;//赋值语句
		//_iy = 0;//并不是真正的初始化
		cout << "Point()" << endl;
	}
#endif

	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{
		//_ix = ix;
		//_iy = iy;
		cout << "Point(int,int)" << endl;
	}


	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}


	//默认情况下，系统也会自动提供一个析构函数
#if 1
	//析构函数只有一个
	~Point()
	{
		cout << "~Point()" << endl;
	}
#endif

private:
	int _ix = 0;
	int _iy = 0;
};

 
int main(void)
{
	int number = 10;

	Point pt0;//调用默认构造函数
	cout << "pt0 = ";
	pt0.print();

	Point pt(1, 2);//有参构造函数
	cout << "pt = ";
	pt.print();

	Point * p1 = new Point(3, 4);
	p1->print();
 
	delete p1;
	return 0;
}
