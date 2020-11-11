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

using namespace std;
using namespace std::chrono;

#ifndef PARALLEL_H
#define PARALLEL_H

class Parallel : public Backtracking
{
public:

    // Constructors
    Parallel();
        
    // Abstract method for the processing 
    virtual void Process();
};

#endif