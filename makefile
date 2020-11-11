run:
	clear
	g++ -std=c++11 -c main.cpp models/Backtracking.cpp models/Parallal.cpp models/ParallalThreadPool.cpp models/Sequential.cpp models/Card.cpp models/Board.cpp
	g++ -std=c++11 -o Projet -lpthread main.o Backtracking.o Parallal.o ParallalThreadPool.o Sequential.o Card.o Board.o
	./Projet