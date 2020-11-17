seq:
	clear
	g++ -std=c++11 -c main.cpp models/Coordinate.cpp models/Backtracking.cpp models/Sequential.cpp models/Card.cpp models/Board.cpp
	g++ -std=c++11 -o Projet -lpthread main.o Coordinate.o Backtracking.o Sequential.o Card.o Board.o
	./Projet
parallal:
	clear
	g++ -std=c++11 -c main.cpp models/Coordinate.cpp models/Backtracking.cpp models/Parallal.cpp models/Card.cpp models/Board.cpp
	g++ -std=c++11 -o Projet -lpthread main.o Coordinate.o Backtracking.o Parallal.o Card.o Board.o
	./Projet
pool:
	clear
	g++ -std=c++11 -c mainThreadPool.cpp models/ThreadPool.cpp models/Coordinate.cpp models/Backtracking.cpp models/ParallalThreadPool.cpp models/Card.cpp models/Board.cpp models/Sequential.cpp 
	g++ -std=c++11 -o Projet -lpthread mainThreadPool.o ThreadPool.o Coordinate.o Backtracking.o ParallalThreadPool.o Card.o Board.o Sequential.o
	./Projet
testpool:
	clear
	g++ -std=c++11 -c MainThreadPoolTest.cpp models/ThreadPool.cpp
	g++ -std=c++11 -o Projet -lpthread MainThreadPoolTest.o ThreadPool.o
	./Projet