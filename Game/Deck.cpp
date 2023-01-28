#include <algorithm>
#include <random>
#include "Deck.hpp"

Deck::Deck()
{
    // number of decks
    for (int i = 0; i < NUMDECKS; i++)
    {
        // suit
        for (int j = 0; j < 4; j++)
        {
            // rank
            for (int k = 0; k < 13; k++)
            {
                cards.push_back(Card(static_cast<Suit>(j), static_cast<Rank>(k)));
            }
        }
    }

    shuffle();
}

void Deck::shuffle()
{
    std::shuffle(this->cards.begin(), this->cards.end(), std::random_device());
}

Card Deck::getDealCard()
{
    Card dealt = this->cards.back();
    this->cards.pop_back();

    return dealt;
}