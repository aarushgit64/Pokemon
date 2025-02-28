#ifndef POKEMON_HPP
#define POKEMON_HPP

#include <string>
#include "PokemonType.hpp"

class Pokemon {
public:
    std::string name;
    PokemonType type;
    int health;

    Pokemon();
    Pokemon(const std::string& p_name, PokemonType p_type, int p_health);
    Pokemon(const Pokemon& other);

    void attack() const;
};

#endif

