#pragma once
#include "Thread.h"

namespace wd {
class TaskQueue;

class Producer : public Thread {
public:
    Producer(TaskQueue& taskque);
private:
    void run() override;
    TaskQueue& _taskQue;
};
}