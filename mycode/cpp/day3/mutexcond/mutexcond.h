#pragma once
#include <unistd.h>
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;

class MutexLock {
    friend class Condition;
public:
    static MutexLock* getInstance();
    static void destroy();

    void lock();

    void unlock();

    pthread_mutex_t& getMutex();
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
private:
    Condition(MutexLock& mutex);
    ~Condition();
private:
    static Condition* _pInstance;
    pthread_cond_t _cond;
    MutexLock& _mutex;
};

