#pragma once
#include <string>
using std::string;

enum Color { RED, BLUE, NOTSET };

enum WarriorType {
    DRAGON_TYPE,
    NINJA_TYPE,
    ICEMAN_TYPE,
    LION_TYPE,
    WOLF_TYPE
};

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