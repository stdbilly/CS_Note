 ///
 /// @file    multimap.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-06 14:32:40
 ///
 
#include <math.h>
#include <iostream>
#include <map>
#include <string>
using std::cout;
using std::endl;
using std::multimap;
using std::string;
using std::pair;


template <class Container>
void display(const Container & c)
{
	typename Container::const_iterator cit = c.begin();
	for(; cit != c.end(); ++cit) {
		cout << cit->first << " ---> " << cit->second << endl;
	}
}

void test0()
{
	multimap<int, string> cities;
	cities.insert(pair<int, string>(1, "北京"));
	cities.insert(pair<int, string>(2, "上海"));
	cities.insert(pair<int, string>(2, "广州"));
	cities.insert(pair<int, string>(4, "深圳"));

	display(cities);
}

void test1()
{
	//multimap内部能存放关键字相同的元素
	//默认情况下会按关键字升序方式进行排列
	//
	//底层实现依然是红黑树
	//
	multimap<int, string> cities = {
		std::make_pair(4, "深圳"),
		pair<int, string>(1, "北京"),
		std::make_pair(2, "上海"),
		std::make_pair(2, "广州"),
	};
	display(cities);


	auto ret = cities.insert(std::make_pair(5, "武汉"));
	cout << ret->first << " --> " 
		 << ret->second << endl;

	display(cities);

	//仅仅只是查找元素
	multimap<int, string>::iterator it = cities.find(8);
	if(it != cities.end()) {
		cout << "查找元素成功" << endl;
		cout << it->first << " ---> " << it->second << endl;
	} else {
		cout << "查找失败, 不会添加新的元素" << endl;
	}
	display(cities);
}

void test2()
{
	//multimap内部能存放关键字相同的元素
	//默认情况下会按关键字升序方式进行排列
	//
	//底层实现依然是红黑树
	//
	multimap<string, string> cities = {
		std::make_pair("0755", "深圳"),
		pair<string, string>("010", "北京"),
		std::make_pair("021", "上海"),
		std::make_pair("0755", "广州"),
	};
	display(cities);


	auto ret = cities.insert(std::make_pair("027", "武汉"));
	cout << ret->first << " --> " 
		 << ret->second << endl;
	display(cities);

	//不支持下标访问运算符
	//cout << cities["010"] << endl;//error

	//仅仅只是查找元素   O(logN)
	multimap<string, string>::iterator it = cities.find("0728");
	if(it != cities.end()) {
		cout << "查找元素成功" << endl;
		cout << it->first << " ---> " << it->second << endl;
	} else {
		cout << "查找失败, 不会添加新的元素" << endl;
	}
	display(cities);
}
 
class Point
{
public:
	Point(int ix, int iy)
	: _ix(ix)
	, _iy(iy)
	{	cout << "Point(int,int)" << endl;}

	double getDistance() const
	{
		return sqrt(_ix * _ix + _iy * _iy);
	}

	friend std::ostream & operator<<(std::ostream & os, const Point & rhs);
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

#if 0
bool operator<(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() < rhs.getDistance();
}
#endif

bool operator>(const Point & lhs, const Point & rhs)
{
	return lhs.getDistance() > rhs.getDistance();
}

struct Comparator
{
	bool operator()(const Point & lhs, const Point & rhs) const
	{
		return lhs.getDistance() < rhs.getDistance();
	}
};

void test3()
{
	//multimap<Point, int, std::greater<Point>> points =
	multimap<Point, int, Comparator> points =
	{
		std::make_pair(Point(1, 2), 1),
		std::make_pair(Point(2, 2), 1),
		std::make_pair(Point(3, 2), 1),
		std::make_pair(Point(4, 2), 1),
	};

	display(points);
}

int main(void)
{
	//test0();
	test1();
	//test2();
	//test3();

	return 0;
}
