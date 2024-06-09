#pragma once

#include "Deck.h"
#include "Player.h"

class Game {
public:
    Game();
    void play();

private:
    Deck deck;
    Player player;
    Player dealer;

    void playRound();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    void clearHands();
};