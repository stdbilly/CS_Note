 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-25 09:50:31
 ///
 
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

class String
{
public:
	String()
	: _pstr(nullptr)
	{
		cout << "String()" << endl;
	}

	void print() const
	{
		printf("_pstr = %p\n", _pstr);
		cout << _pstr << endl;//cout输出char* 的空指针，会导致程序直接崩溃
	}

private:
	char * _pstr;
};
 
int main(void)
{
	String s1;
	s1.print();

	cout << "---" << endl;

	return 0;
}
