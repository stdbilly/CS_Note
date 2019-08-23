 ///
 /// @file    Thread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:38:44
 ///
 
#pragma once

#include "Noncopyable.h"

#include <pthread.h>

#include <functional>
#include <string>

using std::string;

namespace wd
{

namespace current_thread
{
extern __thread const char * threadName;
} //end of namespace current_thread

class Thread
: Noncopyable
{
public:
	using ThreadCallback = std::function<void()>;

	Thread(ThreadCallback && cb, const string & name = string())
	: _pthid(0)
	, _isRunning(false)
	, _name(name)
	, _cb(std::move(cb))
	{}

	~Thread();

	void start();
	void join();
	string name() const {	return _name;	}

	static void * threadFunc(void *);

private:
	pthread_t _pthid;
	bool _isRunning;
	string _name;
	ThreadCallback _cb;
};

}//end of namespace wd
