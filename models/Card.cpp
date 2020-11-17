/**
* Labrak Yanis
* M1 ILSEN ALT
* Projet
*/

#include "headers/Card.h"

// Constructeurs
Card::Card() {

    this->top    = -1;
    this->bottom = -1;
    this->left   = -1;
    this->right  = -1;

    this->used = false;
};

Card::Card(int t, int b, int l, int r) {
    
    this->top = t;
    this->bottom = b;
    this->left = l;
    this->right = r;

    this->used = false;
};

bool Card::isEmpty() {

    if(this->top     == -1 &&
       this->bottom  == -1 &&
       this->left    == -1 &&
       this->right   == -1
    ) {
        return true;
    }

    return false;
};

bool Card::isUsed() {
    return used;
};

void Card::visit() {
    used = true;
};

void Card::unvisit() {
    used = false;
};

string Card::toString() {

    // Check empty
    if(this->isEmpty())
        return "NULL";

    string t = to_string(this->top);
    string b = to_string(this->bottom);
    string l = to_string(this->left);
    string r = to_string(this->right);
    string s = isUsed() ? "X" : "";

    return "[" + l + ", " + t + ", " + r + ", " + b + "] " + s;

    // // Before
    // return "[" + t + ", " + b + ", " + l + ", " + r + "]";
}