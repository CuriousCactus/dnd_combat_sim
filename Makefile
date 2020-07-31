all: combat dndcs

combat: combat.cpp
	g++ -Wall combat.cpp -o combat

dndcs: main.cpp creature.cpp dice.cpp dndcs.h
	g++ -Wall main.cpp creature.cpp dice.cpp -o dndcs
