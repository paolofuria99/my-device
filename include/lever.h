#ifndef LEVER_H
#define LEVER_H

#include <fstream>
#include <iostream>
using namespace std;


/*
    Initialize the isosceles triangle that lifts the shaft
    @param t_base: Base of the triangle
    @param t_height: height of the triangle
*/
// struct Pol_triangle {
//     float t_base;
//     float t_height;
// };




/*
    Initialize the shaft
    @param s_length : Length of the length of the shaft
*/
struct Pol_shaft{
    float s_length;
};




/*
    Initialize the squares
    @param sq1_side: Side of the first square 
    @param sq1_pos: Position of the first square object from the center of the shaft
    
    @param sq2_side: Side of the second square 
    @param sq2_pos: Position of the second square object from the center of the shaft
*/
struct Pol_squares{
    float sq1_side;
    float sq1_pos;
    float sq2_side;
    float sq2_pos;
};

/*
    For now the triangle lenghts are alredy give, and cannot be modified
*/



/*
    Function that initialize the shaft
    @param sLength
*/
Pol_shaft * shaft_init(float sLength);



/*
    Function that initialize the squares
    @param side1: Side of the first square 
    @param pos1: Position of the first square object from the center of the shaft
    
    @param side2: Side of the second square 
    @param pos2: Position of the second square object from the center of the shaft
*/
Pol_squares * squares_init(float side1, float pos1, float side2, float pos2);






/*
    Function that deallocate instances
*/
// void destroyer(Pol_shaft * newshaft, Pol_squares * newsquares);



#endif