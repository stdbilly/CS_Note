#pragma once
#include "Thread.h"
#include "TaskQueue.h"
#include <vector>
#include <memory>
#include <iostream>
using std::vector;
using std::unique_ptr;
using std::cout;
using std::endl;
namespace wd{
class Task;

class Threadpool {
friend class WorkThread;
public:
    Threadpool(size_t, size_t);
    ~Threadpool();
    void start();
    void stop();
    void addTask(Task* task);
private:
    void threadFunc(); //子线程执行的任务
    Task* getTask();
private:
    size_t _threadNum;
    size_t _queSize;
    vector<unique_ptr<Thread>> _threads;
    TaskQueue _taskque;
    bool _isExit;
};
}
