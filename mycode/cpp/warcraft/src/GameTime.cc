#include "../include/GameTime.h"
#include "../include/GameConfig.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;

namespace Warcraft {
void GameTime::showTime() const {
    cout << std::setfill('0') ;
    cout << std::setw(3) << _time/60 << ":" << std::setw(2) << _minute << " " <<endl; 
}

bool GameTime::updateTime() {
    _time = _time + 10;
    if(_time >= GameConfig::getInstance()->getMaxTime()) {
        return false;
    }
    _minute = _time % 60;
    return true;
}

GameTime* GameTime::_pInstance = nullptr;
pthread_once_t GameTime::_once = PTHREAD_ONCE_INIT;
}