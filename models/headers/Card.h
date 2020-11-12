/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include <iostream>
#include <math.h>
#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

class Card
{
public:

    // Values
    int top, bottom, left, right;

    // Is used
    bool used;

    // Constructors
    Card();
    Card(int top, int bottom, int left, int right);

    // Return if is empty
    bool isEmpty();

    // Return if is used
    bool isUsed();

    // Change the usage status
    void visit();
    void unvisit();

    // toString
    string toString();
};

#endif