#include "Attack.hpp"
#include "config.hpp"
#include "Type.hpp"

#include <fstream>
#include <string>



Attack::Attack()
{}


Attack::Attack(Json::Value description)
{
	mName = description["name"].asString();
	mPower = description["power"].asInt();
	mAccuracy = description["accuracy"].asInt();
	mSpecialCost = description["specialCost"].asInt();
	std::string s = description["type"].asString();
	mType = stringToType(s);

}


Attack::~Attack()
{

}



std::string Attack::getName() const
{
	return mName;
}


int Attack::getPower() const
{
	return mPower;
}

int Attack::getAccuracy() const
{
	return mAccuracy;
}


int Attack::getSpecialCost() const
{
	return mSpecialCost;
}



Type Attack::getType() const
{
	return mType;
}