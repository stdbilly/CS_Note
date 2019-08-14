#pragma once
#include "func.h"
#include "warrior.h"
#include <vector>
using std::vector;

namespace Warcraft {
class City {
   public:
    City(size_t id, size_t elements = 0) 
    : _flag(Color::NOTSET)
    , _id(id)
    , _elements(elements)
    , _redWinCount(0) 
    , _blueWinCount(0) {}
    
    void produceElements();//城市生产生命元
    void attach(Warrior*);//某武士进入该城市
    void detach(Warrior*);//某武士离开该城市
    void startBattle();//开始战斗
    void takenby(Warrior*);//生命元被某武士取走

    size_t getId() const { return _id;}
    Color getFlag() const {return _flag;}
    size_t getWarriorAmount() const {
        return _redWarriors.size() + _blueWarriors.size();
    }
    vector<Warrior*>& getRedWarriors() {
        return _redWarriors;
    }

    vector<Warrior*>& getBlueWarriors() {
        return _blueWarriors;
    }

private:
    void battle(Warrior* warrior1, Warrior* warrior2);//两名武士的具体战斗状况
    bool isChangeFlag(Warrior* warrior);

private:
    Color _flag;//城市旗帜的颜色
    size_t _id;
    size_t _elements;//城市生命元
    size_t _redWinCount;//红魔军连续胜利次数
    size_t _blueWinCount;//蓝魔军连续胜利次数
    vector<Warrior*> _redWarriors;
    vector<Warrior*> _blueWarriors;
};

}  // namespace Warcraft