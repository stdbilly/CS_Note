 ///
 /// @file    Thread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 09:41:33
 ///
 
#include "Thread.h"

#include <iostream>
using std::cout;
using std::endl;

namespace wd
{

namespace current_thread
{
__thread const char * threadName = "wd thread";
} //end of namespace current_thread


using ThreadCallback = std::function<void()>;
struct ThreadData
{
	ThreadData(const string name, ThreadCallback && cb)
	: _name(name)
	, _cb(cb)
	{}

	//子线程中执行
	void runInThread()
	{
		current_thread::threadName = (_name==string()?"wd thread" : _name.c_str());
	
		if(_cb) {
			_cb();
		}
	}
	
	string _name;
	ThreadCallback _cb;
};

Thread::~Thread()
{
	if(_isRunning) {
		pthread_detach(_pthid);
	}
	cout << "~Thread()" << endl;	
}

void Thread::start()
{
	ThreadData * pdata = new ThreadData(_name, std::move(_cb));
	pthread_create(&_pthid, nullptr, threadFunc, pdata);
	_isRunning = true;
}

void Thread::join()
{
	if(_isRunning) {
		pthread_join(_pthid, nullptr);
		_isRunning = false;
	}
}

void * Thread::threadFunc(void * arg)
{
	ThreadData * pdata = static_cast<ThreadData *>(arg);
	if(pdata)
		pdata->runInThread();//执行任务

	delete pdata;
	return nullptr;
}

}//end of namespace wd
 
