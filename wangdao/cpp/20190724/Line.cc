 ///
 /// @file    Line.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 09:49:33
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
public:
	//对于引用数据成员，只能放在初始化表达式中
	//进行初始化
	explicit
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int, int)" << endl;
	}

	void print()
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point()
	{
		cout << "~Point()" << endl;
	}

private:
	int _ix;
	int _iy;
};


class Line
{
public:
	//类的对象成员也必须要放在初始化表达式中进行初始化
	Line(int x1, int y1, int x2, int y2)
	: _pt1(x1, y1)
	, _pt2(x2, y2)
	{
		cout << "Line(int,int,int,int)" << endl;
	}

	void printLine()
	{
		_pt1.print();
		cout << " ---> ";
		_pt2.print();
	}

private:
	Point _pt1;
	Point _pt2;
};
 
int main(void)
{
	Point pt0;

	Point pt();//声明了一个函数
	//pt.print();
	Point(1, 2).print();//构造了一个临时对象

	cout << endl;
	Line line(1, 2, 3, 4);
	line.printLine();

	return 0;
}
