 ///
 /// @file    NullPointerCall.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-24 11:24:00
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class NullPointerCall
{
public:
	void test1()
	{	cout << "test1()" << endl;	}

	void test2(int data)
	{	cout << "test2() data = " << data << endl;	}

	static void test3()
	{
		cout << "test3() _data2 = " << _data2 << endl;
	}

	void test4()
	{	cout << "test4() _data = " << this->_data << endl;}

private:
	int _data;
	static int _data2;
};

int NullPointerCall::_data2 = 0;
 
int main(void)
{
	NullPointerCall * p = nullptr;//NULL
	p->test1();
	p->test2(10);
	p->test3();
	p->test4();
	return 0;
}
