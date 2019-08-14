#include "../include/WarcraftWorld.h"
#include "../include/GameConfig.h"
#include "../include/View.h"
#include <memory.h>
using std::unique_ptr;
using namespace Warcraft;

void WarcraftWorld::init() {
    _redHeadquarter = new RedHeadquarter(GameConfig::getInstance()->headquartersInitElem());
    _blueHeadquarter = new BlueHeadquarter(GameConfig::getInstance()->headquartersInitElem());
}

void WarcraftWorld::createWarrior() {
    Warrior* warrior = _redHeadquarter->create();
    if(warrior) {
        unique_ptr<WarriorView> view(new WarriorView(warrior));
        view.get()->showBorn();
    }
}