#include "Battle.hpp"


#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>


Battle::Battle(std::vector<Attack> attackList){
	mAttackList = attackList;
	srand(time(NULL));
}

Battle::Battle(){}


Battle::~Battle(){}



void Battle::run(Player &humanPlayer, Player &enemyPlayer)
{
	int round = 0;
	char userInput;
	std::string attackName;
	Attack attack;

	while (!humanPlayer.isDefeated() && !enemyPlayer.isDefeated() ){
		std::cout << "===========================" << std::endl;
		std::cout << "Round: " << round << std::endl;

		std::cout << "You currently have " << humanPlayer.getActivePokemon()->getName() << " selected.\n"
				  << "Would you like to swap? (y/n)" << std::endl;
		std::cin >> userInput;
		if (userInput == 'Y' || userInput == 'y'){
			std::cout << "Pick a pokemon to fight with by entering their index!" << std::endl;
			humanPlayer.selectPokemon();
		}

		std::cout << "What Attack would you like to use?" << std::endl;
		attackName = humanPlayer.getActivePokemon()->selectAttack();

		attack = getAttackByName(attackName);

		std::cout << "Your " << humanPlayer.getActivePokemon()->getName() << " used: " << attackName << std::endl;
		
		resolveAttack(humanPlayer, enemyPlayer, attack);

		if (!enemyPlayer.isDefeated()){

			attackName = enemyPlayer.getActivePokemon()->selectRandomAttack();

			std::cout << "Enemy " << enemyPlayer.getActivePokemon()->getName() << " used: " << attackName << std::endl;
			attack = getAttackByName(attackName);

			resolveAttack(enemyPlayer, humanPlayer, attack);
		}

		std::cout << "Enemy " << enemyPlayer.getActivePokemon()->getName() <<  " has: " << enemyPlayer.getActivePokemon()->getHealthPoints() << " HP left." << std::endl;
		std::cout << "Your " << humanPlayer.getActivePokemon()->getName() << " has: " << humanPlayer.getActivePokemon()->getHealthPoints() << " HP left." << std::endl;
		round++;

	}

	if (humanPlayer.isDefeated()) {
		std::cout << "You lost!" << std::endl;
	}

	if (enemyPlayer.isDefeated()) {
		std::cout << "You won!" << std::endl;
	}
}


Attack Battle::getAttackByName(const std::string &attackName){
	for (Attack attack : mAttackList) {
		if (attackName == attack.getName())
			return attack;
	}
	std::cout << "system failure" << std::endl;
	return Attack();
}


void Battle::resolveAttack(Player player1, Player player2, Attack attack)
{
	// Raw damage
	int damage, pokemonPower, attackPower, pokemonDefense;

	pokemonPower = player1.getActivePokemon()->getPower();
	pokemonDefense = player2.getActivePokemon()->getDefense();
	attackPower = attack.getPower();

	damage = pokemonPower + attackPower - pokemonDefense;


	// Multiplier
	Type attackType, defenseType;
	attackType = attack.getType();
	defenseType = player2.getActivePokemon()->getType();

	float multiplier = 1.0f;
	if (attackType == Type::PHYSICAL) {}
		
	if (attackType == Type::FIRE){
		if (defenseType == Type::ICE)
			multiplier = 2.0f;
		if (defenseType == Type::GRASS)
			multiplier = 2.0f;
		if (defenseType == Type::WATER)
			multiplier = 0.5f;
	} 
	if (attackType == Type::WATER){
		if (defenseType == Type::GRASS)
			multiplier = 0.5f;
		if (defenseType == Type::FIRE)
			multiplier = 2.0f;
	}
	if (attackType == Type::ICE){
		if (defenseType == Type::WATER)
			multiplier = 2.0f;
	}
	if (attackType == Type::AIR){
		if (defenseType == Type::FIRE)
			multiplier = 0.5f;
	}
	if (attackType == Type::GRASS){
		if (defenseType == Type::FIRE)
			multiplier = 0.5f;
		if (defenseType == Type::WATER)
			multiplier = 2.0f;
	}
	if (attackType == Type::EARTH){
		if (defenseType == Type::WATER)
			multiplier = 0.5f;

	}

	// hit or miss
	int hitChance, pokemonSpeed, attackAccuracy;
	bool hit = false;
	pokemonSpeed = player2.getActivePokemon()->getSpeed();
	attackAccuracy = attack.getAccuracy();
	hitChance = attackAccuracy - pokemonSpeed;
	hitChance = std::clamp(hitChance, 0, 100);
	//std::cout << "chance to hit: " << hitChance << std::endl;
	

	hit = (rand() % 100) < hitChance;



	// resolve
	int currentHealthPoints;
	if (hit) {
		currentHealthPoints = player2.getActivePokemon()->getHealthPoints();
		currentHealthPoints -= damage * multiplier;
		currentHealthPoints = std::max(0, currentHealthPoints);
		player2.getActivePokemon()->setHealthPoints(currentHealthPoints);
		std::cout << player2.getActivePokemon()->getName() << " took " << damage * multiplier << " damage!" << std::endl;
	} else {
		std::cout << "The Attack was a Miss!" << std::endl;
	}
}