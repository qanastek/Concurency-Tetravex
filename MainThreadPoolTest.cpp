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
* Main for the test of the thread pool class
*/
int main(int argc, char *argv[]) {

    ThreadPool* t = new ThreadPool();

	// // Without any thread pool
	// int resultat = e(20);
	// cout << "Resultat: " << resultat << endl;

	// The number of jobs
	int n = 5;

	// Add jobs for each steps
	for (int i = 0; i < n; ++i)
	{
		// Add a job
		t->Add_Job([t,i](int threadId){

			// The result
			// double res = t->e(i);
			double res = 1+1;

			// Debug
			string output = "Job #" + to_string(i) +
            " local res: " + to_string(res) +
            ". Thread " + to_string(threadId) + "\n";
            
			cout << output << endl;
			
		});
	}

	// Wait the end of all the jobs
	t->waitFinished();

    return 0;
}