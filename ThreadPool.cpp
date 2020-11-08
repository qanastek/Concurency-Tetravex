/**
* Labrak Yanis
* M1 ILSEN ALT
* TP2 - Programmation parallèle: Design Pattern
* Sources:
* 	https://stackoverflow.com/questions/15752659/thread-pooling-in-c11
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

using namespace std;
using namespace std::chrono;

atomic<double> totalRes;

queue<function<void(int threadId)>> Queue;
condition_variable condition;
condition_variable condition2;
mutex QueueMutex;
atomic<int> currentWorksCpt(0);
vector<thread> Pool;

/**
* Factorial
*/
unsigned long long fact(unsigned long long n)
{
    if(n > 1)
        return n * fact(n - 1);
    else
        return 1;
}

/**
* Epodential
* Example:
* 	((-1)^0)/(0!)+((-1)^1)/(1!)+((-1)^2)/(2!)+((-1)^3)/(3!)
*/
int e(const int i) {

	// Power
	double p = pow(-1,i);

	// Factorial
	unsigned long long f = fact(i);

	// Result
	double res = p / f;

	// Add it to the total
	totalRes =+ res;

	return res;
};

void ThreadPoolLoop(int threadId)
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

void Add_Job(function<void(int threadId)> job)
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
void waitFinished()
{
    unique_lock<mutex> lock(QueueMutex);

    // Wait until the jobs queue is empty and all finished
    condition2.wait(lock, [](){ return Queue.empty() && (currentWorksCpt == 0); });

    cout << "All jobs are done!" << endl << endl;

	cout << "---------Résultat--------------" << endl;
	cout << totalRes << endl;
	cout << "---------Tasks left--------------" << endl;
	cout << to_string(currentWorksCpt) << " Task left." << endl;
}

/**
* Main
*/
int main() {

	// Start the timer
    auto start = high_resolution_clock::now(); 

	// // Without any thread pool
	// int resultat = e(20);
	// cout << "Resultat: " << resultat << endl;

	// The number of jobs
	int n = 5;

	// CPU Threads 
	int Num_Threads = thread::hardware_concurrency();

	// Run informations
	cout << "-----------------------" << endl;
	cout << "-- CPU Threads: " << Num_Threads << endl;
	cout << "-- Tasks: " << n << endl;
	cout << "-----------------------" << endl;

	// Add threads to the pool
	for(int i = 0; i < Num_Threads; i++) {
		Pool.push_back(thread(ThreadPoolLoop, i));
	}

	// Add jobs for each steps
	for (int i = 0; i < n; ++i)
	{
		// Add a job
		Add_Job([i](int threadId){

			// The result
			double res = e(i);

			// Debug
			string output = "Job #" + to_string(i) + " local res: " + to_string(res) + ". Thread " + to_string(threadId) + "\n";
			cout << output << endl;
			
		});
	}

	// Wait the end of all the jobs
	waitFinished();

	// Stop the timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Total time: " << duration.count() << " ms" << endl;

    return 0;
}
