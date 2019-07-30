 ///
 /// @file    TestMylogger.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-29 09:56:04
 ///
 
#include "Mylogger.h"

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;


void test0()
{
	wd::Mylogger::getInstance()->error(prefix("this is error message").c_str());
	wd::Mylogger::getInstance()->warn(prefix("this is warn message").c_str());
	wd::Mylogger::getInstance()->info(prefix("this is info message").c_str());
	wd::Mylogger::getInstance()->debug(prefix("this is debug message").c_str());

	wd::Mylogger::destroy();
}

void test1()
{
	//系统提供给我们的内置宏
	cout << __FILE__ << endl
		 << __LINE__ << endl
		 << __FUNCTION__ << endl;
}

void test2()
{
	int number = 10;
	LogError("this is error message, %d", number);
	LogWarn("this is warn message");
	LogInfo("this is info message");
	LogDebug("this is debug message");
}
 
int main(void)
{
	//test0();
	//test1();
	test2();

	wd::Mylogger::destroy();
	return 0;
}
