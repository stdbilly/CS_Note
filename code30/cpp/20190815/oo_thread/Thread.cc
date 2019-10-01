 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:41:33
 ///
 
#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);
	}
}

void Thread::start()
{
	pthread_create(&_pthid, nullptr, threadFunc, this);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, nullptr);
		_isRunning = false;
	}
}

void * Thread::threadFunc(void * arg)
{
	Thread * pthread = static_cast<Thread *>(arg);
	if(pthread)
		pthread->run();//执行任务, 有多态
	return nullptr;
}

}//end of namespace wd
 
