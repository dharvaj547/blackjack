#include "Card.hpp"

Card::Card(Suit s, Rank r) : suit(s), rank(r) {}

Suit Card::getSuit() 
{
    return suit;
}

Rank Card::getRank()
{
    return rank;
}

int Card::getValue() const 
{
    // face cards are worth 10 points
    if (rank >= JACK)
        return 10;
    // aces are worth 1 or 11 points
    else if (rank == ACE)
        return 11;
    // all other cards are worth their face value
    else
        return static_cast<int>(rank) + 2;
}