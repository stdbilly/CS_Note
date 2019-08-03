 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-07-26 11:02:27
 ///
 
#pragma  once

#include "MutexLock.h"

#include <pthread.h>

namespace wd
{

class Condition
{
public:
	Condition(MutexLock & mutex)
	: _mutex(mutex)
	{
		if(pthread_cond_init(&_cond, nullptr)) {
			perror(">> pthread_cond_init");
		}
	}

	Condition(const Condition & rhs) = delete;
	Condition & operator=(const Condition & rhs) = delete;

	~Condition()
	{
		if(pthread_cond_destroy(&_cond)) {
			perror(">> pthread_cond_destroy");
		}
	}

	void wait()
	{
		if(pthread_cond_wait(&_cond, _mutex.getMutexLockPtr())) {
			perror(">> pthread_cond_wait");
		}
	} 

	void notify()
	{
		if(pthread_cond_signal(&_cond)) {
			perror(">> pthread_cond_signal");
		}
	}

	void notifyAll()
	{
		if(pthread_cond_broadcast(&_cond)) {
			perror(">> pthread_cond_broadcast");
		}
	}

private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace wd
 
