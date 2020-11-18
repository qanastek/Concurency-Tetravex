/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/
#include <iostream>
#include <thread>

#include "headers/ThreadPool.h"

static atomic<double> totalRes;
static atomic<int> currentWorksCpt(0);

static queue<function<void(int threadId)>> Queue;
static condition_variable condition;
static condition_variable condition2;
static mutex QueueMutex;
static vector<thread> Pool;

ThreadPool::ThreadPool() {

	// CPU Threads 
	int Num_Threads = thread::hardware_concurrency();

	// Add threads to the pool
	for(int i = 0; i < Num_Threads; i++)
		Add_Thread(i);

	// Run informations
	cout << "-----------------------" << endl;
	cout << "--\tCPU Threads: " << Num_Threads << endl;
	cout << "-----------------------" << endl;
}

// Add a thread to the pool
void ThreadPool::Add_Thread(int i) {
	Pool.push_back(thread(ThreadPoolLoop, i));
}

// The processing loop of the thread
void ThreadPool::ThreadPoolLoop(int threadId)
{
    while(true)
    {
    	// 
        unique_lock<mutex> lock(QueueMutex);

        // Wait a job
        condition.wait(lock, []{ return !Queue.empty(); });

        if (!Queue.empty())
        {
        	// Store the job
	        function<void(int threadId)> Job = Queue.front();

	        // Pop the job from the queue
	        Queue.pop();

	        // 
            lock.unlock();

		    try{

		        // Run It
		        Job(threadId);

		        // 
	            lock.lock();

	            // Decrement the number of current jobs
		    	--currentWorksCpt;

		    	// Notify a new thread in the pool
	            condition2.notify_one();

		    }catch (exception& e){
		        return;
		    }
        }
    }
};

// Add a job to the queue
void ThreadPool::Add_Job(function<void(int threadId)> job)
{
	// 
    unique_lock<mutex> lock(QueueMutex);

    // Add a job to the queue
    Queue.push(job);

    // Increment the number of current jobs
    ++currentWorksCpt;

    // Notify one thread from the pool of the newest job
    condition.notify_one();
};

// Wait until the queue is empty.
void ThreadPool::waitFinished()
{
    unique_lock<mutex> lock(QueueMutex);

    // Wait until the jobs queue is empty and all finished
    condition2.wait(lock, [](){ return Queue.empty() && (currentWorksCpt == 0); });

    cout << "All jobs are done!" << endl << endl;

	cout << "---------Résultat--------------" << endl;
	cout << totalRes << endl;
	cout << "---------Jobs left--------------" << endl;
	cout << to_string(currentWorksCpt) << " Task left." << endl;
}

// Wait until the threads are finished
void ThreadPool::waitThreads() {

    // Wait for the threads
    for (thread& t : Pool) {

		if(t.joinable())
			t.join();
	}
}