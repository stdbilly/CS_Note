#pragma once 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

class Computer
{
public:
	Computer(const char * brand, float price)
	: _brand(new char[strlen(brand)+ 1]())
	, _price(price)
	{
		strcpy(_brand, brand);
		cout << "Computer(const char*, float)" << endl;
	}

	Computer(const Computer & rhs)
	: _brand(new char[strlen(rhs._brand) + 1]()) //深拷贝
	, _price(rhs._price)
	{
		cout << "Computer(const Computer &)" << endl;
		strcpy(_brand, rhs._brand);
	}

	Computer & operator=(const Computer & rhs)
	{
		if(this != &rhs) {//自复制
			cout << "Computer & operator=(const Computer &)" << endl;
			delete [] _brand;//回收左操作申请的空间

			//再进行深拷贝
			_brand = new char[strlen(rhs._brand) + 1]();
			strcpy(_brand, rhs._brand);
			_price = rhs._price;
		}
		return *this;
	}

	void print();

	~Computer()
	{//析构函数的作用是用来清理对象开辟的资源
		if(_brand)
			delete [] _brand;

		cout << "~Computer()" << endl;
	}

private:
	char * _brand;
	float _price;
};
 

inline void Computer::print()
{
	cout << "brand:" << _brand << endl
		 << "price:" << _price << endl;
}
