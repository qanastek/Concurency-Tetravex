/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/ThreadPool.h"

static atomic<double> totalRes;
static atomic<int> currentWorksCpt(0);

static queue<function<void(int threadId)>> Queue;
static condition_variable condition;
static condition_variable condition2;
static mutex QueueMutex;
static vector<thread> Pool;

ThreadPool::ThreadPool() {
	
}

/**
* Factorial
*/
unsigned long long ThreadPool::fact(unsigned long long n)
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
int ThreadPool::e(const int i) {

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

void ThreadPool::Add_Thread(int i) {
	Pool.push_back(thread(ThreadPoolLoop, i));
}

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
	cout << "---------Tasks left--------------" << endl;
	cout << to_string(currentWorksCpt) << " Task left." << endl;
}