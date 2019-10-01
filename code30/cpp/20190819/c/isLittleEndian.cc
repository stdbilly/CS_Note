 ///
 /// @file    isLittleEndian.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-20 10:02:40
 ///
 
#include <iostream>
using std::cout;
using std::endl;

bool isLittleEndian()
{
	union Foo
	{
		int a;
		char b;
	};

	Foo foo;
	foo.a = 1;
	return (foo.b == 1);
}
 
int main(void)
{
	cout << isLittleEndian() << endl;
	return 0;
}
