#pragma once
//#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <pthread.h>

namespace lock {
class MutexLock {
public:
    static MutexLock* getInstance();
    static void destroy();
    void lock();
    void unlock();
    pthread_mutex_t* getMutexPtr();

    MutexLock(const MutexLock& rhs) = delete ;
    MutexLock& operator=(const MutexLock& rhs) = delete ;
private:
    MutexLock();
    ~MutexLock();
private:
    static MutexLock* _pInstance;
    pthread_mutex_t _mutex;
};

class Condition {
public:
    static Condition* getInstance(MutexLock& mutex);
    static void destroy();
    void wait();
    void notify();
    void notifyall();

    Condition(const Condition& rhs)=delete ;
    Condition& operator=(const Condition& rhs)=delete ;
private:
    Condition(MutexLock& mutex);
    ~Condition();
private:
    static Condition* _pInstance;
    pthread_cond_t _cond;
    MutexLock& _mutex;
};

class MutexLockGuard {
public:
    MutexLockGuard(MutexLock& mutex)
        :_mutex(mutex){
            _mutex.lock();
        }

    ~MutexLockGuard() {
        _mutex.unlock();
    }
private:
        MutexLock& _mutex;
};
}//end of namespace lock

