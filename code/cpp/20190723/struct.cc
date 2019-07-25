 ///
 /// @file    Computer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 11:44:54
 ///
 
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;

struct Computer
{
//struct默认访问权限是public
	//在类内部定义的函数都是inline函数
	//即使没有加上inline关键字也是inline函数
	void setBrand(const char * brand)
	{
		strcpy(_brand, brand);
	}

	void setPrice(float price)
	{
		_price = price;
	}

	void print()
	{
		cout << "brand:" << _brand << endl
			 << "price:" << _price << endl;
	}

	//私有的成员不能在类之外直接访问
	char _brand[20];//brand_
	float _price;//m_price
};
 
int main(void)
{
	//内置类型
	int number;
	cout << "number = " << number << endl;

	//自定义类类型
	Computer pc;
	pc._price = 10000;//error
	pc.setBrand("Thinkpad");
	pc.setPrice(8888);
	pc.print();
 
	return 0;
}
