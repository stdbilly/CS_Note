 ///
 /// @file    overload.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 17:23:39
 ///
 
#include <stdio.h>

//C语言不支持函数重载
int add(int x, int y)
{
	return x + y;
}

int add(int x, int y, int z)
{
	return x + y + z;
}

 
int main(void)
{
	int a = 3, b = 4;
	printf("add(a, b) = %d\n", add(a, b));
}
