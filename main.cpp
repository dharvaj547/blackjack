#include <iostream>
#include "Game/Blackjack.hpp"

int main(int argc, char const *argv[])
{
    std::cout << "\nNOTE: press ctrl+c to exit anytime\n";
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    std::cout << "------------------------------------------------------------------------------------------\n";
    std::cout << " _____   _____  _____  _____  " << std::endl
              << "|A    | |A    ||A    ||A    | " << std::endl
              << "|  ♠  | |  ♦  ||  ♣  ||  ♥  | " << std::endl
              << "|    A| |    A||    A||    A| " << std::endl
              << " ‾‾‾‾‾   ‾‾‾‾‾  ‾‾‾‾‾  ‾‾‾‾‾  " << std::endl;

    Blackjack game(name);

    while (true)
    {
        std::cout << "------------------------------------------------------------------------------------------\n\n";
        game.play();
    }

    return 0;
}