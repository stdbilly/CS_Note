#pragma once
#include <iostream>
using std::cout;
using std::endl;

class Noncopyable {
protected:
    Noncopyable() = default;
    ~Noncopyable() = default;
    Noncopyable(const Noncopyable&) = delete ;
    Noncopyable& operator=(const Noncopyable&) = delete ;
};

