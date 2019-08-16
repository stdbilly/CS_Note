#include <unistd.h>
#include <iostream>
#include "Task.h"
#include "WorkThread.h"
#include "Threadpool.h"
using std::cout;
using std::endl;

namespace wd{
Threadpool::Threadpool(size_t threadNum, size_t queSize) 
: _threadNum(threadNum)
, _queSize(queSize)
, _taskque(_queSize) 
, _isExit(false) {
    _threads.reserve(_threadNum);
}

void Threadpool::addTask(Task* task) {
    _taskque.push(task);
}

Task* Threadpool::getTask() {
    return _taskque.pop();
}

void Threadpool::start() {
    for(size_t idx = 0; idx != _threadNum; ++idx) {
        unique_ptr<Thread> thread(new WorkThread(*this));
        _threads.push_back(std::move(thread));
    }

    for(auto& thread: _threads) {
        thread->start();
    }
}
//每一个子线程都要执行的任务
void Threadpool::threadFunc() {
    while(!_isExit) {
        Task* task = getTask();
        if(task) {
            task->process(); //执行任务
        }
    }
}

void Threadpool::stop() {
    if(!_isExit) {
        while(!_taskque.empty()) {
            ::usleep(1);
        }
        _isExit = true;
        _taskque.wakeup();
        for(auto& thread: _threads) {
            thread->join();
        }
    }
}

Threadpool::~Threadpool() {
    cout << "~Threadpool()" << endl;
    if(!_isExit) {
        stop();
    }
}

}
