/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector> 

#include "headers/Backtracking.h"

using namespace std;

Backtracking::Backtracking() {
  // cout << "----------- Backtracking Initialized -----------" << endl;
};

void Backtracking::initBoard(int x, int y) {

  // Initialize the board
  this->board.initBoard(x,y);
}
        
void Backtracking::Load5x5() {

  cout << "----------- Load 5x5 -----------" << endl;
  Backtracking::LoadData("data/5x5.txt");   

  int n = 5; 
  this->initBoard(n,n);
};

void Backtracking::Load6x6() {

  Backtracking::LoadData("data/6x6.txt");   

  int n = 6; 
  this->initBoard(n,n);    
};

void Backtracking::Load7x7() {

  Backtracking::LoadData("data/7x7.txt");    

  int n = 7; 
  this->initBoard(n,n);                  
};

void Backtracking::Load8x8() {

  Backtracking::LoadData("data/8x8.txt");    

  int n = 8; 
  this->initBoard(n,n);            
};

void Backtracking::DisplayCardsLeft() {

  // Display each card
  for(Card c : this->cards)
  {
    cout << c.toString() << endl;
  }
}

bool Backtracking::cardsLeft(vector<Card> &cds) {

    for(Card c : cds)
    {
        if (!c.isUsed())
            return true;                
    }

    return false;
}

void Backtracking::LoadData(string filename) {

    cout << "----------- LoadData: " << filename << " -----------" << endl;

    // Open the file
    ifstream infile(filename);

    if (!infile.good()) {
        cout << "----------- Doesn't found the file " << filename << "!" << endl;    
    }

    // Current values
    string line;

    // Index
    int i = 0;

    // Width and height
    int w = 0;
    int h = 0;

    // For each lines
    while (getline(infile, line))
    {        
        // The current line
        istringstream iss(line);

        // First row
        if (i == 0) {

            // Get width and height
            iss >> w >> h;

            // Display them
            cout << "W: " << w << " , H: " << h << endl;

            // Increment position
            i++;

            // Pass the first row
            continue;
        }

        // Current item
        int t, b, l, r;

        // Read the value
        // top, bottom, left, right
        iss >> l >> t >> r >> b;

        // Add the card to the list
        this->cards.push_back(*new Card(t, b, l, r));

        i++;
    }
};