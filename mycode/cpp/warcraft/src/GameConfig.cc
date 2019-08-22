#include "../include/GameConfig.h"
#include <fstream>
#include <iostream>
#include <sstream>
using std::cout;
using std::endl;
using std::ifstream;
using std::istringstream;
using std::make_pair;

namespace Warcraft {
void GameConfig::readFromFile(const string& filename) {
    ifstream ifs(filename);
    if (!ifs) {
        cout << "open config file error" << endl;
        return;
    }
    string line;
    getline(ifs, line);  //先读取有几组测试数据
    int n = std::stoi(line);
    _groups.resize(n);//这里不能用reserve,reserve只会分配空间,不会创建对象；resize会创建对象
    for (int i = 0; i < n; i++) {
        getline(ifs, line);
        istringstream iss(line);
        iss >> _groups[i]._initElements >> _groups[i]._cityCount >> _groups[i]._maxTime;

        getline(ifs, line);
        istringstream iss1(line);
        for (int j = 0; j < 5; ++j) {
            int hp;
            iss1 >> hp;
            //cout << hp << endl;
            _groups[i]._initLifes[_initWarriorOrder[j]] = hp;
        }

        getline(ifs, line);
        istringstream iss2(line);
        for (int j = 0; j < 5; j++) {
            int force;
            iss2 >> force;
            //cout << force << endl;
            _groups[i]._initAttacks[_initWarriorOrder[j]] = force;
        }
    }
}

void GameConfig::debug() {
    for (size_t i = 0; i < _groups.size(); i++) {
        display(_groups[i]._initLifes);
        display(_groups[i]._initAttacks);
    }
}

GameConfig* GameConfig::_pInstance = nullptr;
pthread_once_t GameConfig::_once = PTHREAD_ONCE_INIT;
}