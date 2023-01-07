#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <vector>
#include "Card.hpp"

class Deck
{
private:
  std::vector<Card> cards;

public:
  Deck();
  void shuffle();
  Card dealCard();
};

#endif /* DECK_HPP */