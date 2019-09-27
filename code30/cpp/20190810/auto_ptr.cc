 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-10 11:27:02
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::auto_ptr;
 
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

int main(void)
{
	Point * pt = new Point(1, 2);
	auto_ptr<Point> ap(pt);
	cout << "pt = " << pt << endl;
	cout << "ap.get() = " << ap.get() << endl;
	cout << "*ap = " << *ap << endl;
	ap->print();

	cout << "\n 复制构造auto_ptr对象:" << endl;
	auto_ptr<Point> ap2(ap);//在语法形式上进行的是复制或者赋值操作，
							//但在底层已经完成了所有权的转移
							//
							//该智能指针存在缺陷, 所以不再使用
							//
	cout << "*ap2 = " << *ap2 << endl;
	//cout << "*ap = " << *ap << endl;
 
	auto_ptr<Point> ap3(new Point(3, 4));
	cout << "*ap3 = " << *ap3 << endl;
	ap3 = ap2;
	cout << "\n执行赋值函数: " << endl;
	cout << "*ap3 = " << *ap3 << endl;
	cout << "*ap2 = " << *ap2 << endl;

	return 0;
}
