#include <iostream>
#include "Card.hpp"

Card::Card(Suit s, Rank r) : suit(s), rank(r) { }

std::string Card::getSuit() const
{
    return suit_strings[suit];
}

std::string Card::getRank() const
{
    return rank_strings[rank];
}

int Card::getValue() const
{
    // facedown cards are worth 0
    if (rank == FACEDOWNRANK)
        return 0;
    // aces are worth 1 or 11 points
    else if (rank == ACE)
        return 11;
    // face cards are worth 10 points
    else if (rank >= JACK)
        return 10;
    // all other cards are worth their face value
    else
        return static_cast<int>(rank) + 1;
}
