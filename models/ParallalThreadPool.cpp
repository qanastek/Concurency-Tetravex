/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/ParallalThreadPool.h"

static int cpt = 0;

#include "headers/Sequential.h"
#include "headers/Coordinate.h"

// Constructeurs
ParallalThreadPool::ParallalThreadPool() {

    cout << "----------- ParallalThreadPool Initialized -----------" << endl;
};

bool ParallalThreadPool::Process(vector<Card> &cards, Board b, Coordinate currentPos) {

    // Pour chaque pièce dans le tas
    for (int i = 0; i < this->cards.size(); i++)
    {
        // Intanciate the sequencial method
        Sequential seq = *new Sequential();

		// Add a job
		threadPool->Add_Job([&](int threadId){

			// Debug
            cpt++;
			string output = "Job #" + to_string(cpt) +
            ". Thread " + to_string(threadId) + "\n";

            // Visit
            vector<Card> c = cards;
            c[i].visit();

            // Place it
            Board b = board;
            c[i].visit();
            b.content[0][0] = c[i];

            // Sequencial for i
            seq.Process(c, b, *new Coordinate(0,1));
		});
    }
};