#include <string>
#include "func.h"
using std::string;
#include <iostream>
#include <memory>
using std::cout;
using std::endl;

namespace Warcraft {
class Warrior : public std::enable_shared_from_this<Warrior> {
   public:
    Warrior(Color color, WarriorType type, const string& name, size_t id,
            size_t hp, size_t forces)
        : _color(color),
          _type(type),
          _id(id),
          _hp(hp),
          _forces(forces)
    /* , _Headquarter */ {}

    virtual ~Warrior() {}

    virtual void march();
    virtual void attack(Warrior* warrior);
    virtual void defense(Warrior* warrior);

    void beWinner();
    void beRewarded();
    void sentElemToHeadquarter(size_t elements);

    void sethp(size_t hp) { _hp = hp; }
    void setCity(size_t cityId) { _cityId = cityId; }
    // void setHeadquarter()

    Color getcolor() const { return _color; }
    WarriorType getType() const { return _type; }
    string getName() const { return _name; }
    size_t getId() const { return _id; }
    size_t getHp() const { return _hp; }
    size_t getCityId() const { return _cityId; }
    size_t getEarnElements() const { return _earnElements; }
    size_t getForces() const { return _forces; }

   protected:
    Color _color;
    WarriorType _type;
    string _name;
    size_t _id;
    size_t _hp;
    size_t _forces;
    size_t _cityId;
    size_t _earnElements;
    // Headquarters
};
}  // namespace Warcraft