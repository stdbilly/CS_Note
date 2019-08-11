#pragma once
#include <log4cpp/Category.hh>

#include <iostream>
using namespace log4cpp;

#define suffix(msg)                  \
    std::string(msg)                 \
        .append(" [")                \
        .append(__FILE__)            \
        .append(":")                 \
        .append(__func__)            \
        .append(":")                 \
        .append(to_string(__LINE__)) \
        .append("]")                 \
        .c_str()

class Mylogger {
   public:
    static Mylogger* getInstance(const char* filename);
    static void destroy();

    template <typename... Args>
    void warn(Args... args) {
        _mycategory.warn(args...);
    }

    template <typename... Args>
    void error(Args... args) {
        _mycategory.error(args...);
    }

    template <typename... Args>
    void debug(Args... args) {
        _mycategory.debug(args...);
    }

    template <typename... Args>
    void info(Args... args) {
        _mycategory.info(args...);
    }

   private:
    Mylogger(const char* filename);
    ~Mylogger();

   private:
    Category& _mycategory;
    static Mylogger* _pInstance;
};

#define LogError(msg, ...) \
    Mylogger::getInstance("test.log")->error(suffix(msg), ##__VA_ARGS__)
#define LogWarn(msg, ...) \
    Mylogger::getInstance("test.log")->warn(suffix(msg), ##__VA_ARGS__)
#define LogInfo(msg, ...) \
    Mylogger::getInstance("test.log")->info(suffix(msg), ##__VA_ARGS__)
#define LogDebug(msg, ...) \
    Mylogger::getInstance("test.log")->debug(suffix(msg), ##__VA_ARGS__)
