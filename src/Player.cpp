#include <iostream>

#include "Player.h"

Player::Player() {
}

void Player::addCard(const Card& card) {
    hand.push_back(card);
}

int Player::calculateScore() const {
    int score = 0;
    int numAces = 0;

    for (const Card& card : hand) {
        int value = card.getValue();
        score += value;

        if (value == 11) {
            numAces++;
        }
    }

    while (score > 21 && numAces > 0) {
        score -= 10;
        numAces--;
    }

    return score;
}

bool Player::isBusted() const {
    return calculateScore() > 21;
}

void Player::clearHand() {
    hand.clear();
}

void Player::displayHand() const {
    // print cards in the following format:
    //  _____    _____
    // |K    |  |A    |
    // |  ♦  |  |  ♦  |
    // |    K|  |    A|
    //  ‾‾‾‾‾    ‾‾‾‾‾

    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << " _____   ";
    }
    std::cout << "\n";

    for (const auto &card : hand) {
        std::cout << "|" <<  card.rankToString() << "    |  ";
    }
    std::cout << "\n";

    for (const auto &card : hand) {
        std::cout << "|  " <<  card.suitToString() << "  |  ";
    }
    std::cout << "\n";

    for (const auto &card : hand) {
        std::cout << "|    " <<  card.rankToString() << "|  ";
    }
    std::cout << "\n";

    for (size_t i = 0; i < hand.size(); i++) {
        std::cout << " ‾‾‾‾‾   ";
    }
    std::cout << "\n";
}
