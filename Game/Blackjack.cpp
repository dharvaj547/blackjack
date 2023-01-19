#include <iostream>
#include "Blackjack.hpp"

Blackjack::Blackjack(std::string name)
{
    playerScore = 0;
    dealerScore = 0;
    playerChips = 500000;
    playerName = name;
}

void Blackjack::play()
{
    // TODO: account for aces

    std::cout << "-----------------------------------------------\n\n";

    // placeBet();
    // TODO: error check that bet is not negative or more than available chips
    std::cout << "Place your bet. Your current amount is " << playerChips << " chips left: ";
    int bet;
    std::cin >> bet;
    playerChips -= bet;
    std::cout << "Your bet is " << bet << ". You have " << playerChips << " chips remaining.\n\n";

    player.clearHand();
    dealer.clearHand();

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    // print player cards and dealer cards
    std::cout << "Dealer has 1 face down card + ";
    dealer.printHand();
    std::cout << "Dealer's total: " << dealer.getTotal() << "\n\n";

    std::cout << playerName << " drew: ";
    player.printHand();
    std::cout << "Your total: " << player.getTotal() << "\n";

    if (player.getTotal() == 21)
    {
        determineWinner(bet);
        return;
    }

    while (player.getTotal() < 21)
    {
        // prompt player to hit or stand
        std::cout << "Would you like to hit (h) or stand (s)? ";
        char move;
        std::cin >> move;

        if (move == 'h')
        {
            // playerTurn();
            player.addCard(deck.dealCard());
            std::cout << "\n"
                      << playerName << " drew: ";
            player.printHand();
            std::cout << "Your total: " << player.getTotal() << "\n";
        }
        else
        {
            break;
        }
    }

    if (player.getTotal() > 21)
    {
        std::cout << "\nYou busted! Dealer wins.\n";
        return;
    }

    dealerTurn();

    determineWinner(bet);
}

void Blackjack::playerTurn()
{
}

void Blackjack::dealerTurn()
{
    std::cout << "\n";

    while (dealer.getTotal() < 17)
    {
        dealer.addCard(deck.dealCard());
        std::cout << "Dealer drew: ";
        dealer.printHand();
        std::cout << "Dealer's total: " << dealer.getTotal() << "\n";
    }
}

void Blackjack::determineWinner(int bet)
{
    // dealer busts
    if (dealer.getTotal() > 21) {
        std::cout << "\nYou won! Dealer busts.\n";
        playerChips += bet * 2;
    }
    // player's hand is higher than dealer's hand
    else if (player.getTotal() > dealer.getTotal())
    {
        std::cout << "\nYou won!\n";
        playerChips += bet * 2;
    }
    // draw
    else if (player.getTotal() == dealer.getTotal())
    {
        std::cout << "\nYou drew!\n";
        playerChips += bet;
    }
    // player lost
    else
    {
        std::cout << "\nYou lost!\n";
    }
}