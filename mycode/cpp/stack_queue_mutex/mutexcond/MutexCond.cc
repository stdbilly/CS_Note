#include "MutexCond.h"
using namespace lock;

MutexLock* MutexLock::getInstance() {
    if (_pInstance == nullptr) {
        _pInstance = new MutexLock();
    }
    return _pInstance;
}

void MutexLock::destroy() {
    if (_pInstance) {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

void MutexLock::lock() {
    if (pthread_mutex_lock(&_pInstance->_mutex)) {
        perror("pthread_mutex_lock");
    }
}

void MutexLock::unlock() {
    if (pthread_mutex_unlock(&_pInstance->_mutex)) {
        perror("pthread_mutex_unlock");
    }
}

pthread_mutex_t* MutexLock::getMutexPtr() { return &_pInstance->_mutex; }
MutexLock::MutexLock() {
    if (pthread_mutex_init(&_mutex, nullptr)) {
        perror("pthread_mutex_init");
    }
}

MutexLock::~MutexLock() {
    if (pthread_mutex_destroy(&_mutex)) {
        perror("pthread_mutex_destroy");
    }
}

MutexLock* MutexLock::_pInstance = nullptr;

Condition::Condition(MutexLock& mutex) : _mutex(mutex) {
    if (pthread_cond_init(&_cond, nullptr)) {
        perror("pthread_cond_init");
    }
}

Condition* Condition::getInstance(MutexLock& mutex) {
    if (_pInstance == nullptr) {
        _pInstance = new Condition(mutex);
    }
    return _pInstance;
}

void Condition::destroy() {
    if (_pInstance) {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

Condition::~Condition() {
    if (pthread_cond_destroy(&_cond)) {
        perror("pthread_cond_destroy");
    }
}

void Condition::wait() {
    if (pthread_cond_wait(&_pInstance->_cond,
                          _pInstance->_mutex.getMutexPtr())) {
        perror("pthread_cond_wait");
    }
}

void Condition::notify() {
    if (pthread_cond_signal(&_pInstance->_cond)) {
        perror("pthread_cond_signal");
    }
}

void Condition::notifyall() {
    if (pthread_cond_broadcast(&_pInstance->_cond)) {
        perror("pthread_cond_broadcast");
    }
}

Condition* Condition::_pInstance = nullptr;
