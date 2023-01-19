#ifndef CARD_HPP
#define CARD_HPP

#include <ostream>

enum Suit
{
    SPADES,
    HEARTS,
    CLUBS,
    DIAMONDS
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
    KING
};

const std::string suit_strings[] = {"Spades",
                                    "Hearts",
                                    "Diamonds",
                                    "Clubs"};
                                    
const std::string rank_strings[] = {"A",
                                    "2",
                                    "3",
                                    "4",
                                    "5",
                                    "6",
                                    "7",
                                    "8",
                                    "9",
                                    "10",
                                    "J",
                                    "Q",
                                    "K"};

class Card
{
public:
    Card(Suit s, Rank r);
    Suit getSuit() const;
    Rank getRank() const;
    std::string getSuitString() const;
    std::string getRankString() const;
    int getValue() const;

private:
    Suit suit;
    Rank rank;
};

std::ostream &operator<<(std::ostream &os, const Card &c);

#endif /* CARD_HPP */