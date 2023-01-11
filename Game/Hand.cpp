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

void Hand::printHand() {
    std::cout << "[";

    for (auto it = cards.begin(); it != cards.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != cards.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";
}


