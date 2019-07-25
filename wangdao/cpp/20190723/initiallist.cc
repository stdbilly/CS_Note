 ///
 /// @file    initiallist.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 14:57:09
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Example
{
public:
	//数据成员初始化的顺序只与其声明时的顺序有关，而
	//与其在初始化表达式中的顺序无关
	Example(int data)
	: _iy(data)
	, _ix(_iy)
	{
		cout << "Example(int)" << endl;
	}

	void print()
	{
		cout << _ix << "," << _iy << endl;
	}

private:
	int _ix;
	int _iy;
};
 
int main(void)
{
	Example e(10);
	e.print();

	return 0;
}
