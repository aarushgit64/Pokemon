#include "Game.hpp"
#include "ProfessorOak.hpp"
#include "Player.hpp"
#include <iostream>

int main() {
    ProfessorOak professor("Professor Oak");
    Player player("Ash", Pokemon("Pikachu", PokemonType::ELECTRIC, 100));
    Game game;

    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    professor.explainMainQuest(player);
    game.startGame();
    gameLoop(player);

    return 0;
}










