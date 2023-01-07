#ifndef CARD_HPP
#define CARD_HPP

#include <iostream>

enum Suit
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS
};

enum Rank
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGTH,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

class Card
{
private:
    Suit suit;
    Rank rank;

public:
    Card(Suit s, Rank r);
    Suit getSuit();
    Rank getRank();
    int getValue() const;
};

#endif /* CARD_HPP */