/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Board.h"

// Constructeur
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

Card Board::get(int x, int y) {
    return this->content[x][y];
};

void Board::set(int x, int y, Card c) {
    this->content[x][y] = c;
};

bool Board::isEmpty() {

    // If empty
    if(this->content.size() <= 0)
        return true;

    return false;
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