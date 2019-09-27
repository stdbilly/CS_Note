 ///
 /// @file    WorkerThread.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 16:00:46
 ///
 
#include "WorkerThread.h"
#include "Threadpool.h"

namespace wd
{

WorkerThread::WorkerThread(Threadpool & threadpool)
: _threadpool(threadpool)
{
	cout << "WorkerThread()" << endl;
}

WorkerThread::~WorkerThread()
{
	cout << "~WorkerThread()" << endl;
}


void WorkerThread::run()
{
	_threadpool.threadFunc();	
}
}//end of namespace wd
