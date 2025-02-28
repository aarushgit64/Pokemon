#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "Pokemon.hpp"

class Player {
public:
    std::string name;
    Pokemon* chosenPokemon;

    Player();
    Player(const std::string& p_name, Pokemon* p_chosenPokemon);
    ~Player();

    void choosePokemon(int choice);
};

#endif
