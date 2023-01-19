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
    int betAmount = placeBet();

    player.clearHand();
    dealer.clearHand();
    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    // show dealer's cards
    std::cout << "Dealer has 1 face down card + ";
    dealer.printHand();
    std::cout << "Dealer's total: " << dealer.getTotal() << "\n\n";

    // show player's cards
    // std::cout << playerName << " drew: ";
    player.printHand(playerName);
    std::cout << "Your total: " << player.getTotal() << "\n";

    // check for blackjack
    if (player.getTotal() == 21)
    {
        determineWinner(betAmount);
        return;
    }

    playerTurn();

    // check for bust
    if (player.getTotal() > 21)
    {
        std::cout << "\nYou busted! Dealer wins.\n";
    }
    // else let dealer play
    else
    {
        dealerTurn();
        determineWinner(betAmount);
    }
}

int Blackjack::placeBet()
{
    // ask user to place bet
    std::cout << "Place your bet. Your current amount is " << playerChips << " chips left: ";
    int betAmount;
    std::cin >> betAmount;

    // error check. keep asking until user enters a valid amount
    while (betAmount <= 0 || betAmount > playerChips)
    {
        std::cout << "Please place a valid bet amount: ";
        std::cin >> betAmount;
    }

    playerChips -= betAmount;
    std::cout << "You bet " << betAmount << ". You have " << playerChips << " chips remaining.\n\n";

    return betAmount;
}

void Blackjack::playerTurn()
{
    while (player.getTotal() < 21)
    {
        // prompt player to hit or stand
        std::cout << "Would you like to hit (h) or stand (s)? ";
        char move;
        std::cin >> move;

        // if player hits
        if (move == 'h')
        {
            player.addCard(deck.dealCard());
            // std::cout << "\n" << playerName << " drew: ";
            player.printHand(playerName);
            std::cout << "Your total: " << player.getTotal() << "\n";
        }
        // if player stands
        else
        {
            break;
        }
    }
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

void Blackjack::determineWinner(int betAmount)
{
    // dealer busts
    if (dealer.getTotal() > 21)
    {
        std::cout << "\nYou won! Dealer busts.\n";
        playerChips += betAmount * 2;
    }
    // player's hand is higher than dealer's hand
    else if (player.getTotal() > dealer.getTotal())
    {
        std::cout << "\nYou won!\n";
        playerChips += betAmount * 2;
    }
    // draw
    else if (player.getTotal() == dealer.getTotal())
    {
        std::cout << "\nYou drew!\n";
        playerChips += betAmount;
    }
    // player lost
    else
    {
        std::cout << "\nYou lost!\n";
    }
}