#include <algorithm>
#include <random>
#include "Deck.hpp"

Deck::Deck() 
{
    // TODO:MAKE THIS POSSIBLE FOR MULTIPLE DECKS

    // initialize the deck with one of each card
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            cards.push_back(Card(static_cast<Suit>(i), static_cast<Rank>(j)));
        }
    }
}

void Deck::shuffle()
{
    std::shuffle(this->cards.begin(), this->cards.end(), std::random_device());
}

Card Deck::dealCard()
{
    /* get a better way of doing this!! */
    if (this->cards.size() <= 0)
    {
        std::cerr << "Deck size has reached less than or below 0\n";
    }

    Card dealt = this->cards.back();
    this->cards.pop_back();

    return dealt;
}