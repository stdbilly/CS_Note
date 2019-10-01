 ///
 /// @file    Producer.h
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2019-08-15 11:28:19
 ///
 

#pragma once

#include "Thread.h"

namespace wd
{

class TaskQueue;
class Producer
: public Thread
{
public:
	Producer(TaskQueue & taskque);

private:
	void run() override;
	TaskQueue & _taskQue;
};

}//end of namespace wd
