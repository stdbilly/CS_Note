 ///
 /// @file    Consumer.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:36:06
 ///
 
#include "Consumer.h"
#include "TaskQueue.h"

#include <unistd.h>

#include <iostream>
using std::cout;
using std::endl;
 

namespace wd
{
Consumer::Consumer(TaskQueue & taskque)
: _taskQue(taskque)
{}

void Consumer::run()
{
	int cnt = 20;
	while(cnt--) {
		int number = _taskQue.pop();
		cout << ">> consumer thread " << pthread_self()
			 << " consume a number = " << number << endl;
		//::sleep(1);
	}
}

}//end of namespace wd
