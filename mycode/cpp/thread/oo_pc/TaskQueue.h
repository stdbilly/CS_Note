#pragma once
#include <queue>
#include "Condition.h"
#include "MutexLock.h"
using std::queue;

namespace wd {
using ElemType = int;
class TaskQueue {
   public:
    TaskQueue(size_t quesize);

    bool empty() const;
    bool full() const;
    void push(ElemType);
    ElemType pop();

   private:
    size_t _queSize;
    queue<ElemType> _que;
    MutexLock _mutex;
    Condition _notFull;
    Condition _notEmpty;
};
}  // namespace wd