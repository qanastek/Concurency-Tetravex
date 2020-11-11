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

#ifndef PARALLALTREADPOOL_H
#define PARALLALTREADPOOL_H

class ParallalThreadPool : public Backtracking
{
public:

    // Constructors
    ParallalThreadPool();
        
    // Abstract method for the processing 
    virtual void Process();
};

#endif