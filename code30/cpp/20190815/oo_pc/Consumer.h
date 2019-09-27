 ///
 /// @file    Consumer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:34:42
 ///
 

#pragma once

#include "Thread.h"

namespace wd
{

class TaskQueue;
class Consumer
: public Thread
{
public:
	Consumer(TaskQueue & taskque);

private:
	void run() override;
	TaskQueue & _taskQue;
};

}//end of namespace wd
