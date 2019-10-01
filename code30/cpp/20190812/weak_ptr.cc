 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-12 10:17:19
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
using std::weak_ptr;
 
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

int main(void)
{
	weak_ptr<Point> wp;
	
	{
		shared_ptr<Point> sp(new Point(1, 2));
		wp = sp;

		cout << "sp's use_count = " << sp.use_count() << endl;
		cout << "wp's use_count = " << wp.use_count() << endl;
		cout << "wp's expired = " << wp.expired() << endl;
	
		shared_ptr<Point> sp2 = wp.lock();
		//shared_ptr<Point> sp3;
		cout << "sp's use_count = " << sp.use_count() << endl;
		if(sp2) {
			cout << "*sp2 = ";
			sp2->print();
			cout << "weak_ptr提升成功!" << endl;
		} else {
			cout << "weak_ptr提升失败, 被托管的资源已经被销毁!" << endl;
		}
	}

	//weak_ptr是辅助shared_ptr的，为了解决shared_ptr的问题而出现
	//weak_ptr知道所托管的资源是否还存在，
	//weak_ptr不能直接访问资源的
	cout << "\nwp's expired = " << wp.expired() << endl;

	shared_ptr<Point> sp2 = wp.lock();
	//shared_ptr<Point> sp3;
	cout << "sp2's use_count = " << sp2.use_count() << endl;
	if(sp2) {
		cout << "*sp2 = ";
		sp2->print();
		cout << "weak_ptr提升成功!" << endl;
	} else {
		cout << "weak_ptr提升失败, 被托管的资源已经被销毁!" << endl;
	}

	return 0;
}
