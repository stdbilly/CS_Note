 ///
 /// @file    Threadpool.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 15:23:42
 ///
 
#pragma once

#include "Thread.h"
#include "TaskQueue.h"

#include <vector>
#include <memory>

using namespace std;

namespace wd
{

class Task;
class Threadpool
{
public:
	Threadpool(size_t, size_t);
	~Threadpool();

	void start();
	void stop();
	void addTask(Task * task);

private:
	friend class WorkerThread;

	void threadFunc();//子线程执行的任务
	Task * getTask();

private:
	size_t _threadNum;
	size_t _queSize;
	vector<unique_ptr<Thread>> _threads;
	TaskQueue _taskque;
	bool _isExit;
};

}//end of namespace wd
