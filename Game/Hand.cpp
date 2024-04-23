#include <iostream>
#include <utility>

#include "Hand.hpp"

Hand::Hand() : Hand("Dealer") {}

Hand::Hand(std::string name) : name(std::move(name)) {}

void Hand::addCard(Card c, bool printCards)
{
    cards.push_back(c);

    if (printCards)
    {
        printHand();
    }
}

void Hand::clearHand()
{
    cards.clear();
}

void Hand::pop()
{
    cards.pop_back();
}

[[nodiscard]] int Hand::getTotal() const
{
    int total = 0;

    for (const auto &card : cards)
    {
        total += card.getValue();
    }

    return total;
}

void Hand::printHand() const
{
    std::cout << name << "'s total: " << getTotal() << "\n";

    for (size_t i = 0; i < cards.size(); i++)
    {
        std::cout << " _____   ";
    }
    std::cout << "\n";

    for (const auto &card : cards)
    {
        std::cout << "|" << card.getRank() << "    |  ";
    }
    std::cout << "\n";

    for (const auto &card : cards)
    {
        std::cout << "|  " << card.getSuit() << "  |  ";
    }
    std::cout << "\n";

    for (const auto &card : cards)
    {
        std::cout << "|    " << card.getRank() << "|  ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < cards.size(); i++)
    {
        std::cout << " ‾‾‾‾‾   ";
    }
    std::cout << "\n";
}
