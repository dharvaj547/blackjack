# Blackjack game
A terminal based Blackjack clone written in C++.

# Running
- Ensure that you are running at least C++11 
- Clone the repository
- Open terminal and to the project directory
- Run ```make play``` in terminal to play the game

Errors caused here are most likely caused by the Makefile. Read "Makefile for macOS and windows" for fixes.  

# Makefile for macOS and windows
The given Makefile is for windows system. If you are using a mac, your Makefile might look something like 
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
Make sure that you use the correct flag which ensures you are running at least C++11. For me ```CXX = g++``` had to be changed to ```CXX = g++-11``` but this might be different for you. 

# TODO
- add some feature to exit the game at any time (instead of ctrl+c everytime)
- fix some known bugs
- add feature for card counting
