 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:38:44
 ///
 
#pragma once

#include "Noncopyable.h"

#include <pthread.h>

#include <functional>

namespace wd
{

class Thread
: Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;

	Thread(ThreadCallback && cb)
	: _pthid(0)
	, _isRunning(false)
	, _cb(std::move(cb))
	{}

	~Thread();

	void start();
	void join();

	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
	ThreadCallback _cb;
};

}//end of namespace wd
