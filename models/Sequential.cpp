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

int Sequential::getNextCard(vector<Card> cards) {

    // For each card
    for (int i = 0; i < cards.size(); i++)
    {
        // If not already used, return it
        if (cards[i].isUsed() == false) return i;
    }

    // Else return empty card
    return -1;
}

bool Sequential::Process(vector<Card> &cards, Board b, Coordinate currentPos) {

    cout << "New instance: " << currentPos.toString() << endl;

    if(currentPos == board.end()) {
        cout << "############# WINNING #############" << endl;
        return true;
    }
    
    // int i = currentPos->x;
    // int j = currentPos->y;

    // Pour chaque pièce dans le tas
    for (int k = 0; k < this->cards.size(); k++)
    {
        // Vérifier l'utilisation de la piece ainsi que la posibilité de la pose
        if (!b.isUsed(currentPos))
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

                // Si il a était placer mais que le move a mener à rien
                // b.remove(cards, currentPos);

                // Unvisit it
                cards[k].unvisit();

            }
        }
        
    }

    return false;
};