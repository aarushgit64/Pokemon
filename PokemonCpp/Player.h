#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "Pokemon.hpp"

class Player {
public:
    Pokemon chosenPokemon;
    Player() : chosenPokemon("Default", 100) {}
};

#endif