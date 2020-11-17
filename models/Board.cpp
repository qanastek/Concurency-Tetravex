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

// Get the card at (x,y)
Card Board::get(int x, int y) {
    return this->content[x][y];
};

// Set the card at (x,y)
void Board::set(int x, int y, Card c) {
    this->content[x][y] = c;
};

// Get the end coordinates of the board
Coordinate Board::end() {

    // The coordinates
    return *new Coordinate(
        content.size() - 1,
        content[0].size() - 1
    ); 
}

// Get board total dimension
int Board::getDimension() {
    return ((end().x + 1) * (end().y + 1));
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

int Board::getNextCard(vector<Card> cards) {

    // For each card
    for (int i = 0; i < cards.size(); i++)
    {
        // If not already used, return it
        if (cards[i].isUsed() == false) return i;
    }

    // Else return empty card
    return -1;
}

// First element
bool Board::case0(Card card, Coordinate c) {

    // First row
    if(c.x == 0 && c.y == 0)
        return true;

    return false;
}

// First row
bool Board::case1(Card card, Coordinate c) {

    // First row
    if(c.x == 0 && content[c.x][c.y-1].right == card.left)
        return true;

    return false;
}

// Firs col
bool Board::case2(Card card, Coordinate c) {

    // First col
    if(c.y == 0 && content[c.x-1][c.y].bottom == card.top)
        return true;

    return false;
}

// Others
bool Board::case3(Card card, Coordinate c) {

    cout << "1 Bottom: " << content[c.x-1][c.y].bottom << endl;
    cout << "1 Top: " << card.top << endl;

    cout << "2 Right: " << content[c.x][c.y-1].right << endl;
    cout << "2 Left: " << card.left << endl;

    cout << card.toString() << endl << endl;

    // Others
    if(content[c.x-1][c.y].bottom == card.top &&
       content[c.x][c.y-1].right == card.left)
        return true;

    return false;
}

bool Board::canPlaced(Card &card, Coordinate c) {

    // First card
    if(c.x == 0 && c.y == 0)
        return true;

    // first col
    if(c.y == 0) {

        // If not the same
        if (content[c.x-1][c.y].bottom == card.top)
        {
            return false;
        }        
    }

    // first row
    if(c.x == 0) {

        // If not the same
        if (content[c.x][c.y-1].right != card.left)
        {
            return false;
        }        
    }

    // // If agree with all the rules return cannot put
    // if(card.isEmpty() || (case0(card,c) == false &&  &&  && case3(card,c) == false))
    //     return false;
    
    return true;
}

int Board::put(vector<Card> &cards, Coordinate c) {

    // Get the next card
    int cardIndex = getNextCard(cards);

    // if(card.isEmpty() == false)
    // cout << "Card: " << (isEmpty() ? "Not_found": ("Found " + cards[cardIndex].toString())) << endl;

    // Card index
    if(cardIndex != -1)
        // Set as visited
        cards[cardIndex].visit();

    // If empty or doesn't agree with any rules return cannot put
    if(cardIndex == -1 || cards[cardIndex].isEmpty() == true || (case0(cards[cardIndex],c) == false && case1(cards[cardIndex],c) == false && case2(cards[cardIndex],c) == false && case3(cards[cardIndex],c) == false))
        return -1;

    // Place the card
    this->content[c.x][c.y] = cards[cardIndex];

    // cout << "Visited" << endl;
    // cout << "Card v: " << this->content[c.x][c.y].toString() << endl;

    return cardIndex;
}

void Board::remove(vector<Card> &cards, Coordinate c) {

    // cout << "Remove" << endl;

    // Restore unused state of the card
    content[c.x][c.y].unvisit();

    // Remove it from the board
    content[c.x][c.y] = *new Card();
};

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