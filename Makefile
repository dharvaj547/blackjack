CXX = g++
CXXFLAGS = -Wall -g

all: blackjack

blackjack: main.cpp Game/*.cpp Game/*.hpp
	$(CXX) $(CXXFLAGS) -o blackjack $^

play: clean blackjack
	./blackjack play

clean:
	rm -f blackjack