#ifndef HAND_HPP
#define HAND_HPP

#include <vector>
#include <string>
#include "Card.hpp"

class Hand
{
private:
    std::vector<Card> cards;
    std::string name;

public:
    Hand();
    Hand(const std::string& name);
    void addCard(Card c, bool printCards = false);
    void clearHand();
    void pop();
    int getTotal() const;
    void printHand() const;
};

#endif /* HAND_HPP */