 ///
 /// @file    TaskQueue.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 10:58:20
 ///
 
#pragma once

#include "MutexLock.h"
#include "Condition.h"
#include "Task.h"
#include <queue>
using std::queue;

namespace wd
{

using ElemType = Task *;

class TaskQueue
{
public:
	TaskQueue(size_t size);

	bool empty() const;
	bool full() const;
	void push(ElemType elem);
	ElemType pop();
	void wakeup();

private:
	size_t _queSize;
	queue<ElemType> _que;
	MutexLock _mutex;
	Condition _notFull;
	Condition _notEmpty;
	bool _flag;
};

}//end of namespace wd
