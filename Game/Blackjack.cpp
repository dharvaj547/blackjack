#include <iostream>
#include "Blackjack.hpp"

Blackjack::Blackjack(std::string name)
{
    playerChips = 10000;
    betAmount = -1;
    playerName = name;
}

void Blackjack::play()
{
    player.clearHand();
    dealer.clearHand();
    betAmount = placeBet();

    // deal starting cards
    Card unknownCard(Suit::UNKNOWNSUIT, Rank::UNKNOWNRANK);
    dealer.addCard(unknownCard);
    dealer.addCard(deck.dealCard());
    dealer.printHand();
    dealer.clearFirstCard(); /* remove the "UNKNOWN" card as it is just for show */

    player.addCard(deck.dealCard());
    player.addCard(deck.dealCard());
    player.printHand(playerName);

    // pleminary check for blackjack
    if (player.getTotal() == 21)
        return;

    playerTurn();

    // check player for bust
    if (player.getTotal() > 21)
    {
        std::cout << "You busted! Dealer wins.\n";
        return;
    }

    dealerTurn();

    determineWinner();
}

void Blackjack::playerTurn()
{
    while (player.getTotal() <= 21)
    {
        if (player.getTotal() == 21)
        {
            player.printHand();
            break;
        }

        // prompt player to hit, stand, or double down
        std::cout << "Would you like to hit (h), stand (s), or double down (d)? ";
        char move;
        std::cin >> move;

        // player hits
        if (move == 'h')
        {
            player.addCard(deck.dealCard());
            player.printHand(playerName);
        }
        // player doubles down
        else if (move == 'd')
        {
            player.addCard(deck.dealCard());
            player.printHand(playerName);
            betAmount *= 2;
            break;
        }
        // player stands
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
        std::cout << "Dealer busts! You win.\n";
        playerChips += betAmount * 2;
    }
    // player wins
    else if (player.getTotal() > dealer.getTotal())
    {
        std::cout << "You win!\n";
        playerChips += betAmount * 2;
    }
    // dealer wins
    else if (player.getTotal() < dealer.getTotal())
    {
        std::cout << "You lose!\n";
    }
    // draw
    else
    {
        std::cout << "You drew! Push.\n";
        playerChips += betAmount;
    }
}

int Blackjack::placeBet()
{
    // ask user to place bet
    std::cout << "You have $" << playerChips << ". How much would you like to bet? ";
    std::cin >> betAmount;

    // error check. keep asking until user enters a valid amount
    while (betAmount <= 0 || betAmount > playerChips)
    {
        std::cout << "Please place a valid bet amount: ";
        std::cin >> betAmount;
    }

    playerChips -= betAmount;
    std::cout << "You bet $" << betAmount << ". You have $" << playerChips << " remaining.\n\n";

    return betAmount;
}