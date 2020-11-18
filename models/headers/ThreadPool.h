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
    
    // The processing loop of the thread
    static void ThreadPoolLoop(int threadId);
    
    // Add a job to the queue
    void Add_Job(function<void(int threadId)> job);
    
    // Add a thread to the pool
    void Add_Thread(int i);

    // Wait until the queue is empty.
    void waitFinished();
    
    void waitThreads();
};

#endif