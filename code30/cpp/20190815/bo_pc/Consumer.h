 ///
 /// @file    Consumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 14:39:03
 ///
 
#pragma once

#include "TaskQueue.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{
class Consumer
{
public:
	void consume(TaskQueue & taskque)
	{
		int cnt = 20;
		while(cnt--) {
			int number = taskque.pop();
			cout << ">> consumer thread " << pthread_self()
				 << " consume a number = " << number << endl;
			::sleep(1);
		}
	}


};
}
