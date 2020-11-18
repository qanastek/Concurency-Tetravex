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

bool Sequential::Process(vector<Card> cards, Board b, Coordinate currentPos) {

    // cout << "New instance: " << currentPos.toString() << endl;

    // If no cards left
    if(cardsLeft(cards) == false) {

        cout << "############# END #############" << endl;

        // Display loaded cards
        cout << endl << "DisplayCardsLeft" << endl;
        DisplayCardsLeft();

        // Display the board
        cout << endl << "DisplayBoard" << endl;
        cout << b.toString() << endl;

        return true;
    }

    // cout << "ddddddddddddddddddd: " << currentPos.toString() << endl;

    // Pour chaque pièce dans le tas
    for (unsigned int k = 0; k < cards.size(); k++)
    {
        // cout << "uuuuuuuuuuuuuuu: " << endl;

        // Vérifier l'utilisation de la piece ainsi que la posibilité de la pose
        if (!cards[k].isUsed())
        {

            // Can we place the card here ?
			if (b.canPlaced(cards[k], currentPos))  {
                
                // Visit it
                cards[k].visit();

                // Place it
                b.content[currentPos.x][currentPos.y] = cards[k];

                if (Process(cards, b, b.nextEmpty()))
                {
                    cout << "Place: " << cards[k].toString() << " at " << currentPos.toString() << endl;

                    return true;
                }

                // Unvisit it
                cards[k].unvisit();
            }
        }        
    }

    return false;
};