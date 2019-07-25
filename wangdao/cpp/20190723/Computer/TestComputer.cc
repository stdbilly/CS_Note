 ///
 /// @file    TestComputer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 14:33:34
 ///
 
#include "Computer.h"
#include <iostream>
using std::cout;
using std::endl;
 
int main(void)
{
	//内置类型
	int number;
	cout << "number = " << number << endl;

	//自定义类类型
	Computer pc;//创建对象的过程称为类的实例化
	//pc._price = 10000;//error
	pc.setBrand("Thinkpad");
	pc.setPrice(8888);
	pc.print();

	Computer pc2;
	pc2.setBrand("ACER");
	pc2.setPrice(6666);
	pc2.print();

 
	return 0;
}
