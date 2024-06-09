#pragma once

#include <vector>

#include "Card.h"

class Deck {
public:
    Deck();
    Card dealCard();

private:
    std::vector<Card> cards;

    void initialiseDeck();
    void shuffle();
};
