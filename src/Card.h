#pragma once

#include <string>

enum class Suit { Hearts, Diamonds, Clubs, Spades };
enum class Rank { Ace = 1, Two, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King };

class Card {
public:
    Card(Rank rank, Suit suit);
    int getValue() const;
    std::string rankToString() const;
    std::string suitToString() const;

private:
    Rank rank;
    Suit suit;
};