/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/
#include <iostream>
#include <thread>

#include "headers/ParallalThreadPool.h"

static int cpt = 0;

#include "headers/Sequential.h"
#include "headers/Coordinate.h"

// Constructeurs
ParallalThreadPool::ParallalThreadPool() {

    // cout << "----------- ParallalThreadPool Initialized -----------" << endl;
};

bool ParallalThreadPool::Process(vector<Card> cards, Board b, Coordinate currentPos) {

    // Pour chaque pièce dans le tas
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {

        cout << "Create the Job for: " << i << endl;

		// Add a job
		threadPool->Add_Job([cards,i,b](int threadId){

			// Counter of jobs
            cpt++;

			string output = "Job #" + to_string(cpt) +
            ". Thread " + to_string(threadId) + "\n";

			cout << output << endl;

            // Intantiate the sequencial method
            Sequential seq = *new Sequential();

            // Visit
            vector<Card> c = cards;
            c[i].visit();

            // Place it
            Board board = b;
            board.content[0][0] = c[i];

            // Sequencial for i
            seq.Process(
                c,
                board,
                *new Coordinate(0,1)
            );
		});
    }

	// Wait the end of all the jobs
	threadPool->waitFinished();
    
	// Wait the end of all the threads
	threadPool->waitThreads();
    
    return 0;
};