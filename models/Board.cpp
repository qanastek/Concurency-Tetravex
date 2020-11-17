/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Board.h"

// Constructeur
Board::Board() {

    // Init board
    this->initBoard(0,0);
};

Board::Board(int width, int height) {

    // Init board
    this->initBoard(width,height);
};

/**
 * Initialize the board 
 */
void Board::initBoard(int x, int y) {

  // Row
  for (int i = 0; i < x; i++)
  {

    vector<Card> row;

    // Column
    for (int j = 0; j < y; j++)
        row.push_back(*new Card());

    this->content.push_back(row);
  }
}

bool Board::isEmpty() {

    // If empty
    if(this->content.size() <= 0)
        return true;

    return false;
};

// Get the end coordinates of the board
Coordinate Board::end() {

    // The coordinates
    return *new Coordinate(
        content.size() - 1,
        content[0].size() - 1
    ); 
}

// // Others
// bool Board::case3(Card card, Coordinate c) {

//     cout << "1 Bottom: " << content[c.x-1][c.y].bottom << endl;
//     cout << "1 Top: " << card.top << endl;

//     cout << "2 Right: " << content[c.x][c.y-1].right << endl;
//     cout << "2 Left: " << card.left << endl;

//     cout << card.toString() << endl << endl;

//     // Others
//     if(content[c.x-1][c.y].bottom == card.top &&
//        content[c.x][c.y-1].right == card.left)
//         return true;

//     return false;
// }

bool Board::canPlaced(Card &card, Coordinate c) {

    // First card
    if(c.x == 0 && c.y == 0)
        return true;

    // not first row
    if(c.x != 0) {
        
        // If not the same
        if (content[c.x-1][c.y].bottom != card.top)
        {
            return false;
        }  
    }

    // first col
    if(c.y != 0) {

        // If not the same
        if (content[c.x][c.y-1].right != card.left)
        {
            return false;
        }

    }

    return true;
}

// Find the next empty tile
Coordinate Board::nextEmpty() {

    // Row
    for (int i = 0; i < this->content.size(); i++)
    {
        // Col
        for (int j = 0; j < this->content[i].size(); j++)
        {
            // If empty
            if (this->content[i][j].isEmpty())
            {
                // cout << "------------ next: " << i << "," << j << endl;

                // Return the blank position
                return *new Coordinate(i,j);
            }            
        }
    }
    
    // If not found return the last element
    return *new Coordinate(
        this->content.size() - 1,
        this->content[0].size() - 1
    );
};

string Board::toString() {

    // Check empty
    if(this->isEmpty())
        return "Empty board";

    string str = "";

    cout << "[" << endl;

    for(vector<Card> row : this->content)
    {
        cout << "[";

        for(Card card : row)
        {
            cout << card.toString() << " ";
        }  

        cout << "]" << endl;
    }

    cout << "]" << endl;

    return str;
};