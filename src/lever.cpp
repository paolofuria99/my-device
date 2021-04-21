#include "lever.h"

using namespace std;

Pol_shaft* shaft_init(float sLength){

    // Allocating a struct called "shaft" like "Pol_shaft"
    Pol_shaft* newshaft = new Pol_shaft;

    // Size assignment
    newshaft->s_length = sLength;

    //Returning the object
    return newshaft;
}

Pol_squares* squares_init(float side1, float pos1, float side2, float pos2){

    // Allocating a struct called "squares" like "Pol_squares"
    Pol_squares* newsquares = new Pol_squares;

    // Size assignment
    newsquares->sq1_side = side1;
    newsquares->sq1_pos = pos1;
    newsquares->sq2_side = side2;
    newsquares->sq2_pos = pos2;

    //Returning the object
    return newsquares;
}

void destroyer(Pol_shaft * myshaft, Pol_squares * mysquares){
    delete myshaft;
    delete mysquares;
}
// void destroyer(Pol_shaft* newshaft, Pol_squares* newsquares){
//    delete newshaft->s_length;
//    delete newshaft;

//    delete newsquares->sq1_side;
//    delete newsquares->sq1_pos;
//    delete newsquares->sq2_side;
//    delete newsquares-> sq2_pos;
//    delete newsquares;
// }