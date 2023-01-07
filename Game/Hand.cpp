#include "Hand.hpp"

Hand::Hand() {}

void Hand::addCard(Card c)
{
    cards.emplace_back(c);
}

int Hand::getTotal() const
{
    int total = 0;

    for (const auto& card : cards) {
        total += card.getValue();
    }

    return total;
}