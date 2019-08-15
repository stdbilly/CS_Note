#pragma once
#include <pthread.h>

namespace wd {
class MutexLock {
public:
    MutexLock();
    ~MutexLock();
    void lock();
    void unlock();
    pthread_mutex_t* getMutexPtr() { return &_mutex; }
private:
    pthread_mutex_t _mutex;
};

class MutexGuard
{
public:
    MutexGuard(MutexLock& mutexlock) 
    : _mutexlock(mutexlock) {
        _mutexlock.lock();
    }
    ~MutexGuard() {
        _mutexlock.unlock();
    }
private:
    MutexLock& _mutexlock;
};

}