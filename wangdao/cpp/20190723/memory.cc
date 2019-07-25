 ///
 /// @file    memory.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-23 11:03:15
 ///
 
#include <stdio.h>
#include <string.h>

#include <iostream>
using std::cout;
using std::endl;

int a = 0;
char * p1;//即使没有显式进行初始化, 系统也会清零
 
int test0(void)
{
	int b;
	char s[] = "hello,world";
	char * p2;//栈上, 不会清零，野指针

	const char * p3 = "hello,world";//文字常量区,只读,不能进行修改
	//*p3 = 'X';//error
	
	static int c = 0;//不在栈上，位于全局静态区
	++c;
	p1 = new char[10];
	strcpy(p1, "hello,world");


	printf("&a = %p\n", &a);
	printf("&b = %p\n", &b);
	printf("&c = %p\n", &c);
	printf("c = %d\n", c);

	printf("&p1 = %p\n", &p1);
	printf("p1 = %p\n", p1);
	printf("&p2 = %p\n", &p2);
	printf("p2 = %p\n", p2);
	printf("s = %p\n", s);
	printf("&p3 = %p\n", &p3);
	printf("p3 = %p\n", p3);
	printf("&test0 = %p\n", test0);
	printf("&test0 = %p\n", &test0);


	return 0;
}

int main(void)
{
	test0();
	cout << endl;
	test0();
	cout << endl;
	test0();
	return 0;
}
