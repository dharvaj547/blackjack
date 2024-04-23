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

constexpr const char* suit_strings[] = {"♠",
                                        "♥",
                                        "♦",
                                        "♣",
                                        "?"};

constexpr const char* rank_strings[] = {"A",
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
    [[nodiscard]] std::string getSuit() const;
    [[nodiscard]] std::string getRank() const;
    [[nodiscard]] int getValue() const;

private:
    Suit suit;
    Rank rank;
};