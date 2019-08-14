#pragma once
#include "City.h"
#include "Headquarters.h"
#include "warrior.h"
using namespace Warcraft;

class WarriorView {
   public:
    WarriorView(Warrior* warrior) : _warrior(warrior) {}

    void showBorn() const;          //武士出生时
    void showMarch() const;         //武士行军时
    void showEarnElements() const;  //武士取走城市生命元时
    void showReachDest() const;     //武士到达敌方司令部时
   protected:
    void showName() const;
    void showToCity() const;
    void showInCity() const;
    void showDeath() const;
    void showHpAndForces() const;

   protected:
    Warrior* _warrior;
};

class DragonView : public WarriorView {
   public:
    DragonView(Warrior* warrior) : WarriorView(warrior) {}
    // dragon 在一次在它主动进攻的战斗结束后，如果还没有战死，就会欢呼
    void showYell() const;
};

class BattleView {
   public:
    BattleView(Warrior* warrior1, Warrior* warrior2)
        : _warrior1(warrior1), _warrior2(warrior2) {}

    //武士主动进攻时
    void showAttack() const;
    //武士反击时
    void showDefense() const;

   private:
    Warrior* _warrior1;
    Warrior* _warrior2;
};

class HeadquartersView {
   public:
    HeadquartersView(Headquarters* headquarter) : _headquarter(headquarter) {}

    //司令部报告情况时
    void showLeftElements() const;
    //司令部被占领时
    void showBeTaken() const;

   private:
    Headquarters* _headquarter;
};

class CityView {
   public:
    CityView(City* city) : _city(city) {}
    //城市更换旗帜时
    void showFlag() const;

   private:
    City* _city;
};