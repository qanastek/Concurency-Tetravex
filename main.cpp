#include <iostream>
#include <thread>
#include <math.h>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <algorithm> 
#include <chrono>
#include <stdio.h>
#include <string.h>

#include "models/headers/Backtracking.h"
#include "models/headers/Sequential.h"
// #include "models/headers/Parallal.h"
#include "models/headers/ParallalThreadPool.h"

using namespace std;
using namespace std::chrono;

/**
* Main
*/
int main(int argc, char *argv[]) {

    cout << "----------- Main Seq -----------" << endl;

    int argsSize = 2;

    if (argc != argsSize) {
        cerr << (argc > argsSize ? "Too much arguments" : "Not enaugh arguments") << endl;        
        exit(0);
    }

    // The Strategy
    // Backtracking* b;

    // Type
    if (strcmp(argv[1], "seq" ) == 0 ) {

        // Intantiate the sequencial method
        Sequential* b = new Sequential();
        b->Load5x5();
        b->Solve();
    }
    else if (strcmp(argv[1], "para" ) == 0 ) {

        // Intantiate the sequencial method
        // b = new Parallal();
    }
    else if (strcmp(argv[1], "pool" ) == 0 ) {

        // Intantiate the sequencial method
        ParallalThreadPool* b = new ParallalThreadPool();
        b->Load5x5();
        b->Solve();
    }

    // // Load the dataset
    // if (strcmp(argv[2], "5" ) == 0 ) {
    //     b->Load5x5();
    // }
    // else if (strcmp(argv[2], "6" ) == 0 ) {
    //     b->Load6x6();
    // }
    // else if (strcmp(argv[2], "7" ) == 0 ) {
    //     b->Load7x7();
    // }
    // else if (strcmp(argv[2], "8" ) == 0 ) {
    //     b->Load8x8();
    // }

    // Solve the board
    // b->Solve();
}