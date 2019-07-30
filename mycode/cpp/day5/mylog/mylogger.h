#pragma once
#include <log4cpp/Category.hh>

#include <iostream>
using namespace log4cpp;

#define suffix(msg)  std::string(msg).append(" [")\
    .append(__FILE__).append(":").append(__func__)\
    .append(":").append(std::to_string(__LINE__))\
    .append("]").c_str()


class Mylogger
{
public:
    static Mylogger* getInstance();
    static void destroy();
    void warn(const char * msg);
    void error(const char * msg);
    void debug(const char * msg);
    void info(const char * msg);
private:
    Mylogger(); 
    ~Mylogger();

private:
    Category & _mycategory;
    static Mylogger* _pInstance;
};

#define LogError(msg) Mylogger::getInstance()->error(suffix(msg))
#define LogWarn(msg) Mylogger::getInstance()->warn(suffix(msg))
#define LogInfo(msg) Mylogger::getInstance()->info(suffix(msg))
#define LogDebug(msg) Mylogger::getInstance()->debug(suffix(msg))

