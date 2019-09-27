 ///
 /// @file    Producer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:30:05
 ///
 
#include "Producer.h"
#include "TaskQueue.h"


#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Producer::Producer(TaskQueue & taskque)
: _taskQue(taskque)
{}

void Producer::run()
{
	int cnt = 20;	
	::srand(::clock());
	while(cnt--) {
		int number = ::rand() % 100;		
		_taskQue.push(number);

		cout << ">> producer thread " << pthread_self() 
			 << " produc a number = " << number << endl;
		::sleep(1);
	}
}

}
