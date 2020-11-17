#include <iostream>
#include <thread>
#include <math.h>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <algorithm> 
#include <chrono>

#include "models/headers/Parallal.h"

using namespace std;
using namespace std::chrono;

/**
* Main
*/
int main(int argc, char *argv[]) {

    cout << "----------- Main Seq -----------" << endl;

    // Intantiate the sequencial method
    Parallal seq = *new Parallal();

    // Load the 5x5 dataset
    seq.Load5x5();

    // Solve the board
    seq.Solve();
}