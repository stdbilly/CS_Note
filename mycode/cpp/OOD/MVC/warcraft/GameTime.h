#pragma once
#include <iostream>

namespace Warcraft {
class GameTime {
   public:
    static GameTime* getInstance();
    static void destroy();

    void showTime() const;
    void updateTime();
    void reset() {
        _hour = 0;
        _minute = 0;
    }

   private:
    GameTime(size_t hour = 0, size_t minute = 0)
        : _hour(hour), _minute(minute) {}

   private:
    static GameTime* _pInstance;
    size_t _hour;
    size_t _minute;
};
}  // namespace Warcraft