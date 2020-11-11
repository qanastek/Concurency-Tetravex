/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Card.h"

// Constructeurs
Card::Card() {
    this->top = 0;
    this->bottom = 0;
    this->left = 0;
    this->right = 0;
};

Card::Card(int top, int bottom, int left, int right) {
    this->top = top;
    this->bottom = bottom;
    this->left = left;
    this->right = right;
};

bool Card::isEmpty() {

    if(this->top     == 0 &&
       this->bottom  == 0 &&
       this->left     == 0 &&
       this->right     == 0
    ) {
        return true;
    }

    return false;
};

string Card::toString() {

    // Check empty
    if(this->isEmpty())
        return "NULL";

    string t = to_string(this->top);
    string b = to_string(this->bottom);
    string l = to_string(this->left);
    string r = to_string(this->right);

    return "[" + l + ", " + t + ", " + r + ", " + b + "]";

    // // Before
    // return "[" + t + ", " + b + ", " + l + ", " + r + "]";
}