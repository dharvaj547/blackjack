cmake_minimum_required(VERSION 3.27)
project(blackjack)

set(CMAKE_CXX_STANDARD 14)

include_directories(Game)

add_executable(blackjack
        Game/Blackjack.cpp
        Game/Blackjack.hpp
        Game/Card.cpp
        Game/Card.hpp
        Game/Deck.cpp
        Game/Deck.hpp
        Game/Hand.cpp
        Game/Hand.hpp
        main.cpp)
