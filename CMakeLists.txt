cmake_minimum_required(VERSION 3.27)
project(blackjack_)

set(CMAKE_CXX_STANDARD 20)

add_executable(blackjack_ main.cpp
        src/Game.cpp
        src/Game.h
        src/Player.cpp
        src/Player.h
        src/Deck.cpp
        src/Deck.h
        src/Card.cpp
        src/Card.h)
