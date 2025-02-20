#ifndef BATTLEMANAGER_HPP
#define BATTLEMANAGER_HPP

#include "Pokemon.hpp"
#include "Player.hpp"
#include "BattleState.hpp"

class BattleManager {
private:
    BattleState* battleState;

public:
    BattleManager();
    ~BattleManager();
    void startBattle(Player& player, Pokemon& wildPokemon);
    void battle();
    void updateBattleState();
    void handleBattleOutcome();
};

#endif