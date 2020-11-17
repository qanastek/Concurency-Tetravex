base:
	clear
	g++ -std=c++11 -Wall -g3 -c -lpthread main.cpp -o objects/main.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/ThreadPool.cpp -o objects/ThreadPool.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Coordinate.cpp -o objects/Coordinate.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Backtracking.cpp -o objects/Backtracking.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/ParallalThreadPool.cpp -o objects/ParallalThreadPool.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Sequential.cpp -o objects/Sequential.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Card.cpp -o objects/Card.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Board.cpp -o objects/Board.o
	g++ -std=c++11 -Wall -g3 -o Projet -lpthread objects/main.o objects/ThreadPool.o objects/Coordinate.o objects/Backtracking.o objects/ParallalThreadPool.o objects/Sequential.o objects/Card.o objects/Board.o
seq:
	make base
	./Projet seq
parallal:
	clear
	g++ -std=c++11 -Wall -g3 -c -lpthread mainParallal.cpp -o objects/mainParallal.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Coordinate.cpp -o objects/Coordinate.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Backtracking.cpp -o objects/Backtracking.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Parallal.cpp -o objects/Parallal.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Card.cpp -o objects/Card.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Sequential.cpp -o objects/Sequential.o
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Board.cpp -o objects/Board.o
	g++ -std=c++11 -Wall -g3 -o Projet -lpthread objects/mainParallal.o objects/Coordinate.o objects/Backtracking.o objects/Parallal.o objects/Card.o objects/Board.o objects/Sequential.o
	./Projet
pool:
	make base
	./Projet pool
testpool:
	clear
	g++ -std=c++11 -O3 -c MainThreadPoolTest.cpp -o objects/MainThreadPoolTest.o
	g++ -std=c++11 -O3 -c models/ThreadPool.cpp -o objects/ThreadPool.o
	g++ -std=c++11 -O3 -o Projet -lpthread objects/MainThreadPoolTest.o objects/ThreadPool.o
	./Projet