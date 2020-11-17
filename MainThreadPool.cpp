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

#include "models/headers/ThreadPool.h"

/**
* Main
*/
int main() {

    ThreadPool* t = new ThreadPool();

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
		t->Add_Thread(i);		
	}

	// Add jobs for each steps
	for (int i = 0; i < n; ++i)
	{
		// Add a job
		t->Add_Job([t,i](int threadId){

			// The result
			double res = t->e(i);

			// Debug
			string output = "Job #" + to_string(i) +
            " local res: " + to_string(res) +
            ". Thread " + to_string(threadId) + "\n";
            
			cout << output << endl;
			
		});
	}

	// Wait the end of all the jobs
	t->waitFinished();

	// Stop the timer
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    cout << "Total time: " << duration.count() << " ms" << endl;

    return 0;
}