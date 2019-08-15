#pragma once
#include "Nocopyble.h"
#include <pthread.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

namespace wd{
class Thread : Nocopyble {
public:
    using ThreadCallback = std::function<void()>;

    Thread(ThreadCallback&& cb) 
    : _pthid(0)
    , _isRunning(false) 
    , _cb(std::move(cb)) {}

    ~Thread();
    void start();
    void join();
    static void* threadFunc(void*);
private:
    pthread_t _pthid;
    bool _isRunning;
    ThreadCallback _cb;
};
}

