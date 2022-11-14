#pragma once

#include "Pokemon.hpp"

#include <vector>
#include <string>


class Player
{
public:
	Player();
	Player(std::vector<Pokemon> pokemonList);
	~Player();

	std::string getActivePokemonName() const;
	bool selectPokemon();
	void printAllPokemon() const;
	bool isDefeated() const;
	Pokemon *getActivePokemon();
private:
	std::vector<Pokemon> mPokemonList;
	Pokemon *mActivePokemon;
};