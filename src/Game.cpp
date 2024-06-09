#include <iostream>

#include "Game.h"

Game::Game() {
}

void Game::play() {
    deck = Deck();
    player = Player();
    dealer = Player();

    while (true) {
        playRound();
        char choice;
        std::cout << "Would you like to play again? (y/n) ";
        std::cin >> choice;
        if (choice != 'y') {
            break;
        }
    }
}

void Game::playRound() {
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    playerTurn();
    if (!player.isBusted()) {
        dealerTurn();
    }
    determineWinner();
    clearHands();
}

void Game::clearHands() {
    player.clearHand();
    dealer.clearHand();
}

void Game::playerTurn() {
    std::cout << "Your hand: \n";
    player.displayHand();

    char choice;
    do {
        std::cout << "Score: " << player.calculateScore() << std::endl;
        std::cout << "Would you like to Hit (h) or Stand (s)? ";
        std::cin >> choice;
        if (choice == 'h') {
            player.addCard(deck.dealCard());
            player.displayHand();
        }
    } while (choice == 'h' && !player.isBusted());
}

void Game::dealerTurn() {
    while (dealer.calculateScore() < 17) {
        dealer.addCard(deck.dealCard());
    }
}

void Game::determineWinner() {
    int playerScore = player.calculateScore();
    int dealerScore = dealer.calculateScore();

    std::cout << "Dealer's hand: \n";
    dealer.displayHand();
    std::cout << "Dealer's score: " << dealerScore << std::endl;

    if (player.isBusted()) {
        std::cout << "You busted! Dealer wins!" << std::endl;
    } else if (dealer.isBusted()) {
        std::cout << "Dealer busted! You win!" << std::endl;
    } else if (playerScore > dealerScore) {
        std::cout << "You win!" << std::endl;
    } else if (playerScore < dealerScore) {
        std::cout << "Dealer wins!" << std::endl;
    } else {
        std::cout << "Stand!" << std::endl;
    }
}