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

    // toString
    string toString();
};

#endif