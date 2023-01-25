#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include "Card.hpp"

class Hand
{
private:
    std::vector<Card> cards;

public:
    Hand();
    void addCard(Card c);
    void clearHand();
    int getTotal() const;
    void printHand(std::string = "Dealer") const;
};

#endif /* HAND_HPP */