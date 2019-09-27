 ///
 /// @file    TestTimer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 11:13:59
 ///
 
#include "TimerThread.h"

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

class Task
{
public:
	void process()
	{
		::srand(::clock());
		int number = ::rand() % 100;
		cout << ">> get a number = " << number << endl;
	}
};
 

int main(void)
{
	wd::TimerThread timer(3, 6, std::bind(&Task::process, Task()));
	timer.start();
	::sleep(20);

	timer.stop();

	return 0;
}
