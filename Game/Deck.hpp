#ifndef DECK_HPP
#define DECK_HPP

#include <vector>
#include "Card.hpp"

class Deck
{
private:
  std::vector<Card> cards;
  void shuffle();

public:
  Deck();
  Card dealCard();
};

#endif /* DECK_HPP */