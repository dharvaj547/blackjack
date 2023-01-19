#include <iostream>
#include "Game/Blackjack.hpp"

int main(int argc, char const *argv[])
{
    // TODO: add support to exit game loop
    // TODO: account for aces
    // TODO: add ability to split
    
    std::cout << "NOTE: press ctrl+c to exit anytime\n";
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "------------------------------------------------------------\n";
    std::cout << " _____   _____  _____  _____  " << std::endl
              << "|A    | |A    ||A    ||A    | " << std::endl
              << "|  ♠  | |  ♦  ||  ♣  ||  ♥  | " << std::endl
              << "|    A| |    A||    A||    A| " << std::endl
              << " ‾‾‾‾‾   ‾‾‾‾‾  ‾‾‾‾‾  ‾‾‾‾‾  " << std::endl;
    std::cout << "Welcome to the table " << name << "!\n\n";

    Blackjack game(name);

    while (true)
    {
        std::cout << "------------------------------------------------------------\n\n";
        game.play();
    }

    return 0;
}