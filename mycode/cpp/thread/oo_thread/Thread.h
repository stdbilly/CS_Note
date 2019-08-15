#pragma once
#include "Nocopyble.h"
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

namespace wd{
class Thread : Nocopyble {
public:
    Thread() 
    : _pthid(0)
    , _isRunning(false) {}

    virtual ~Thread();
    void start();
    void join();
    static void* threadFunc(void*);
private:
    virtual void run() = 0;
private:
    pthread_t _pthid;
    bool _isRunning;
};
}

