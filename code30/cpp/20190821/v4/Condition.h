 ///
 /// @file    Condition.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:10:47
 ///
 
#pragma once

#include "Noncopyable.h" 

#include <pthread.h>


namespace wd
{

class MutexLock;
class Condition
: Noncopyable
{
public:
	Condition(MutexLock & mutex);

	~Condition();

	void wait();
	void notify();
	void notifyall();
private:
	pthread_cond_t _cond;
	MutexLock & _mutex;
};

}//end of namespace wd
