#include "mylogger.h"
#include <log4cpp/FileAppender.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/RollingFileAppender.hh>
using std::cout;
using std::endl;

Mylogger* Mylogger::getInstance(const char* filename) {
    if (_pInstance == nullptr) {
        _pInstance = new Mylogger(filename);
    }
    return _pInstance;
}

void Mylogger::destroy() {
    if (_pInstance) {
        delete _pInstance;
        _pInstance = nullptr;
    }
}

Mylogger::Mylogger(const char* filename)
    : _mycategory(Category::getRoot().getInstance("mycategory")) {
    PatternLayout* ptnLayout1 = (new PatternLayout());
    PatternLayout* ptnLayout2 = (new PatternLayout());
    OstreamAppender* ostreamAppender =
        (new OstreamAppender("OstreamAppender", &cout));
    FileAppender* fileAppender = (new FileAppender("FileAppender", filename));
    ptnLayout1->setConversionPattern("%d [%p] %m%n");
    ptnLayout2->setConversionPattern("%d [%p] %m%n");
    ostreamAppender->setLayout(ptnLayout1);
    fileAppender->setLayout(ptnLayout2);
    _mycategory.setPriority(Priority::DEBUG);
    _mycategory.addAppender(ostreamAppender);
    _mycategory.addAppender(fileAppender);
}

Mylogger::~Mylogger() { Category::shutdown(); }

Mylogger* Mylogger::_pInstance = nullptr;