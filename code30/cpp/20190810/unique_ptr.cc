 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-10 11:40:22
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
using std::unique_ptr;
 
class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	} 

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
		     << ")" << endl;
	}

	~Point(){	cout << "~Point()" << endl;	}
private:
	int _ix;
	int _iy;
};
 
std::ostream & operator<<(std::ostream & os, const Point & rhs)
{
	os << "(" << rhs._ix
	   << "," << rhs._iy
	   << ")";
	return os;
}

unique_ptr<Point> getPoint()
{
	unique_ptr<Point> up(new Point(1, 2));
	return up;//调用的是unique_ptr的移动构造函数
}


int main(void)
{
	Point * pt = new Point(1, 2);

	//unique_ptr是独享所有权的智能指针
	unique_ptr<Point> up(pt);
	cout << "pt = " << pt << endl;
	cout << "up.get() = " << up.get() << endl;
	cout << "*up = " << *up << endl;
	up->print();

	//cout << "\n 复制构造auto_ptr对象:" << endl;
	//unique_ptr不能进行复制或者赋值操作的
	//unique_ptr<Point> ap2(ap);//error
	//cout << "*ap2 = " << *ap2 << endl;
	//cout << "*ap = " << *ap << endl;
 
	unique_ptr<Point> ap3(new Point(3, 4));
	cout << "*ap3 = " << *ap3 << endl;
	//ap3 = ap2;//error


	
	//1. boost库中提供了指针容器ptr_vector
	//2. 采用智能指针
	vector<unique_ptr<Point>> points;
	points.push_back(unique_ptr<Point>(new Point(1, 2)));
	points.push_back(unique_ptr<Point>(new Point(3, 2)));
	points.push_back(unique_ptr<Point>(new Point(3, 4)));
	//points.push_back(up);
	//unique_ptr具有移动语义
	points.push_back(std::move(up));
	
	unique_ptr<Point> up2 = getPoint();//右值

	return 0;
}
