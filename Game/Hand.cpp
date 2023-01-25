#include <iostream>
#include "Hand.hpp"

Hand::Hand() {}

void Hand::addCard(Card c)
{
    cards.push_back(c);
}

void Hand::clearHand()
{
    cards.clear();
}

int Hand::getTotal() const
{
    int total = 0;

    for (const auto &card : cards)
    {
        total += card.getValue();
    }

    return total;
}

void Hand::printHand(std::string name) const
{
    std::cout << name << "'s total: " << getTotal() << "\n";

    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << " _____   ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|" << card.getRankString() << "    |  ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|  " << card.getSuitString() << "  |  ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|    " << card.getRankString() << "|  ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << " ‾‾‾‾‾   ";
    }
    std::cout << std::endl;
}
