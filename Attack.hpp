#pragma once

#include "Type.hpp"
#include <string>
#include <jsoncpp/json/json.h>



class Attack {
public:
    Attack();
    Attack(Json::Value description);
    ~Attack();

    std::string getName() const;
    int getPower() const;
    int getAccuracy() const;
    int getSpecialCost() const;
    Type getType() const;
private:
    std::string mName;

    int mPower; 
    int mAccuracy;
    int mSpecialCost;

    Type mType;

};
