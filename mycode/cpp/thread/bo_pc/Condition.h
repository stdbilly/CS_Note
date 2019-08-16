#pragma once
#include <pthread.h>

namespace wd {
class MutexLock;

class Condition {
public:
    Condition(MutexLock& mutex);
    ~Condition();
    void wait();
    void notify();
    void notifyall();
private:
    pthread_cond_t _cond;
    MutexLock& _mutex;    
};
}