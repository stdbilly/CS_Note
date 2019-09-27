 ///
 /// @file    EventfdThread.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 11:22:51
 ///
 
#include "Eventfd.h"
#include "Thread.h"

namespace wd
{

class EventfdThread
{
public:
	using EventfdCallback = Eventfd::EventfdCallback;
	EventfdThread(EventfdCallback && cb);

	void start();
	void stop();
	void wakeup();

private:
	Eventfd _eventfd;
	Thread _thread;
};

}//end of namespace wd
 
