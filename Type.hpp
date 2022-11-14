#pragma once

#include <string>



enum Type {
    PHYSICAL,
    FIRE,
    WATER,
    ICE,
    AIR,
    GRASS,
    EARTH, 
    NONE
};



Type stringToType(const std::string &s);