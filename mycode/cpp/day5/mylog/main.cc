#include "mylogger.h"

#include <string>
using std::string;

void test1(){
    LogWarn("this is a warn messages");
    LogError("this is a error messages");
    LogDebug("this is a debug messages");
    LogInfo("this is a info messages");
    Mylogger::destroy();
}

int main() {
    test1();
    LogWarn("this is a warn messages");
    LogError("this is a error messages");
    LogDebug("this is a debug messages");
    LogInfo("this is a info messages");
    Mylogger::destroy();
    return 0;
}

