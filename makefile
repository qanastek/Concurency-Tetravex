run:
	clear
	g++ -std=c++11 -c main.cpp models/Parallel.cpp models/Sequential.cpp models/IBacktracking.cpp
	g++ -std=c++11 -o Projet -lpthread main.o Parallel.o Sequential.o IBacktracking.o
	./Projet