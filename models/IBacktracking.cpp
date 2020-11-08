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

#include "headers/IBacktracking.h"

using namespace std;
        
void IBacktracking::Load5x5() {
    cout << "----------- Load 5x5 -----------" << endl;
    IBacktracking::LoadData("data/5x5.txt");      
};

void IBacktracking::Load6x6() {
    IBacktracking::LoadData("data/6x6.txt");      
};

void IBacktracking::Load7x7() {
    IBacktracking::LoadData("data/7x7.txt");                  
};

void IBacktracking::Load8x8() {
    IBacktracking::LoadData("data/8x8.txt");            
};

void IBacktracking::LeftCards() {

    cout << endl;
    
    for(vector<int> card : this->cards)
    {
        for(int nbr : card)
        {
            cout << nbr << " ";            
        }
        
        cout << endl;
    }
}

void IBacktracking::LoadData(string filename) {

    cout << "----------- LoadData: " << filename << " -----------" << endl;

    // Open the file
    ifstream infile(filename);

    if (!infile.good()) {
        cout << "----------- Doesn't found the file " << filename << "!" << endl;    
    }

    // Current values
    int value;
    string line;

    int i = 0;
    int w = 0;
    int h = 0;
    int cardSize = 4;

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
        int current;

        // Current card
        vector<int> card;

        for (int i = 0; i < cardSize; i++)
        {
            // Read the value
            iss >> current;

            // Add the value to the card
            card.push_back(current);
        }

        // Add the card to the list
        this->cards.push_back(card);

        i++;
    }
};