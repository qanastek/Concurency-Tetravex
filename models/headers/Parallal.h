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

#include "Sequential.h"
#include "Backtracking.h"

#include "Coordinate.h"
#include "Board.h"

using namespace std;
using namespace std::chrono;

#ifndef PARALLAL_H
#define PARALLAL_H

class Parallal : public Backtracking
{
public:

    // Constructors
    Parallal();
        
    // Abstract method for the processing 
    bool Process(vector<Card> cards, Board b, Coordinate currentPos);
    
    Board Solve() {

        // Start the recursion fron the top left corner
        this->Process(this->cards, this->board, *new Coordinate(0,0));

        return this->board;
    }
};

#endif