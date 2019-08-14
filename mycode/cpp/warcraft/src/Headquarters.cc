#include "../include/Headquarters.h"
#include "../include/GameConfig.h"
#include "../include/warrior.h"

using namespace Warcraft;

Warrior* Headquarters::create() {
    size_t id = _warriors.size() + 1;
    switch (_warriorCreateOrder[_nextWarriorIndex]) {
        case DRAGON_TYPE:
            return createDragon(id, CONFIG->warriorInitLife(DRAGON_TYPE),
                         CONFIG->warriorInitAttack(DRAGON_TYPE));
        case NINJA_TYPE:
            return createNinja(id, CONFIG->warriorInitLife(NINJA_TYPE), CONFIG->warriorInitAttack(NINJA_TYPE));
        case ICEMAN_TYPE:
            return createIceman(id, CONFIG->warriorInitLife(ICEMAN_TYPE), CONFIG->warriorInitAttack(ICEMAN_TYPE));
        case LION_TYPE:
            return createLion(id, CONFIG->warriorInitLife(LION_TYPE), CONFIG->warriorInitAttack(LION_TYPE));
        case WOLF_TYPE:
            return createWolf(id, CONFIG->warriorInitLife(WOLF_TYPE), CONFIG->warriorInitAttack(WOLF_TYPE));
        default:
            break;
    }
}

Warrior* Headquarters::createDragon(size_t id, int hp, int forces) {
    
}