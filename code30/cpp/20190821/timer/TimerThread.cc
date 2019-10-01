 ///
 /// @file    TimerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 11:24:47
 ///
 
#include "TimerThread.h"
#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

TimerThread::TimerThread(int initialTime, int periodicTime, TimerCallback && cb)
: _timer(initialTime, periodicTime, std::move(cb))
, _thread(std::bind(&Timer::start, &_timer))
{}

void TimerThread::start()
{
	_thread.start();
}
	
void TimerThread::stop()
{
	_timer.stop();
	_thread.join();
}

}//end of namespace wd
 
