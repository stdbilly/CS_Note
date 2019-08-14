#pragma once
#include <pthread.h>
#include <stdlib.h>
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
    static GameConfig* getInstance() {
        pthread_once(&_once, init);
        return _pInstance;
    }
    static void destroy() {
        if (_pInstance) delete _pInstance;
    }

    static void init() {
        ::atexit(destroy);
        _pInstance = new GameConfig();
    }

    void readFromConsole();
    void readFromFile(const string& filename);
    void nextGroupId() { ++_currentGroupId; }  //测试下一组数据
    void debug();

    template <typename Iterator>
    void setWarriorInitOrder(Iterator beg, Iterator end) {
        auto it = _initWarriorOrder.begin();
        _initWarriorOrder.insert(it, beg, end);
    }

    size_t groupSize() const { return _groups.size(); }
    int getMaxTime() const { return _groups[_currentGroupId]._maxTime; }
    int getCurrentGroupId() const { return _currentGroupId; }
    int getcityCount() const { return _groups[_currentGroupId]._cityCount; }
    int headquartersInitElem() const {
        return _groups[_currentGroupId]._initElements;
    }
    int warriorInitLife(WarriorType type) const {
        return _groups[_currentGroupId]._initLifes.at(type);
    }
    int warriorInitAttack(WarriorType type) const {
        return _groups[_currentGroupId]._initAttacks.at(type);
    }

   private:
    GameConfig() : _currentGroupId(0) { cout << "GameConfig()" << endl; }
    ~GameConfig() { cout << "~GameConfig()" << endl; }

    struct InitData {
        int _initElements;
        int _cityCount;
        int _maxTime;
        unordered_map<WarriorType, int> _initLifes;
        unordered_map<WarriorType, int> _initAttacks;
    };

   private:
    static GameConfig* _pInstance;
    static pthread_once_t _once;
    vector<InitData> _groups;  // N组数据
    int _currentGroupId;       //当前正在测试的一组数据
    vector<WarriorType>
        _initWarriorOrder;  //输入时武士的生命值和攻击力的设置顺序
};

#define CONFIG GameConfig::getInstance()

}  // namespace Warcraft
