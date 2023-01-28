# Blackjack game
Blakcjack game written in C++.

# Running
Ensure that you are running at least C++11 

Clone the repository

Open terminal and navigate to the project

Run ```make play``` in terminal to play the game

Errors caused here are most likely caused by the Makefile. Read "Makefile for macOS and windows" for fixes.  

# Makefile for macOS and windows
The given Makefile is for windows system (as I use a windows laptop). If you are on a mac, your Makefile may look something like 
```
CXX = g++
CXXFLAGS = -Wall -g
SOURCES = main.cpp Game/*.cpp
HEADERS = Game/*.hpp

all: blackjack

blackjack: main.cpp $(SOURCES) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o blackjack $(SOURCES)

play: clean blackjack
	./blackjack play

clean:
	rm -f blackjack
```
Note that ```CXX = g++``` is actually ```CXX = g++-11``` on my mac laptop as this ensures that my compiler is running C++17. Please make sure that you change this to whichever command allows your compiler to use at least C++11.

# Gameplay



# To do

