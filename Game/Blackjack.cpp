#include <iostream>
#include "Blackjack.hpp"

Blackjack::Blackjack(const std::string& name)
{
    playerChips = 10000;
    betAmount = -1;
    player = Hand(name);
}

void Blackjack::play()
{
    player.clearHand();
    dealer.clearHand();
    betAmount = placeBet();

    // deal starting cards
    Card faceDownCard(Suit::FACEDOWNSUIT, Rank::FACEDOWNRANK);
    dealer.addCard(deck.getDealCard());
    dealer.addCard(faceDownCard, true);
    dealer.pop();  // remove face down card
    player.addCard(deck.getDealCard());
    player.addCard(deck.getDealCard(), true);

    // pleminary check for blackjack
    if (player.getTotal() == 21)
    {
        determineWinner();
        return;
    }

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
    while (player.getTotal() < 21)
    {
        if (player.getTotal() == 21)
            break;

        // prompt player to hit, stand, or double down
        std::cout << "Would you like to hit (h), stand (s), or double down (d)? ";
        char move;
        std::cin >> move;

        // player hits
        if (move == 'h')
        {
            player.addCard(deck.getDealCard(), true);
        }
        // player doubles down
        else if (move == 'd')
        {
            player.addCard(deck.getDealCard(), true);
            playerChips -= betAmount;
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
        dealer.addCard(deck.getDealCard(), true);
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
    std::cout << "Your balance: $" << playerChips << "\nPlace your bet: $";
    std::cin >> betAmount;

    // error check. keep asking until user enters a valid amount
    while (betAmount <= 0 || betAmount > playerChips)
    {
        std::cout << "Please place a valid bet amount: ";
        std::cin >> betAmount;
    }

    playerChips -= betAmount;
    std::cout << "\nYou have $" << betAmount << " remaining.\n\n";

    return betAmount;
}