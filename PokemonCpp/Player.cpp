#include "Player.hpp"
#include <iostream>

Player::Player() : name("Trainer"), chosenPokemon(nullptr) {}

Player::Player(const std::string& p_name, Pokemon* p_chosenPokemon)
    : name(p_name), chosenPokemon(p_chosenPokemon) {
}

Player::~Player() {
    delete chosenPokemon;
}

void Player::choosePokemon(int choice) {
    switch (choice) {
    case 1:
        chosenPokemon = new Pokemon("Charmander", PokemonType::FIRE, 100);
        break;
    case 2:
        chosenPokemon = new Pokemon("Bulbasaur", PokemonType::GRASS, 100);
        break;
    case 3:
        chosenPokemon = new Pokemon("Squirtle", PokemonType::WATER, 100);
        break;
    default:
        chosenPokemon = new Pokemon("Pikachu", PokemonType::ELECTRIC, 100);
        break;
    }
    std::cout << "Player " << name << " chose " << chosenPokemon->name << "!\n";
}
