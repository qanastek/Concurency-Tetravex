/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include <iostream>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>

#include "Card.h"
#include "Coordinate.h"

using namespace std;

#ifndef BOARD_H
#define BOARD_H

class Board
{
public:

    // Content of the board
    vector<vector<Card>> content;

    // Constructeur
    Board(int width, int height);

    // Initialize the board
    void initBoard(int x, int y);

    // Get the card at (x,y)
    Card get(int x, int y);

    // Set the card at (x,y)
    void set(int x, int y, Card c);
    
    // Return if is empty
    bool isEmpty();

    // Check if the position is already used
    bool isUsed(Coordinate pos);

    // Get the next empty slot
    Coordinate nextEmpty();
    
    // Put a card
    bool put(vector<Card> cards, Coordinate c);

    // Remove the card
    void remove(vector<Card> cards, Coordinate c);
    
    // Return the next available card
    Card getNextCard(vector<Card> cards);

    // toString
    string toString();
};

#endif