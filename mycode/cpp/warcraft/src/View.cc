#include "../include/View.h"
#include "../include/GameTime.h"
using namespace Warcraft;

void WarriorView::showBorn() const {
    TIME->showTime();
    cout << toString(_warrior->getcolor()) << " " << _warrior->getName() << " " << _warrior->getId() << " born" << endl;
    TIME->updateTime();
}