#pragma once

#include <string>

enum Suit
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS,
    FACEDOWNSUIT
};

enum Rank
{
    ACE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    FACEDOWNRANK
};

const std::string suit_strings[] = {"♠",
                                    "♥",
                                    "♦",
                                    "♣",
                                    "?"};

const std::string rank_strings[] = {"A",
                                    "2",
                                    "3",
                                    "4",
                                    "5",
                                    "6",
                                    "7",
                                    "8",
                                    "9",
                                    "T",
                                    "J",
                                    "Q",
                                    "K",
                                    "?"};

class Card
{
public:
    Card(Suit s, Rank r);
    std::string getSuit() const;
    std::string getRank() const;
    int getValue() const;

private:
    Suit suit;
    Rank rank;
};