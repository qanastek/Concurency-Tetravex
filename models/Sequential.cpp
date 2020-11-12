/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Sequential.h"
#include "headers/Coordinate.h"

// Constructeurs
Sequential::Sequential() {
    cout << "----------- Sequential Initialized -----------" << endl;
};

bool Sequential::Process(Board b, Coordinate currentPos) {

    if(currentPos == END)
        return true;
    
    // int i = currentPos->x;
    // int j = currentPos->y;

    // Pour chaque pièce dans le tas
    for (int k = 0; k < ((END.x + 1) * (END.y + 1)); k++)
    {
        // Vérifier l'utilisation de la piece ainsi que la posibilité de la pose
        if ((cas1 || cas2 || cas3) && !b.isUsed(currentPos))
        {
            // Poser la piece
            bool isPlaced = b.put(cards, currentPos);

            // Si le children a marcher alors sa continue en recursive jusqu'à la fin ou sa 
            // va backtracking et save chacun des moves
            if (isPlaced && Process(b, b.nextEmpty()))
            {
                return true;
            }

            // Si il a était placer mais que le move a mener à rien
            b.remove(cards, currentPos);
        }
        
    }

    return false;
    
    // // For each tiles
    // for (int i = 0; i < 5*5; i++)
    // {
    //     // Local cards
    //     vector<Card> availableCards = this->cards;

    //     // Pop it
    //     availableCards.erase(availableCards.begin() + i);

    //     for (int j = 0; j < 5*5; j++)
    //     {

    //         // Dont go on a used place
    //         //if(localBoard[j] != NULL) continue;

    //         // Local board
    //         // -- vector<vector<int>> localBoard = this->board;

    //         // Place the current card
    //         //localBoard[j] = availableCards[i];
    //     }        

    //     // pop la carte de cards et la garder dans currentCard
    //         // Garder les cartes restantes dans availableCards

    //     // la mettre dans les 5x5 de la board
    //         // Mais faire gaffe a chaque fois de vérifier qu'il y a pas déjà une carte à l'endroit
        
    //     // Recursif
    // }
    
    
};