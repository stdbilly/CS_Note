 ///
 /// @file    TestEventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 11:13:59
 ///
 
#include "EventfdThread.h"

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
	wd::EventfdThread eventfd(std::bind(&Task::process, Task()));
	eventfd.start();

	int cnt = 20;
	while(cnt--) {
		cout << "main thread notify sub thread doing somethin..." << endl;
		eventfd.wakeup();	
		::sleep(1);
	}

	eventfd.stop();

	return 0;
}
