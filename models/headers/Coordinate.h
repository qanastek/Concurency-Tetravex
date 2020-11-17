#include <iostream>
#include <string>

using namespace std;

#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
public:

    int x;
    int y;

    Coordinate();
    Coordinate(int x, int y);

    // Comparison operator
    bool operator==(const Coordinate& c) const;

    // Check if empty
    bool isEmpty();

    // toString
    string toString();
};

#endif