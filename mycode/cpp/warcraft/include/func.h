#pragma once
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

enum Color { RED, BLUE, NOTSET };

enum WarriorType { DRAGON_TYPE, NINJA_TYPE, ICEMAN_TYPE, LION_TYPE, WOLF_TYPE };

inline string toString(Color color) { return color == RED ? "red" : "blue"; }

inline string toString(WarriorType warrior) {
    switch (warrior) {
        case DRAGON_TYPE:
            return "dragon";
        case NINJA_TYPE:
            return "ninja";
        case ICEMAN_TYPE:
            return "iceman";
        case LION_TYPE:
            return "lion";
        case WOLF_TYPE:
            return "wolf";
        default:
            return "";
    }
}

/* template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    while (cit != c.end()) {
        cout << *cit << " ";
        ++cit;
    }
    cout << endl;
} */

template <class Container>
void display(const Container& c) {
    typename Container::const_iterator cit = c.begin();
    for (; cit != c.end(); ++cit) {
        cout << cit->first << " ---> " << cit->second << endl;
    }
}