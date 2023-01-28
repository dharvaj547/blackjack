#ifndef DECK_HPP
#define DECK_HPP

#define NUMDECKS 4

#include <vector>
#include "Card.hpp"

class Deck
{
private:
  std::vector<Card> cards;
  void shuffle();

public:
  Deck();
  Card getDealCard();
};

#endif /* DECK_HPP */