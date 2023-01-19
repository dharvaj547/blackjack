#include <iostream>
#include "Blackjack.hpp"

Blackjack::Blackjack(std::string name)
{
    playerScore = 0;
    dealerScore = 0;
    playerChips = 10000;
    betAmount = -1;
    playerName = name;
}

void Blackjack::play()
{
    // TODO: account for aces

    std::cout << "------------------------------------------------------------\n\n";
    betAmount = placeBet();

    player.clearHand();
    dealer.clearHand();

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    dealer.addCard(deck.dealCard());

    // show cards
    dealer.printFirstHand();
    player.printHand(playerName);

    // check player for blackjack
    // if (player.getTotal() == 21)
    // {
    //     determineWinner();
    //     return;
    // }

    playerTurn();

    // check for bust
    if (player.getTotal() > 21)
    {
        std::cout << "You busted! Dealer wins.\n";
        return;
    }

    dealerTurn();
    determineWinner();
}

int Blackjack::placeBet()
{
    // ask user to place bet
    std::cout << "Place your bet. Your current amount is " << playerChips << " chips left: ";
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
    while (player.getTotal() <= 21)
    {
        if (player.getTotal() == 21) {
            break;
        }

        // prompt player to hit, stand, or double down
        std::cout << "Would you like to hit (h) or stand (s)? ";
        char move;
        std::cin >> move;

        // if player hits
        if (move == 'h')
        {
            player.addCard(deck.dealCard());
        }
        // if player doubles down
        else if (move == 'd') 
        {
            player.addCard(deck.dealCard());
            player.printHand(playerName);
            betAmount *= 2;
            break;
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
        dealer.printHand();
    }
}

void Blackjack::determineWinner()
{
    // dealer busts
    if (dealer.getTotal() > 21)
    {
        std::cout << "You won! Dealer busts.\n";
        playerChips += betAmount * 2;
    }
    // player's hand is higher than dealer's hand
    else if (player.getTotal() > dealer.getTotal())
    {
        std::cout << "You won!\n";
        playerChips += betAmount * 2;
    }
    // player lost
    else if (player.getTotal() < dealer.getTotal())
    {
        std::cout << "You lost!\n";
    }
    // draw
    else
    {
        std::cout << "You drew!\n";
        playerChips += betAmount;
    }
}