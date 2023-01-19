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
    void printHand();
    void clearHand();
};

#endif /* HAND_HPP */