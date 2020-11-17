/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Coordinate.h"

// Constructors
Coordinate::Coordinate() {
    this->x = -1;
    this->y = -1;
};

Coordinate::Coordinate(int x, int y) {
    this->x = x;
    this->y = y;
};

// Comparison operator
bool Coordinate::operator==(const Coordinate& c) const
{
    return (x == c.x) && (y == c.y);
};

bool Coordinate::isEmpty() {

    if(x == -1 && y == -1) return true;

    return false;
}

string Coordinate::toString() {

    string a = to_string(this->x);
    string b = to_string(this->y);

    return "x: " + a + ", y: " + b;
}