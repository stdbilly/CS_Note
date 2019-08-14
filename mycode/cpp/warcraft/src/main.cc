#include "../include/GameConfig.h"
#include "../include/GameTime.h"
#include "../include/WarcraftWorld.h"
using namespace Warcraft;

void test0() {
    //武士生命值和攻击力的设置顺序
    vector<WarriorType> order0 = {DRAGON_TYPE, NINJA_TYPE, ICEMAN_TYPE,
                                  LION_TYPE, WOLF_TYPE};
    // red武士制造顺序
    vector<WarriorType> order1 = {ICEMAN_TYPE, LION_TYPE, WOLF_TYPE, NINJA_TYPE,
                                  DRAGON_TYPE};
    // blue武士制造顺序
    vector<WarriorType> order2 = {LION_TYPE, DRAGON_TYPE, NINJA_TYPE,
                                  ICEMAN_TYPE, WOLF_TYPE};
                                  
    CONFIG->setWarriorInitOrder(order0.begin(), order0.end());
    CONFIG->readFromFile("../input.conf");
    //CONFIG->debug();
#if 0
    for (int i = 0; i <= 100; ++i)
    {
        GameTime::getInstance()->showTime();
        if(!GameTime::getInstance()->updateTime()) {
            break;
        }
    }
#endif
    size_t groups = CONFIG->groupSize();
    for (size_t groupId = 0; groupId < groups; ++groupId) {
        cout << "Case:" << groupId + 1 << endl;
        WarcraftWorld wow;
        TIME->showTime();
        wow.setRedCreateOrder(order1.begin(), order1.end());
        wow.setBlueCreateOrder(order2.begin(), order2.end());


        CONFIG->nextGroupId();
        GameTime::getInstance()->reset();
    }
}

int main() {
    test0();
    return 0;
}
