 ///
 /// @file    testAdd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-05 11:16:29
 ///

#include "add"

#include <iostream>
using std::cout;
using std::endl;

void test0()
{
	int a = 3, b = 4;
	cout << "add(a, b) = " << add(a, b) << endl;
}
 
int main(void)
{
	test0();
	return 0;
}
