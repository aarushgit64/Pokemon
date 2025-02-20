#ifndef BATTLESTATE_HPP
#define BATTLESTATE_HPP

#include "Pokemon.hpp"

struct BattleState {
    Pokemon* playerPokemon;
    Pokemon* wildPokemon;
    bool playerTurn;
    bool battleOngoing;

    BattleState(Pokemon* pPokemon, Pokemon* wPokemon)
        : playerPokemon(pPokemon), wildPokemon(wPokemon), playerTurn(true), battleOngoing(true) {
    }
};

#endif
