#pragma once
#include "Thread.h"

namespace wd {
class TaskQueue;

class Consumer : public Thread{
public:
    Consumer(TaskQueue& taskque);
private:
    void run() override;
    TaskQueue& _taskQue;
};
}