#include "Game.hpp"
#include "config.hpp"

#include <jsoncpp/json/json.h>
#include <fstream>
#include <iostream>


Game::Game()
{
    Json::Reader reader;
    Json::Value root;

    //build list of known pokemon    
    std::ifstream pokemonListFile(gPokemonListPath);
    reader.parse(pokemonListFile, root);
    for (auto desc : root["Pokemons"]){
        Pokemon pokemon(desc);
        mPokemonList.push_back(pokemon);
    }

    //build list of known attacks
    std::ifstream attackListFile(gAttackListPath);
    reader.parse(attackListFile, root);
    for (auto desc : root["Attacks"]){
        Attack attack(desc);
        mAttackList.push_back(attack);
    }

    mHumanPlayer = Player(mPokemonList);
    mEnemyPlayer = Player(mPokemonList);

    mBattleResolver = Battle(mAttackList);

    mainMenu();
}



Game::~Game()
{
}


void Game::printGameInfo()
{
    std::cout << "Welcome to the PokeGame by Ruben van der Waal\n"
              << "This game was made for a coding challenge by Avonics B.V.\n"
              << "Please Enjoy!" << std::endl;
}



int Game::mainMenu()
{

    printGameInfo();

    bool exit = false;
    char userInput;
    while (!exit){

        std::cout << "Pick a pokemon to fight with by entering their index!" << std::endl;
        mHumanPlayer.selectPokemon();
        
        std::cout << "Pick a pokemon to fight against by entering their index!" << std::endl;
        mEnemyPlayer.selectPokemon();
        
        mBattleResolver.run(mHumanPlayer, mEnemyPlayer);


        std::cout << "Would you like to quit? (y/n)" << std::endl;
        std::cin >> userInput;
        if (userInput == 'y' || userInput == 'Y')
            exit = true;
    }
    return 0;
}




int main()
{
    Game g = Game();

    return 0;
}
