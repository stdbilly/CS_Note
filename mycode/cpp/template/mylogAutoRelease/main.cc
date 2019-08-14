#include "mylogger.h"

#include <string>
using std::string;
using std::to_string;

void test1(){
    int num = 10;
    LogWarn("warn message, %d",num);
    LogError("this is a error messages");
    LogDebug("this is a debug messages");
    LogInfo("this is a info messages");
    Mylogger::destroy();
}

int main() {
    test1();
    return 0;
}

