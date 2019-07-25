 ///
 /// @file    overload.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 17:23:39
 ///
 
#include <stdio.h>

//C++语言支持函数重载
//实现原理: 名字改编(name mangling)
//具体的操作步骤: 当函数名称相同时，会
//根据函数参数的类型，个数，顺序进行改编
int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}

float add(float x, float y)
{
	return x + y;
}

int add(int x, float y)
{
	return x + y;
}

int add(float x, int y)
{
	return x + y;
}

 
int main(void)
{
	int a = 3, b = 4;
	printf("add(a, b) = %d\n", add(a, b));
	return 0;
}
