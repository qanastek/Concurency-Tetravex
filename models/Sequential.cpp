/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Sequential.h"

// Constructeurs
Sequential::Sequential() {
    cout << "----------- Sequential Initialized -----------" << endl;
};

void Sequential::Process() {

    // For each tiles
    for (int i = 0; i < 5*5; i++)
    {
        // Local cards
        vector<Card> availableCards = this->cards;

        // Pop it
        availableCards.erase(availableCards.begin() + i);

        for (int j = 0; j < 5*5; j++)
        {

            // Dont go on a used place
            //if(localBoard[j] != NULL) continue;

            // Local board
            // -- vector<vector<int>> localBoard = this->board;

            // Place the current card
            //localBoard[j] = availableCards[i];
        }        

        // pop la carte de cards et la garder dans currentCard
            // Garder les cartes restantes dans availableCards

        // la mettre dans les 5x5 de la board
            // Mais faire gaffe a chaque fois de vérifier qu'il y a pas déjà une carte à l'endroit
        
        // Recursif
    }
    
    
};