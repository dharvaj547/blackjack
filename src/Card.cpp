#include "Card.h"

Card::Card(Rank rank, Suit suit) : rank(rank), suit(suit) {}

int Card::getValue() const {
    if (rank >= Rank::Two && rank <= Rank::Ten) {
        return static_cast<int>(rank);
    } else if (rank >= Rank::Jack && rank <= Rank::King) {
        return 10;
    } else {
        return 11; // Ace can be 1 or 11; handle in game logic
    }
}

std::string Card::rankToString() const {
    switch (rank) {
        case Rank::Ace:
            return "A";
        case Rank::Two:
            return "2";
        case Rank::Three:
            return "3";
        case Rank::Four:
            return "4";
        case Rank::Five:
            return "5";
        case Rank::Six:
            return "6";
        case Rank::Seven:
            return "7";
        case Rank::Eight:
            return "8";
        case Rank::Nine:
            return "9";
        case Rank::Ten:
            return "T";
        case Rank::Jack:
            return "J";
        case Rank::Queen:
            return "Q";
        case Rank::King:
            return "K";
        default:
            return "Invalid rank";
    }
}

std::string Card::suitToString() const {
    switch (suit) {
        case Suit::Hearts:
            return "♥";
        case Suit::Diamonds:
            return "♦";
        case Suit::Clubs:
            return "♣";
        case Suit::Spades:
            return "♠";
        default:
            return "Invalid suit";
    }
}