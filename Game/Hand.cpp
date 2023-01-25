#include <iostream>
#include "Hand.hpp"

Hand::Hand() : Hand("Dealer") {}

Hand::Hand(std::string name)
{
    this->name = name;
    std::cout << "name: " << this->name << std::endl;
}

void Hand::addCard(Card c, bool printCards)
{
    cards.push_back(c);

    if (printCards)
        printHand();
}

void Hand::clearHand()
{
    cards.clear();
}

void Hand::pop()
{
    cards.pop_back();
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

void Hand::printHand() const
{
    std::cout << name << "'s total: " << getTotal() << "\n";

    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << " _____   ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|" << card.getRank() << "    |  ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|  " << card.getSuit() << "  |  ";
    }
    std::cout << std::endl;

    for (const auto &card : cards) {
        std::cout << "|    " << card.getRank() << "|  ";
    }
    std::cout << std::endl;

    for (size_t i = 0; i < cards.size(); i++) {
        std::cout << " ‾‾‾‾‾   ";
    }
    std::cout << std::endl;
}
