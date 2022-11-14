#include "Pokemon.hpp"
#include "config.hpp"
#include "Type.hpp"

#include <fstream>
#include <iostream>
#include <cstdlib>



Pokemon::Pokemon()
{}


Pokemon::Pokemon(Json::Value description)
{
	mName = description["name"].asString();
	mMaxHealthPoints = description["healthpoints"].asInt();
	mCurrentHealthPoints = mMaxHealthPoints;
	mPower = description["power"].asInt();
	mDefense = description["defense"].asInt();
	mSpeed = description["speed"].asInt();

	std::string s = description["type"].asString();
	mType = stringToType(s);

	for (auto attackName : description["attacks"]) {
		mAttackList.push_back(attackName.asString());
	}

}


Pokemon::~Pokemon()
{

}



std::string Pokemon::getName() const
{
	return mName;
}


int Pokemon::getPower() const
{
	return mPower;
}


int Pokemon::getDefense() const
{
	return mDefense;
}


int Pokemon::getSpeed() const
{
	return mSpeed;
}



Type Pokemon::getType() const
{
	return mType;
}


int Pokemon::getHealthPoints() const
{
	return mCurrentHealthPoints;
}


void Pokemon::setHealthPoints(int healthPoints)
{
	mCurrentHealthPoints = healthPoints;
}



std::string Pokemon::selectAttack() const
{
	int idx = 0;
	int userInput;
	for (auto &attackName : mAttackList)
	{
		std::cout << idx+1 << " : " << attackName << std::endl;
		idx++;
	}
	std::cin >> userInput;
	return mAttackList[userInput-1];
}


std::string Pokemon::selectRandomAttack() const
{
	int idx = rand() % mAttackList.size();

	return mAttackList[idx];
}