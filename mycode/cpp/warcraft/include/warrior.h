#pragma once
#include "func.h"
#include <string>
#include <memory>
using std::string;

namespace Warcraft {
class Headquarters;

class Warrior : public std::enable_shared_from_this<Warrior> {
   public:
    Warrior(Color color, WarriorType type, const string& name, int id,
            int hp, int forces)
        : _color(color), _type(type), _id(id), _hp(hp), _forces(forces) {}

    virtual ~Warrior() {}

    /* virtual void march();
    virtual void attack(Warrior* warrior);
    virtual void defense(Warrior* warrior); */

    void beWinner();
    void beRewarded();
    //为司令部获取生命元
    void sentElemToHeadquarter(int elements);

    void sethp(int hp) { _hp = hp; }
    void setCity(int cityId) { _cityId = cityId; }
    void setHeadquarter(Headquarters* headquarter) {
        _headquarter = headquarter;
    }

    Color getcolor() const { return _color; }
    WarriorType getType() const { return _type; }
    string getName() const { return _name; }
    int getId() const { return _id; }
    int getHp() const { return _hp; }
    int getCityId() const { return _cityId; }
    int getEarnElements() const { return _earnElements; }
    int getForces() const { return _forces; }

   protected:
    Color _color;
    WarriorType _type;
    string _name;
    size_t _id;
    int _hp;            //生命值
    int _forces;        //攻击力
    int _cityId;        //位于哪个城市
    int _earnElements;  //从某个城市获取的生命元
    Headquarters* _headquarter;
};

class Dragon : public Warrior {
   public:
    Dragon(Color color, int id, int hp, int forces)
        : Warrior(color, DRAGON_TYPE, "dragon", id, hp, forces) {}
    ~Dragon() {}
};

class Ninja : public Warrior {
   public:
    Ninja(Color color, int id, int hp, int forces)
        : Warrior(color, NINJA_TYPE, "ninja", id, hp, forces) {}
    ~Ninja() {}
    // ninja挨打了也不反击
    //void defense(Warrior* warrior) override;
};

class Iceman : public Warrior {
   public:
    Iceman(Color color, int id, int hp, int forces)
        : Warrior(color, ICEMAN_TYPE, "iceman", id, hp, forces), _steps(0) {}
    ~Iceman() {}
    // iceman 每前进两步，在第2步完成的时候，生命值会减少9，攻击力会增加20。
    //但是若生命值减9后会小于等于0，则生命值不减9,而是变为1
    //void march() override;

   private:
    int _steps;
};

class Lion : public Warrior {
   public:
    Lion(Color color, int id, int hp, int forces)
        : Warrior(color, LION_TYPE, "lion", id, hp, forces) {}
};

class Wolf : public Warrior {
   public:
    Wolf(Color color, int id, int hp, int forces)
        : Warrior(color, WOLF_TYPE, "wolf", id, hp, forces), _killTimes(0) {}

    /* 在一个 wolf通过主动攻击杀死敌人的次数达到偶数的时刻（次数从1开始算），
    在战斗完成后，该wolf生命值和攻击力都增加1倍。如果其杀死的敌人是lion,
    则攻击力和生命值先加倍，然后才吸取lion的生命值。获取总部的生命元奖励，
    发生在加倍之后。只有在主动攻击杀死敌人时才能有加倍的事情，反击杀死敌人则不不会发生加倍
     */

    //void attack(Warrior* warrior) override;

   private:
    int _killTimes;  //击杀次数
};

}  // namespace Warcraft
