 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:38:44
 ///
 
#pragma once

#include "Noncopyable.h"

#include <pthread.h>

namespace wd
{

class Thread
: Noncopyable
{
public:
	Thread()
	: _pthid(0)
	, _isRunning(false)
	{}

	virtual ~Thread();

	void start();
	void join();

	static void * threadFunc(void *);

private:
	virtual void run()=0;

private:
	pthread_t _pthid;
	bool _isRunning;
};

}//end of namespace wd
