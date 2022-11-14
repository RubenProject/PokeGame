#pragma once

#include <vector>
#include <string>

#include "Attack.hpp"
#include "Type.hpp"
#include <jsoncpp/json/json.h>



class Pokemon {
public:
    Pokemon();
    Pokemon(Json::Value description);
    ~Pokemon();

    std::string getName() const;
    Type getType() const;
    int getHealthPoints() const;
    int getPower() const;
    int getDefense() const;
    int getSpeed() const;

    void setHealthPoints(int healthPoints);

    std::string selectAttack() const;
    std::string selectRandomAttack() const;
private:
    std::string mName;

    int mMaxHealthPoints;
    int mCurrentHealthPoints;
    int mPower;
    int mDefense;
    int mSpeed;
    Type mType;
    std::vector<std::string> mAttackList;
};
