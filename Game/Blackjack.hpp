#pragma once

#include <string>

#include "Deck.hpp"
#include "Hand.hpp"

class Blackjack
{
private:
    const std::string playerName;
    int playerChips;
    int betAmount;
    Deck deck;
    Hand player;
    Hand dealer;
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    int placeBet();

public:
    explicit Blackjack(const std::string& name);
    void play();
};