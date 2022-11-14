#include "Type.hpp"



Type stringToType(const std::string &s){
    if (s == "PHYSICAL"){
        return Type::PHYSICAL;
    } else if (s == "FIRE") {
        return Type::FIRE;
    } else if (s == "WATER") {
        return Type::WATER;
    } else if (s == "ICE") {
        return Type::ICE;
    } else if (s == "AIR") {
        return Type::AIR;
    } else if (s == "GRASS") {
        return Type::GRASS;
    } else if (s == "EARTH") {
        return Type::EARTH;
    }
    return Type::NONE;
}