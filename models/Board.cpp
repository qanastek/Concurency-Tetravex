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


bool Board::isUsed(Coordinate pos) {

    // If not empty
    if(!this->content[pos.x][pos.y].isEmpty())
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

Card Board::getNextCard(vector<Card> cards) {

    // For each card
    for(Card c : cards)
    {
        // If not already used, return it
        if (!c.isUsed()) return c;
    }

    // Else return empty card
    return *new Card();
}

bool Board::put(vector<Card> cards, Coordinate c) {

    // Get the next card
    Card card = getNextCard(cards);

    // If empty return cannot put
    if(card.isEmpty()) return false;

    // Set as visited
    card.visit();

    // Place the card
    this->content[c.x][c.y] = card;

    return true;
}

void Board::remove(vector<Card> cards, Coordinate c) {
    
    // Get the placed card
    Card card = content[c.x][c.y];

    // Restore unused state
    card.unvisit();

    // Remove it from the board
    content[c.x][c.y] = *new Card();
};

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