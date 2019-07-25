 ///
 /// @file    Computer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 14:32:12
 ///
 
#pragma once

#include <iostream>
using std::cout;
using std::endl;
 
class Computer
{
public:
	//放在public区域的称为类对外提供的接口、功能、服务
	void setBrand(const char * brand);
	void setPrice(float price);
	void print();

private://封装的效果
	//私有的成员不能在类之外直接访问
	char _brand[20];//brand_
	float _price;//m_price
};
