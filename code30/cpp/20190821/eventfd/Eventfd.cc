 ///
 /// @file    Eventfd.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-21 10:55:59
 ///
 
#include "Eventfd.h"

#include <unistd.h>
#include <errno.h>
#include <poll.h>
#include <sys/eventfd.h>

#include <iostream>
using std::cout;
using std::endl;
 
namespace wd
{

Eventfd::Eventfd(EventfdCallback && cb)
: _fd(createEventfd())
, _cb(std::move(cb))
, _isStarted(false)
{
}

Eventfd::~Eventfd()
{
	if(_isStarted) {
		stop();
	}
}

void Eventfd::start()
{
	_isStarted = true;

	struct pollfd pfd;
	pfd.fd = _fd;
	pfd.events = POLLIN;

	while(_isStarted) {
		int nready = ::poll(&pfd, 1, 5000);
		if(nready == -1 && errno == EINTR)
			continue;
		else if(nready == -1) {
			perror(">> poll");
			return ;
		} else if(nready == 0) {
			cout << ">> poll timeout!" << endl;
		} else {
			if(pfd.revents & POLLIN) {
				handleRead();//处理事件 (水平触发)
				if(_cb) 
					_cb(); //执行任务
			}
		}
	}
}

void Eventfd::stop()
{
	_isStarted = false;
}

int Eventfd::createEventfd()
{
	int fd = ::eventfd(0, 0);	
	if(fd == -1) {
		perror(">> eventfd_create");
	}
	return fd;
}

void Eventfd::handleRead()
{
	uint64_t howmany;
	int ret = ::read(_fd, &howmany, sizeof(howmany));
	if(ret != sizeof(howmany)) {
		perror(">> read");
	}
}

//handleRead与wakeup要运行在不同的线程
void Eventfd::wakeup()
{
	uint64_t one = 1;
	int ret = ::write(_fd, &one, sizeof(one));
	if(ret != sizeof(one)) {
		perror(">> write");
	}
}

}//end of namespace wd
