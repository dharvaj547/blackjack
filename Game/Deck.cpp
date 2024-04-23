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
                deck.push_back(Card(static_cast<Suit>(j), static_cast<Rank>(k)));
            }
        }
    }

    shuffle();
}

void Deck::shuffle()
{
    std::shuffle(deck.begin(), deck.end(), std::random_device());
}

Card Deck::getDealCard()
{
    // deal a card from the top of the deck, and the remove it from the deck
    Card dealtCard = deck.back();
    deck.pop_back();

    return dealtCard;
}