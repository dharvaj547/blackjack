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

public:
    Blackjack();
    void play();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
};

#endif /* BLACKJACK_HPP */