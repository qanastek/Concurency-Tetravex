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
	g++ -std=c++11 -Wall -g3 -c -lpthread models/Parallal.cpp -o objects/Parallal.o
	g++ -std=c++11 -Wall -g3 -o executables/Projet -lpthread objects/main.o objects/ThreadPool.o objects/Coordinate.o objects/Backtracking.o objects/ParallalThreadPool.o objects/Sequential.o objects/Card.o objects/Board.o objects/Parallal.o
seq:
	make base
	./executables/Projet seq
pool:
	make base
	./executables/Projet pool
para:
	make base
	./executables/Projet para