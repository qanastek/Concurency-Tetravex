#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

#include "Card.h"
#include "Board.h"

#ifndef BACKTRACKING_H
#define BACKTRACKING_H

class Backtracking
{
    public:

        // The available cards
        vector<Card> cards;

        // The game board
        Board board = *new Board(0,0);

        Backtracking();

        // Initialize the board
        void initBoard(int x, int y);
        
        // Load the dataset of size  x * y
        void Load5x5();
        void Load6x6();
        void Load7x7();
        void Load8x8();

        // Generique dataset loader
        void LoadData(string filename);

        // Display the cards available in cards
        void DisplayCardsLeft();

        // Display the board
        void DisplayBoard();

        // Solve the problem 
        Board Solve();
        
        // Abstract method for the processing 
        virtual void Process() = 0;
};

#endif