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

#include "IBacktracking.h"

using namespace std;
using namespace std::chrono;

class Parallel : public IBacktracking
{
public:
    // Constructeurs
    Parallel();
};