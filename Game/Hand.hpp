#ifndef HAND_HPP
#define HAND_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"

class Hand
{
private:
    std::vector<Card> cards;

public:
    Hand();
    void addCard(Card c);
    int getTotal() const;
    void printHand(std::string = "Dealer") const;
    void printFirstHand() const;
    void printTotal(std::string = "Dealer") const;
    void clearHand();   
};

#endif /* HAND_HPP */