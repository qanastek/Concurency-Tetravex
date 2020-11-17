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

    cout << "----------- ParallalThreadPool Initialized -----------" << endl;
};

bool ParallalThreadPool::Process(vector<Card> cards, Board b, Coordinate currentPos) {

    // Pour chaque pièce dans le tas
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        // Intantiate the sequencial method
        Sequential seq = *new Sequential();

        cout << "Setup the seq for the card: " << i << endl;

		// Add a job
		threadPool->Add_Job([&](int threadId){

			// Debug
            cpt++;

			string output = "Job #" + to_string(cpt) +
            ". Thread " + to_string(threadId) + "\n";

			cout << output << endl;

            // Visit
            vector<Card> c = cards;
            c[i].visit();

            // Place it
            Board b = board;
            b.content[0][1] = c[i];

            // Sequencial for i
            seq.Process(c, b, *new Coordinate(0,0));
		});
    }

	// Wait the end of all the jobs
	threadPool->waitFinished();
    
    return 0;
};