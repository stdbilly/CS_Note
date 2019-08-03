#include <stdio.h>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#define WARRIOR_NUM 5
#define WEAPON_NUM 3

class Headquarter ;

class Warrior {
public:
    Warrior(Headquarter* pHeadquarter, int no, int kindNo);
    void printResult(int nTime);
    void printWeapon(int _kindNo);
public:
    static int _initialLifeValue[WARRIOR_NUM];
private:
    Headquarter* _pHeadquarter;
    int _kindNo; //武士种类编号
    int _weaponNum; //武器种类编号
    int _weaponNo[2];
    int _no; //武士编号
    double _morale;//士气
    int _loyalty;
    static string _names[WARRIOR_NUM];
    static string _weapons[WEAPON_NUM];
    int _lifeValue;
};

string Warrior::_names[WARRIOR_NUM] = {"dragon","ninja","iceman","lion","wolf"};
string Warrior::_weapons[WEAPON_NUM] = {"sword","bomb","arrow"};
int Warrior::_initialLifeValue[WARRIOR_NUM] = {0};

class Headquarter {
public:
    friend class Warrior;
    void HeadquarterInit(int color, int lv);
    ~Headquarter();
    bool produce(int nTime);
    string getColor();
private:
    int _color; //0:red 1:blue
    int _totalLifeValue;
    int _totalWarriorNum;
    bool _stop;
    int _warriorNum[WARRIOR_NUM];//存放每种武士的数量
    int _curMakeSeqIdx;
    int _minLifeValue;
    static int _makingSeq[2][WARRIOR_NUM];//武士的制造顺序
    Warrior* _pWarrior[1000];
};

int Headquarter::_makingSeq[2][WARRIOR_NUM] = {{2,3,4,1,0}, {3,0,1,2,4}};

Warrior::Warrior(Headquarter* pHeadquarter, int no, int kindNo) 
    : _pHeadquarter(pHeadquarter)
    , _kindNo(kindNo)
      , _no(no) 
      , _lifeValue(0){
          switch(_kindNo) {
          case 0:
              _weaponNo[0] = _no % 3;
              _morale = 1.0 * _pHeadquarter ->_totalLifeValue / _initialLifeValue[_kindNo];
              break;
          case 1:
              _weaponNo[0] = _no % 3;
              _weaponNo[1] = (_no + 1) % 3;
              break;
          case 2:
              _weaponNo[0] = _no % 3;
              break;
          case 3:
              _loyalty = pHeadquarter->_totalLifeValue; 
              break;
          }
      }

void Warrior::printResult(int nTime) {
    string color = _pHeadquarter->getColor();

    printf("%03d %s %s %d born with strength %d, %d %s in %s headquarter\n", nTime, color.c_str(), _names[_kindNo].c_str(), _no, _initialLifeValue[_kindNo],
           _pHeadquarter->_warriorNum[_kindNo], _names[_kindNo].c_str(), color.c_str());
}

void Warrior::printWeapon(int kindNo) {
    switch(kindNo) {
    case 0:
        printf("It has a %s, and it's morale is %f\n", _weapons[_weaponNo[0]].c_str(), _morale);
        break;
    case 1:
        printf("It has a %s and a %s\n", _weapons[_weaponNo[0]].c_str(), _weapons[_weaponNo[1]].c_str());
        break;
    case 2:
        printf("It has a %s\n",_weapons[_weaponNo[0]].c_str());
        break;
    case 3:
        printf("It's loyalty is %d\n", _loyalty);
        break;
    }
}

void Headquarter::HeadquarterInit(int color, int lv) {
    _color=color;
    _totalLifeValue=lv;
    _totalWarriorNum=0;
    _stop=false;
    _curMakeSeqIdx=0;
    for(int i=0; i<WARRIOR_NUM; ++i) {
        _warriorNum[i] = 0;
    }

    _minLifeValue = Warrior::_initialLifeValue[0];

    for(int i=0; i<WARRIOR_NUM; ++i) {
        if(_minLifeValue > Warrior::_initialLifeValue[i]) {
            _minLifeValue = Warrior::_initialLifeValue[i];
        }
    }
}

string Headquarter::getColor() {
    return _color == 0 ? "red" : "blue";
}

Headquarter::~Headquarter() {
    for(int i=0; i<_totalWarriorNum; ++i) {
        delete _pWarrior[i];
    }
}

bool Headquarter::produce(int nTime) {
    if(_stop) return false;
    if(_minLifeValue > _totalLifeValue) {
        _stop = true;
        if(_color == 0) {
            printf("%03d red headquarter stops making warriors\n", nTime);
        }else{
            printf("%03d blue headquarter stops making warriors\n", nTime);
        }

        return false;
    }
    int i=0;
    while(Warrior::_initialLifeValue[_makingSeq[_color][_curMakeSeqIdx]] > _totalLifeValue && i < WARRIOR_NUM) {
        _curMakeSeqIdx = (_curMakeSeqIdx + 1) % WARRIOR_NUM;
        ++i;
    }
    int kindNo = _makingSeq[_color][_curMakeSeqIdx];
    _totalLifeValue -= Warrior::_initialLifeValue[kindNo];
    _curMakeSeqIdx = (_curMakeSeqIdx + 1) % WARRIOR_NUM;
    _pWarrior[_totalWarriorNum] = new Warrior(this, _totalWarriorNum+1, kindNo);
    ++_warriorNum[kindNo];
    _pWarrior[_totalWarriorNum]->printResult(nTime);
    _pWarrior[_totalWarriorNum]->printWeapon(kindNo);
    ++_totalWarriorNum;

    return true;
}

void test1() {
    int caseNum=0, t, m;
    Headquarter red, blue;
    scanf("%d",&t);
    while(t--) {
        printf("Case:%d\n",++caseNum);
        scanf("%d",&m);
        for(int i=0; i<WARRIOR_NUM; ++i) {
            scanf("%d",&Warrior::_initialLifeValue[i]);
        }

        red.HeadquarterInit(0,m);
        blue.HeadquarterInit(1,m);
        int nTime = 0;
        bool flag1 = true;
        bool flag2 = true;
        while(flag1 || flag2){
            flag1 = red.produce(nTime);
            flag2 = blue.produce(nTime);
            ++nTime;
        }
    }
}

int main() {
    test1();
    return 0;
}

