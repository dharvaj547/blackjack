#pragma once

#include <vector>

#include "Card.h"

class Player {
public:
    Player();
    void addCard(const Card& card);
    int calculateScore() const;
    bool isBusted() const;
    void displayHand() const;
    void clearHand();

private:
    std::vector<Card> hand;
};