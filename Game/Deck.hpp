#pragma once

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