#include "lever.h"


Pol_shaft* shaft_init(double sLength){

    // Allocating a struct called "shaft" like "Pol_shaft"
    Pol_shaft* new_shaft = new Pol_shaft;

    // Size assignment
    new_shaft->s_length = sLength;

    //Returning the object
    return new_shaft;
}

Pol_squares* squares_init(double side1, double pos1, double side2, double pos2){

    // Allocating a struct called "squares" like "Pol_squares"
    Pol_squares* new_squares = new Pol_squares;

    // Size assignment
    new_squares->sq1_side = side1;
    new_squares->sq1_pos = pos1;
    new_squares->sq2_side = side2;
    new_squares->sq2_pos = pos2;

    //Returning the object
    return new_squares;
}

void destroyer(Pol_shaft* new_shaft, Pol_squares* new_squares){
   delete new_shaft->s_length;
   delete new_shaft;

   delete new_squares->sq1_side;
   delete new_squares->sq1_pos;
   delete new_squares->sq2_side;
   delete new_squares-> sq2_pos;
   delete new_squares;
}