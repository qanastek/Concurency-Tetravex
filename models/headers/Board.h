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

    // Get the card at (x,y)
    Card get(int x, int y);

    // Set the card at (x,y)
    void set(int x, int y, Card c);
    
    // Get the end coordinates of the board
    Coordinate end();

    // Get board total dimension
    int getDimension();
    
    // Return if is empty
    bool isEmpty();

    // Check if the position is already used
    bool isUsed(Coordinate pos);

    // Get the next empty slot
    Coordinate nextEmpty();
    
    // Put a card
    int put(vector<Card> &cards, Coordinate c);

    // Remove the card
    void remove(vector<Card> &cards, Coordinate c);

    // Can we place the card here ?
    bool canPlaced(Card &card, Coordinate c);
    
    // Return the next available card
    int getNextCard(vector<Card> cards);
    
    // Case element
    bool case0(Card card, Coordinate c);
    // Case first row
    bool case1(Card card, Coordinate c);
    // Case first col
    bool case2(Card card, Coordinate c);
    // Case others
    bool case3(Card card, Coordinate c);

    // toString
    string toString();
};

#endif