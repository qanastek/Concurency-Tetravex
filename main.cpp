#include <iostream>
#include <thread>
#include <math.h>
#include <queue>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <algorithm> 
#include <chrono>

#include "models/headers/Sequential.h"

using namespace std;
using namespace std::chrono;

/**
* Main
*/
int main() {

    cout << "----------- Main -----------" << endl;

    // Intanciate the sequencial method
    Sequential seq = *new Sequential();

    // Load the 5x5 dataset
    seq.Load5x5();

    // Solve the board
    seq.Solve();
}