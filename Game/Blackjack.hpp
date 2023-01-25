#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "Deck.hpp"
#include "Hand.hpp"

class Blackjack
{
private:
    Deck deck;
    Hand player;
    Hand dealer;
    int playerChips;
    int betAmount;
    std::string playerName;

public:
    Blackjack(std::string name);
    void play();
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    int placeBet();
};

#endif /* BLACKJACK_HPP */