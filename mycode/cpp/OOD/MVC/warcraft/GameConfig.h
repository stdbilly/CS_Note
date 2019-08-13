#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "func.h"
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::vector;

namespace Warcraft {
class GameConfig {
   public:
    static GameConfig* getInstance();
    static void destroy();

    void readFromConsole();
    void readFromFile(const string& filename);
    void nextGroupId() { ++_currentGroupId; }

    size_t groups() const { return _groups.size(); }
    size_t getCurrentGroupId() const { return _currentGroupId; }
    size_t getcityCount() const;
    size_t headquartersInitElem() const;
    size_t warriorInitLife(WarriorType Key) const;
    size_t warriorInitAttack(WarriorType Key) const;

   private:
    GameConfig() : _currentGroupId(0) {}
    ~GameConfig() {}
    struct InitData {
        size_t _initElements;
        size_t _cityCount;
        size_t _minutes;
        unordered_map<WarriorType, size_t> _initLifes;
        unordered_map<WarriorType, size_t> _initAttacks;
    };

   private:
    static GameConfig* _pInstance;
    vector<InitData> _groups;
    size_t _currentGroupId;
    vector<WarriorType> _initWarriorOrder;
};
}  // namespace Warcraft
