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

#ifndef SEQUENTIAL_H
#define SEQUENTIAL_H

class Sequential : public Backtracking
{
public:

    // Constructors
    Sequential();
        
    // Abstract method for the processing 
    virtual void Process();
};

#endif