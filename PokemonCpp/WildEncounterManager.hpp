#pragma once
#include "PokemonType.hpp"
#include <string>
using namespace std;

class Pokemon {
public:
    string name;
    PokemonType type;
    int health;
    Pokemon() : name("Unknown"), type(PokemonType::NORMAL), health(50) {}
    Pokemon(string p_name, PokemonType p_type, int p_health) : name(p_name), type(p_type), health(p_health) {}
    void attack() { cout << name << " attacks with a powerful move!\n"; }
};

class WildEncounterManager {
public:
    Pokemon getRandomPokemonFromGrass() {
        return Pokemon("Pidgey", PokemonType::NORMAL, 30); // Placeholder
    }
};
