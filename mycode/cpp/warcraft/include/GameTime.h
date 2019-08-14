#pragma once
#include <pthread.h>
#include <stdlib.h>

namespace Warcraft {
class GameTime {
   public:
    static GameTime* getInstance() {
        pthread_once(&_once, init);
        return _pInstance;
    }
    static void destroy() {
        if(_pInstance) delete _pInstance;
    }

    static void init() {
        ::atexit(destroy);
        _pInstance = new GameTime();
    }

    void showTime() const;
    bool updateTime();
    void reset() {
        _time = 0;
        _minute = 0;
    }

   private:
    GameTime(int hour = 0, int minute = 0)
        : _time(hour), _minute(minute) {}

   private:
    static GameTime* _pInstance;
    static pthread_once_t _once;
    int _time;
    int _minute;
};

#define TIME GameTime::getInstance()

}  // namespace Warcraft