 ///
 /// @file    Eventfd.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 10:53:33
 ///
 
#pragma once


#include <functional>
#include <iostream>
using std::cout;
using std::endl;
namespace wd
{

class Eventfd
{
public:
	using EventfdCallback = std::function<void()>;

	Eventfd(EventfdCallback && cb);
	~Eventfd();

	void start();
	void stop();
	void wakeup();
private:
	int createEventfd();
	void handleRead();

private:
	int _fd;
	EventfdCallback _cb;
	bool _isStarted;
};

}//end of namespace wd
