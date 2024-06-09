#include "Deck.h"

#include <algorithm>
#include <random>

Deck::Deck() {
    initialiseDeck();
    shuffle();
}

void Deck::initialiseDeck() {
    cards.clear();
    static constexpr int NUMDECKS = 4;
    for (int _ = 0; _ < NUMDECKS; _++) {
        for (int suit = static_cast<int> (Suit::Hearts); suit <= static_cast<int> (Suit::Spades); suit++) {
            for (int rank = static_cast<int> (Rank::Ace); rank <= static_cast<int> (Rank::King); rank++) {
                cards.emplace_back(Card(static_cast<Rank> (rank), static_cast<Suit> (suit)));
            }
        }
    }
}

void Deck::shuffle() {
    std::shuffle(cards.begin(), cards.end(), std::random_device());
}

Card Deck::dealCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}