#pragma once


#include "Attack.hpp"
#include "Player.hpp"

#include <vector>



class Battle
{
public:
	Battle();
	Battle(std::vector<Attack> attackList);
	~Battle();

	void run(Player &human, Player &enemy);
	void resolveAttack(Player player1, Player player2, Attack attack);
private:
	Attack getAttackByName(const std::string &attackName);
	
	std::vector<Attack> mAttackList;
};