#pragma once


#include "Pokemon.hpp"
#include "Attack.hpp"
#include "Battle.hpp"

#include <vector>
#include <string>





class Game
{
public:
    Game();
    ~Game();
private:
    int mainMenu();
    void printGameInfo();

    std::vector<Pokemon> mPokemonList;
    std::vector<Attack> mAttackList;

    Player mHumanPlayer;
    Player mEnemyPlayer;

    Battle mBattleResolver;
};


