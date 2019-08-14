#pragma once
#include <queue>
#include <unordered_map>
#include <vector>
#include "func.h"
using std::priority_queue;
using std::unordered_map;
using std::vector;

namespace Warcraft {
class Warrior;

class Headquarters {
   public:
    Headquarters(Color color, int elements)
        : _color(color),
          _elements(elements),
          _earnElements(0),
          _nextWarriorIndex(0) {}

    virtual ~Headquarters() {}

    Warrior* create();
    Warrior* addWinner(Warrior* warrior);
    void reward();

    //统计从城市获得的生命元
    void increaseElements(int elements) { _earnElements += elements; }

    //设置所剩生命元数量
    void setElements(int elements) { _elements = elements; }
    //设置武士生产顺序
    template <typename Iterator>
    void setWarriorCreateOrder(Iterator beg, Iterator end) {
        for (; beg != end; ++beg) {
            _warriorCreateOrder.push_back(*beg);
        }
    }

    int getId() const { return _id; }
    void setId(int id) { _id = id; }
    Color getColor() const { return _color; }
    int getElements() const { return _elements; }
    vector<Warrior*>& getWarriors() { return _warriors; }

   private:
    Warrior* createIceman(size_t id, int hp, int forces);
    Warrior* createLion(size_t id, int hp, int forces);
    Warrior* createWolf(size_t id, int hp, int forces);
    Warrior* createNinja(size_t id, int hp, int forces);
    Warrior* createDragon(size_t id, int hp, int forces);

    void nextWarriorType() { ++_nextWarriorIndex; }

    WarriorType getNextWarriorType() {
        return _warriorCreateOrder[_nextWarriorIndex];
    }

   protected:
    Color _color;
    int _id;        //编号，0代表红色司令部,N+1代表蓝色司令部
    int _elements;  //当前司令部所剩的生命元
    int _earnElements;  //一次战斗时刻结束后，所有武士获取的生命元
    int _nextWarriorIndex;  //下次创建的武士的下标
    vector<WarriorType> _warriorCreateOrder;

    //一次战斗时间结束后，胜利的所有武士
    //优先奖励距离敌方司令部近的武士
    // priority_queue<Warrior*, vector<Warrior*>, WarriorComparator> _winners;

    vector<Warrior*> _warriors;  //生产的所有武士
    //各种类型武士的数量
    unordered_map<WarriorType, int> _warriorTypeCount;
};

class RedHeadquarter : public Headquarters {
   public:
    RedHeadquarter(int elements) : Headquarters(RED, elements) {}
    ~RedHeadquarter() {}
};

class BlueHeadquarter : public Headquarters {
   public:
    BlueHeadquarter(int elements) : Headquarters(BLUE, elements) {}
    ~BlueHeadquarter() {}
};

}  // namespace Warcraft
