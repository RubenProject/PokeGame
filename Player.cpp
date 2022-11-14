#include "Player.hpp"

#include <iostream>



Player::Player(){}


Player::Player(std::vector<Pokemon> pokemonList)
{
	mPokemonList = pokemonList;
}


Player::~Player(){}


std::string Player::getActivePokemonName() const
{
	return mActivePokemon->getName();
}


bool Player::selectPokemon()
{
	int userInput;
	bool found = false;
	while (!found) {
		printAllPokemon();
		std::cin >> userInput;

		if (mPokemonList[userInput-1].getHealthPoints() == 0){
			std::cout << "Pokemon has no HP left!" << std::endl;
		} else {
			found = true;
		}
	}	
	
	mActivePokemon = &mPokemonList[userInput-1];
	return true;
}


void Player::printAllPokemon() const
{
    int idx = 0;
    for (const auto &pokemon : mPokemonList)
    {
        std::cout << idx + 1 << " : " << pokemon.getName() << " , hp: " << pokemon.getHealthPoints() << std::endl;
        idx++;
    }
}


bool Player::isDefeated() const
{
	return mActivePokemon->getHealthPoints() == 0;
}


Pokemon* Player::getActivePokemon()
{
	return mActivePokemon;
}