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

    // Constructors
    Card();
    Card(int top, int bottom, int left, int right);

    // Return if is empty
    bool isEmpty();

    // toString
    string toString();
};

#endif