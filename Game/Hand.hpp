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
};

#endif /* HAND_HPP */