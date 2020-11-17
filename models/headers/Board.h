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
    Board();
    Board(int width, int height);

    // Initialize the board
    void initBoard(int x, int y);
    
    // Get the end coordinates of the board
    Coordinate end();

    // Check if is empty    
    bool isEmpty();

    // Get the next empty slot
    Coordinate nextEmpty();

    // Can we place the card here ?
    bool canPlaced(Card &card, Coordinate c);

    // toString
    string toString();
};

#endif