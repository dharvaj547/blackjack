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
    std::string playerName;

public:
    Blackjack(std::string name);
    void play();
    int placeBet();
    void playerTurn();
    void dealerTurn();
    void determineWinner(int bet);
};

#endif /* BLACKJACK_HPP */