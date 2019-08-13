// http://bailian.openjudge.cn/practice/3750/

#pragma once
#include <vector>
#include "City.h"
#include "Headquarter.h"
using std::vector;

namespace Warcraft {
class WarcraftWorld {
public:
    WarcraftWorld() 
    : _redHeadquarter(nullptr)
    , _blueHeadquarter(nullptr) {
        init();
    }

    void start() {
        while (1)
        {
            createWarrior();
            if(!warriorMarch()) { break; }
            cityProduceElements();
            takeCityElements();
            battle();
            headquarterReportElements();
        }
    }

    template<typename Iterator>
    void setRedCreateOrder(Iterator beg, Iterator end);

    template<typename Iterator>
    void setBlueCreateOrder(Iterator beg, Iterator end);

    ~WarcraftWorld() {
        if(_redHeadquarter) delete _redHeadquarter;
        if(_blueHeadquarter) delete _blueHeadquarter;
    }

   private:
    void init();
    //事件begin
    void createWarrior();        //整点：创建武士
    bool warriorMarch();         //第10分：所有武士前进一步
    void cityProduceElements();  //第20分：每个城市产出10个生命元
    void takeCityElements();     //第30分：武士取走城市中的生命元
    void battle();  //第40分：有两个武士的城市，会发生战斗
    void headquarterReportElements();  //第50分:司令部报告它拥有的生命元数量
    //事件end

    bool createWarrior(Headquarters*);  //某个司令部开始创建武士
    void warriorMarch(Headquarters*);   //某个司令部的武士行军
    bool checkRedIsTakeen();            //判断红色司令部是否被占领
    bool checkBlueIsTaken();            //判断蓝色司令部是否被占领

   private:
    Headquarters* _redHeadquarter;   //红色司令部
    Headquarters* _blueHeadquarter;  //蓝色司令部
    vector<City> _cities;  //所有的城市，其中0号代表红色司令部，size()-1代表蓝色司令部
};

template <typename Iterator>
void WarcraftWorld::setRedCreateOrder(Iterator beg, Iterator end) {
    _redHeadquarter->setWarriorCreateOrder(beg, end);
}

template <typename Iterator>
void WarcraftWorld::setBlueCreateOrder(Iterator beg, Iterator end) {
    _blueHeadquarter->setWarriorCreateOrder(beg, end);
}

}  // namespace Warcraft