#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <iostream>
#include "Deck.hpp"
#include "Hand.hpp"

class Blackjack
{
private:
    Deck deck;
    Hand player;
    Hand dealer;
    int playerScore;
    int dealerScore;
    int playerChips;
    int betAmount;
    std::string playerName;

public:
    Blackjack(std::string name);
    void play();
    int getBet();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
};

#endif /* BLACKJACK_HPP */