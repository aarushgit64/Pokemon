#include "Game.hpp"
#include "ProfessorOak.hpp"
#include "Player.hpp"
#include <iostream>
#include <limits>

using namespace std;




void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void waitForEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

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
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
        case 1:
            player.choosePokemon(1);
            player.chosenPokemon->attack();
            waitForEnter();
            break;
        case 2:
            cout << "You head to the PokeCenter, but Nurse Joy is on break.\n";
            waitForEnter();
            break;
        case 3:
            cout << "You try to challenge a Gym, but it's closed for renovations.\n";
            waitForEnter();
            break;
        case 4:
            cout << "You approach the Pokémon League... but the gatekeeper says you're not ready yet.\n";
            waitForEnter();
            break;
        case 5:
            keepPlaying = false;
            cout << "Goodbye, " << player.name << "! Thanks for playing.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            waitForEnter();
            break;
        }
    }
}

