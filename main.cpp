#include <iostream>
// #include "Game/Card.hpp"
// #include "Game/Deck.hpp"
// #include "Game/Hand.hpp"
#include "Game/Blackjack.hpp"

int main(int argc, char const *argv[]) {
    std::cout << "Please enter your name: ";
    std::string name;
    std::cin >> name;
    
    std::cout << "-----------------------------------------------\n";
    std::cout << " _____   _____  _____  _____  " << std::endl <<
                 "|A    | |A    ||A    ||A    | " << std::endl <<
                 "|  ♠  | |  ♦  ||  ♣  ||  ♥  | " << std::endl <<
                 "|    A| |    A||    A||    A| " << std::endl <<
                 " ‾‾‾‾‾   ‾‾‾‾‾  ‾‾‾‾‾  ‾‾‾‾‾  " << std::endl;

    std::cout << "Welcome to the table " << name << "!\n\n";

    Blackjack game(name);

    // initalise classes Blackjack game; etc...
    // game loop while the 'q' button is not pressed.
    // game.play();

    // TODO: add option to quit game when 'q' is pressed
    while (true) 
    {
        game.play();
    }

    return 0;
}