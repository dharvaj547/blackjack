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

void Hand::printHand(std::string name) const
{
    std::cout << name << " drew [";

    for (auto it = cards.begin(); it != cards.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != cards.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "]\n";

    printTotal(name);
}

void Hand::printFirstHand() const 
{
    std::cout << "Dealer drew [";
    std::cout << cards[0];
    std::cout << "] + 1 face down card\n";
    printTotal();
}

void Hand::printTotal(std::string name) const
{
    std::cout << name << "'s total: " << getTotal() << "\n";
}

void Hand::clearHand() 
{
    cards.clear();
}


