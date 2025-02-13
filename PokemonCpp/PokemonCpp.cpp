#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Function to clear the console
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    (void)system("clear");
#endif
}

// Function to wait for user to press Enter
void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Define an enum for Pokemon choices
enum class PokemonChoice {
    CHARMANDER = 1,
    BULBASAUR,
    SQUIRTLE,
    PIKACHU
};

// Define an enum for Pokemon types
enum class PokemonType {
    FIRE,
    GRASS,
    WATER,
    ELECTRIC,
    NORMAL
};

// Pokemon class definition
class Pokemon {
public:
    string name;
    PokemonType type;
    int health;

    // Default constructor
    Pokemon() {
        name = "Unknown";
        type = PokemonType::NORMAL;
        health = 50;
    }

    // Parameterized constructor
    Pokemon(std::string p_name, PokemonType p_type, int p_health) {
        name = p_name;
        type = p_type;
        health = p_health;
    }

    // Copy constructor
    Pokemon(const Pokemon& other) {
        name = other.name;
        type = other.type;
        health = other.health;
    }

    void attack() { std::cout << name << " attacks with a powerful move!\n"; }
};

// Player class definition
class Player {
public:
    string name;
    Pokemon chosenPokemon;

    // Default constructor
    Player() {
        name = "Trainer";
        chosenPokemon = Pokemon();
    }

    // Parameterized constructor
    Player(std::string p_name, Pokemon p_chosenPokemon) {
        name = p_name;
        chosenPokemon = p_chosenPokemon;
    }

    void choosePokemon(int choice) {
        switch ((PokemonChoice)choice) {
        case PokemonChoice::CHARMANDER:
            chosenPokemon = Pokemon("Charmander", PokemonType::FIRE, 100);
            break;
        case PokemonChoice::BULBASAUR:
            chosenPokemon = Pokemon("Bulbasaur", PokemonType::GRASS, 100);
            break;
        case PokemonChoice::SQUIRTLE:
            chosenPokemon = Pokemon("Squirtle", PokemonType::WATER, 100);
            break;
        default:
            chosenPokemon = Pokemon("Pikachu", PokemonType::ELECTRIC, 100);
            break;
        }
        cout << "Player " << name << " chose " << chosenPokemon.name << "!\n";
        waitForEnter();
    }
};

// ProfessorOak class definition
class ProfessorOak {
public:
    string name;

    // Parameterized constructor
    ProfessorOak(string p_name) { name = p_name; }

    void greetPlayer(Player& player) {
        cout << name << ": Hello there! Welcome to the world of Pokemon!\n";
        waitForEnter();
        cout << name << ": My name is Oak. People call me the Pokemon Professor!\n";
        waitForEnter();
        cout << name << ": But enough about me. Let's talk about you!\n";
        waitForEnter();
    }

    void offerPokemonChoices(Player& player) {
        cout << name << ": First, tell me, what’s your name? [Enter Your Name]\n";
        getline(cin, player.name);
        cout << name << ": Ah, " << player.name << "! What a fantastic name!\n";
        waitForEnter();
        cout << name << ": You must be eager to start your adventure. But first, you’ll need a Pokemon of your own!\n";
        waitForEnter();

        cout << name << ": I have three Pokemon here with me. They’re all quite feisty!\n";
        waitForEnter();
        cout << "1. Charmander - The fire type. A real hothead!\n";
        cout << "2. Bulbasaur - The grass type. Calm and collected!\n";
        cout << "3. Squirtle - The water type. Cool as a cucumber!\n";

        int choice;
        cout << name << ": So, which one will it be? Enter the number of your choice: ";
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        player.choosePokemon(choice);
    }

    void explainMainQuest(Player& player) {
        clearConsole();
        cout << "Professor Oak: " << player.name << "!, Your adventure is about to begin.\n";
        waitForEnter();
        cout << "Professor Oak: Your mission is to collect all Pokémon Badges and conquer the Pokémon League.\n";
        waitForEnter();
        cout << player.name << ": Sounds like a walk in the park... right?\n";
        waitForEnter();
        cout << "Professor Oak: Hah! That’s what they all say! Beware of the challenges ahead!\n";
        waitForEnter();
    }
};

// Function to handle the main game loop
void gameLoop(Player& player) {
    bool keepPlaying = true;

    while (keepPlaying) {
        clearConsole();
        cout << "\nWhat would you like to do next, " << player.name << "?\n";
        cout << "1. Battle Wild Pokémon\n";
        cout << "2. Visit PokeCenter\n";
        cout << "3. Challenge Gyms\n";
        cout << "4. Enter Pokémon League\n";
        cout << "5. Quit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        // Clear input buffer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            cout << "You look around... but all the wild Pokémon are on vacation. Maybe try again later?\n";
            break;
        case 2:
            cout << "You head to the PokeCenter, but Nurse Joy is out on a coffee break. Guess your Pokémon will have to tough it out for now!\n";
            break;
        case 3:
            cout << "You march up to the Gym, but it's closed for renovations. Seems like even Gym Leaders need a break!\n";
            break;
        case 4:
            cout << "You boldly step towards the Pokémon League... but the gatekeeper laughs and says, 'Maybe next time, champ!'\n";
            break;
        case 5:
            cout << "You try to quit, but Professor Oak's voice echoes: 'There's no quitting in Pokémon training!'\n";
            cout << "Are you sure you want to quit? (y/n): ";
            char quitChoice;
            cin >> quitChoice;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            if (quitChoice == 'y' || quitChoice == 'Y') {
                keepPlaying = false;
                cout << "Goodbye, " << player.name << "! Thanks for playing!\n";
            }
            break;
        default:
            cout << "That's not a valid choice. Try again!\n";
            break;
        }

        waitForEnter();
    }
}

int main() {
    // Create a ProfessorOak and Player object
    ProfessorOak professor("Professor Oak");
    Player player;

    // Start the introduction and let the player choose their Pokemon
    professor.greetPlayer(player);
    professor.offerPokemonChoices(player);
    professor.explainMainQuest(player);

    // Start the main game loop
    gameLoop(player);

    return 0;
}





