#include <iostream>
#include <string>
#include <limits>
#include "PokemonType.hpp"
#include "PokemonChoice.hpp"
#include "WildEncounterManager.hpp"
#include "Grass.hpp"

using namespace std;

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    (void)system("clear");
#endif
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

class Pokemon {
public:
    string name;
    PokemonType type;
    int health;
    Pokemon() : name("Unknown"), type(PokemonType::NORMAL), health(50) {}
    Pokemon(string p_name, PokemonType p_type, int p_health) : name(p_name), type(p_type), health(p_health) {}
    Pokemon(const Pokemon& other) : name(other.name), type(other.type), health(other.health) {}
    void attack() { cout << name << " attacks with a powerful move!\n"; }
};

class Player {
public:
    string name;
    Pokemon chosenPokemon;
    Player() : name("Trainer"), chosenPokemon(Pokemon()) {}
    Player(string p_name, Pokemon p_chosenPokemon) : name(p_name), chosenPokemon(p_chosenPokemon) {}
    void choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::CHARMANDER: chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 100); break;
        case PokemonChoice::BULBASAUR: chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 100); break;
        case PokemonChoice::SQUIRTLE: chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 100); break;
        default: chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 100); break;
        }
        cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
        waitForEnter();
    }
};

class ProfessorOak {
public:
    string name;
    ProfessorOak(string p_name) { name = p_name; }
    void greetPlayer(Player& player) {
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n"; waitForEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n"; waitForEnter();
        cout << name << ": But enough about me. Let's talk about you!\n"; waitForEnter();
    }
    void offerPokemonChoices(Player& player) {
        cout << name << ": First, tell me, what’s your name? [Enter Your Name]\n";
        getline(cin, player.name);
        cout << name << ": Ah, " << player.name << "! What a fantastic name!\n"; waitForEnter();
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!\n"; waitForEnter();
        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!\n"; waitForEnter();
        cout << "1. Charmander - The fire type. A real hothead!\n2. Bulbasaur - The grass type. Calm and collected!\n3. Squirtle - The water type. Cool as a cucumber!\n";
        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        player.choosePokemon(choice);
    }
    void explainMainQuest(Player& player) {
        clearConsole();
        cout << "Professor Oak: " << player.name << "!, Your adventure is about to begin.\n"; waitForEnter();
        cout << "Professor Oak: Your mission is to collect all Pokémon Badges and conquer the Pokémon League.\n"; waitForEnter();
        cout << player.name << ": Sounds like a walk in the park... right?\n"; waitForEnter();
        cout << "Professor Oak: Hah! That’s what they all say! Beware of the challenges ahead!\n"; waitForEnter();
    }
};

void gameLoop(Player& player) {
    WildEncounterManager encounterManager;
    bool keepPlaying = true;
    while (keepPlaying) {
        clearConsole();
        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n2. Visit PokeCenter\n3. Challenge Gyms\n4. Enter Pokémon League\n5. Quit\nEnter your choice: ";
        int choice;
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        switch (choice) {
        case 1: {
            Pokemon wildPokemon = encounterManager.getRandomPokemonFromGrass();
            cout << "A wild " << wildPokemon.name << " appeared! Prepare for battle!\n";
            wildPokemon.attack();
            break;
        }
        case 2: cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokémon will have to tough it out for now!\n"; break;
        case 3: cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n"; break;
        case 4: cout << "You boldly step towards the Pokémon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n"; break;
        case 5: cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokémon training!'\nAre you sure you want to quit? (y/n): ";
            char quitChoice; cin >> quitChoice; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (quitChoice == 'y' || quitChoice == 'Y') { keepPlaying = false; cout << "Goodbye, " << player.name << "! Thanks for playing!\n"; }
            break;
        default: cout << "That's not a valid choice. Try again!\n"; break;
        }
        waitForEnter();
    }
}



// Assuming classes like ProfessorOak, Player, Game exist

int main() {
    // Create objects dynamically using new
    ProfessorOak* professor = new ProfessorOak("Professor Oak");
    Player* player = new Player("Ash");
    Game* game = new Game();

    // Access methods using pointer notation
    professor->greetPlayer(*player);
    game->startGame();

    // Free memory after use
    delete professor;
    delete player;
    delete game;

    return 0;
}








