#pragma once

#include <vector>

#include "Card.hpp"

class Deck
{
private:
    static constexpr int NUMDECKS = 4;
    std::vector<Card> deck;
    void shuffle();

public:
    Deck();
    Card getDealCard();
};