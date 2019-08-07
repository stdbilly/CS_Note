#pragma once
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

