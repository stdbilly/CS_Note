 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 09:52:35
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;


class Point
{
public:
	Point(int ix = 0, int iy = 0)
	: _ix(ix)
	, _iy(iy)
	{
		cout << "Point(int,int)" << endl;
	}

	void print() const
	{
		cout << "(" << _ix
			 << "," << _iy
			 << ")" << endl;
	}

	~Point() {	cout << "~Point()" << endl;	}

private:
	int _ix;
	int _iy;
};


void test0()
{
	shared_ptr<Point> sp(new Point(1, 2));
	(*sp).print();
	sp->print();
	cout << "sp' use_count = " << sp.use_count() << endl;

	shared_ptr<Point> sp2(sp);
	cout << "sp' use_count = " << sp.use_count() << endl;
	cout << "sp2' use_count = " << sp2.use_count() << endl;
	(*sp).print();
	sp->print();
	
	(*sp2).print();
	sp2->print();

}
 
int main(void)
{
	test0();

	return 0;
 
}
