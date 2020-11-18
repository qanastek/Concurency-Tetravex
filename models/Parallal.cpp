/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/
#include <iostream>
#include <thread>

#include "headers/Sequential.h"
#include "headers/Coordinate.h"
#include "headers/Parallal.h"

static int cpt = 0;

// Constructeurs
Parallal::Parallal() {
    cout << "----------- Parallal Initialized -----------" << endl;
};

bool Parallal::Process(vector<Card> cards, Board b, Coordinate currentPos) {

    vector<thread> threads;

    // Pour chaque pièce dans le tas
    for (unsigned int i = 0; i < this->cards.size(); i++)
    {
        cpt++;

        // Intantiate the sequencial method
        Sequential seq = *new Sequential();

		// Add a job
        threads.push_back(

            thread([&](){

                // Visit
                vector<Card> c = cards;
                c[i].visit();

                // Place it
                Board b = board;
                b.content[0][0] = c[i];

                // Sequencial for i
                seq.Process(c, b, *new Coordinate(0,1));
            })
        );
    }

    // Wait for the threads
    for (thread& t : threads) { t.join(); }

    return 0;
};