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
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	//默认情况下，系统也会提供拷贝构造函数
#if 1
	Point(const Point & rhs)
	: _ix(rhs._ix)
	, _iy(rhs._iy)
	{
		cout << this->_ix << endl;

		cout << "Point(const Point & rhs)" << endl;
	}
#endif

	//this指针代表当前对象本身, 隐含的参数
	//void operator=(const Point & rhs)
	//Point比较简单，不需要显式定义
	Point & operator=(const Point & rhs)
	{
		cout << "Point & operator=(const Point & rhs)" << endl;
		this->_ix = rhs._ix;
		this->_iy = rhs._iy;

		return *this;
	}

	void print(/*     Point * const this     */)
	{
		//this = 0x1000;//error
		cout << "(" << this->_ix
			 << "," << this->_iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix = 0;
	int _iy = 0;
};

 
int test0(void)
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


void test1()
{
	int a = 3;
	int b = a;
	cout << "a = " << a << endl
		 << "b = " << b << endl;

	Point pt1(1, 2);
	cout << "pt1 = ";
	pt1.print();
	Point pt2 = pt1;//调用复制(拷贝)构造函数
	cout << "pt2 = ";
	pt2.print();

}
 
void func1(Point pt) //Point pt = p;
{
	cout << "pt = ";
	pt.print();
}

int getInt()
{
	int number = 10;
	return number;
}

Point func2()
{
	Point pt(5, 6);
	cout << "pt = ";
	pt.print();

	return pt;
}

void test2()
{
	//Point p(3, 4);
	//func1(p);
	
	Point p1 = func2();
}

void test3()
{
	int a = 3, b = 4, c = 5;
	a = b = c;
	
	Point pt1(1, 2), pt2(3, 4), pt3(5, 6);
	cout << "pt1 = ";
	pt1.print();// ==> Point::print(&pt1);
	cout << "pt2 = ";
	pt2.print();


	cout << "执行赋值语句之后:" << endl;
	pt2 = (pt1 = pt3);//调用赋值运算符函数
	//等价于pt2.operator=(pt1);	

	cout << "pt2 = ";
	pt2.print();
}

int main(void)
{
	//test1();
	//test2();
	test3();
	return 0;
}
