#include "../include/WarcraftWorld.h"
#include "../include/GameConfig.h"
using namespace Warcraft;

void WarcraftWorld::init() {
    _redHeadquarter = new RedHeadquarter(GameConfig::getInstance()->headquartersInitElem());
    _blueHeadquarter = new BlueHeadquarter(GameConfig::getInstance()->headquartersInitElem());
}