#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include <memory>
#include "Deck.hpp"
#include "Hand.hpp"

class Blackjack
{
private:
    std::string playerName;
    int playerChips;
    int betAmount;
    Deck deck;
    std::unique_ptr<Hand> player;
    std::unique_ptr<Hand> dealer;
    void playerTurn();
    void dealerTurn();
    void determineWinner();
    int placeBet();

public:
    Blackjack(std::string name);
    void play();
};

#endif /* BLACKJACK_HPP */