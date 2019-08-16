#include "TaskQueue.h"

namespace wd {
TaskQueue::TaskQueue(size_t queSize)
    : _queSize(queSize), _mutex(), _notFull(_mutex), _notEmpty(_mutex) {}

bool TaskQueue::empty() const { return _que.size() == 0; }

bool TaskQueue::full() const { return _que.size() == _queSize; }

void TaskQueue::push(ElemType elem) {
    MutexGuard autolock(_mutex);
    while (full()) {
        _notFull.wait();
    }

    _que.push(elem);
    _notEmpty.notify();
}

ElemType TaskQueue::pop() {
    MutexGuard autolock(_mutex);
    while (empty()) {
        _notEmpty.wait();
    }

    ElemType elem = _que.front();
    _que.pop();
    _notFull.notify();
    return elem;
}
}  // namespace wd