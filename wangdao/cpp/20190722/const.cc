 ///
 /// @file    const.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-22 15:18:36
 ///
 
#include <iostream>
using std::cout;
using std::endl;

//编辑 ---> 预编译(预处理) --> 编译 --> 汇编 --> 链接 --> 可执行程序(运行)

//定义常量
//
//const修饰的常量与宏定义有什么差别？
//1. 发生的时机：
//	  宏定义是预编译, 进行简单的字符串替换
//	  const关键字是编译时, 其定义的常量是有类型检查
//
//使用宏定义是有概率会发生错误;
//2. 推荐使用const关键字定义常量，能够减少
//犯错误的概率
//
#define NUMBER 100

void test0()
{//内置类型: char/short/int/long   float double  void
 //指针类型
	const int number = 1;//常量
	//number = 10;//error

	//const int number2;//error
}

//数组指针   指针数组
//
//函数指针   指针函数
//
//常量指针   指针常量


void test1()
{
	int number = 10;
	int number2 = 20;
	const int * pa = &number;//常量指针(pointer to const)
	*pa = 20;//不能通过pa指针修改所指变量的值
	pa = &number2;//可以改变pa的指向

	int const * pc = &number;
	*pc = 20;
	pc = &number2;

	int * const pb = &number;//指针常量(const pointer)
	*pb = 20;//可以通过pb指针修改所指变量的值
	pb = &number2;//不能改变pb的指向

	const int * const pd = &number;//两者都不能进行修改 

}


 
int main(void)
{
 
}
