#include "Card.hpp"

Card::Card(Suit s, Rank r) : suit(s), rank(r) { }

Suit Card::getSuit() const { return suit; }

Rank Card::getRank() const { return rank; }

std::string Card::getSuitString() const { return suit_strings[suit]; }

std::string Card::getRankString() const { return rank_strings[rank]; }

int Card::getValue() const
{
    // aces are worth 1 or 11 points
    if (rank == ACE)
        return 11;
    // face cards are worth 10 points
    else if (rank >= JACK)
        return 10;
    // all other cards are worth their face value
    else
        return static_cast<int>(rank) + 1;
}

std::ostream &operator<<(std::ostream &os, const Card &c)
{
    os << c.getRankString() << " of " << c.getSuitString();
    return os;
}
