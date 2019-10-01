 ///
 /// @file    TimerThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 11:22:51
 ///
 
#include "Timer.h"
#include "Thread.h"

namespace wd
{

class TimerThread
{
public:
	using TimerCallback = Timer::TimerCallback;
	TimerThread(int, int, TimerCallback && cb);

	void start();
	void stop();

private:
	Timer _timer;
	Thread _thread;
};

}//end of namespace wd
 
