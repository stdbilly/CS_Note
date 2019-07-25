 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 11:44:54
 ///
 

#include "Computer.h"
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

 
//在类之外实现成员函数
void Computer::setBrand(const char * brand)
{
	strcpy(_brand, brand);
}

void Computer::setPrice(float price)
{
	_price = price;
}

void Computer::print()
{
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}

