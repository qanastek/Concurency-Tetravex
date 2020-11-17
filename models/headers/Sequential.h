/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include <iostream>
#include <thread>
#include <math.h>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <algorithm> 
#include <chrono>

#include "Backtracking.h"

#include "Coordinate.h"
#include "Board.h"

using namespace std;
using namespace std::chrono;

#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

class Sequential : public Backtracking
{
public:

    // Constructors
    Sequential();
        
    // Abstract method for the processing 
    bool Process(vector<Card> cards, Board b, Coordinate currentPos);
    
    Board Solve() {

        // Start the recursion fron the top left corner
        this->Process(this->cards, this->board, *new Coordinate(0,0));

        return this->board;
    }
};

#endif