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
#include <string>
#include <sstream>

using namespace std;
using namespace std::chrono;

#ifndef THREADPOOL_H
#define THREADPOOL_H

class ThreadPool
{
public:

    // Constructors
    ThreadPool();
    
    unsigned long long fact(unsigned long long n);
    int e(const int i);
    static void ThreadPoolLoop(int threadId);
    void Add_Job(function<void(int threadId)> job);
    void Add_Thread(int i);
    void waitFinished();
};

#endif