#ifndef LEVER_H
#define LEVER_H

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>
using namespace std;


/*
    For now the triangle lenghts are alredy give, and cannot be modified
*/


/**
 * Initialize the isosceles triangle that lifts the shaft
 * @param t_base: Base of the triangle
 * @param t_height: height of the triangle
*/


/**
 *  Initialize the shaft
 *  @param s_length : Length of the length of the shaft
*/
struct Pol_shaft{
    float s_length;
};



/**
 *  Initialize the squares
 *  @param sq1_side: Side of the first square 
 *  @param sq1_pos: Position of the first square object from the center of the shaft
 *  @param sq2_side: Side of the second square 
 *  @param sq2_pos: Position of the second square object from the center of the shaft
*/
struct Pol_squares{
    float sq1_side;
    float sq1_pos;
    float sq2_side;
    float sq2_pos;
};


/**
 * Function that initialize the shaft
 * @param sLength  
*/
Pol_shaft * shaft_init(float sLength);



/**
 *  Function that initialize the squares
 *  @param side1: Side of the first square 
 *  @param pos1: Position of the first square object from the center of the shaft
 *  @param side2: Side of the second square 
 *  @param pos2: Position of the second square object from the center of the shaft
*/
Pol_squares * squares_init(float side1, float pos1, float side2, float pos2);



/** Function that create a string svg containing the image of the shaft and of the squares 
 * 
 *  @param myshaft stucture containg the data of the shaft
 *  @param mysquares stucture containg the data of the squares
 */
string to_svg(Pol_shaft* myshaft, Pol_squares * mysquares);


/** Function to change sizes and checks constrains
 *  @param ShaftLength Length of the shaft
 *  @param SquareSide1 Side of the square 1
 *  @param SquarePos1 Position of the square 1
 *  @param SquareSide2 Side of the square 2
 *  @param SquarePos2 Position of the square 2
 * 
*/
int my_set(double ShaftLength, double SquareSide1, double SquarePos1, double SquareSide2, double SquarePos2);


/** Function that print the string "svg" into a file
 *  Receive in input the name of the file's name that I want to create and open and then I print into it the string received
 *  @param filename name of the file 
 *  @param str_svg string containing everything needed to create an svg file
 */
void svg_to_file(string filename, string str_svg);


/** Function that read an svg file
 * @param filename name of the file to read
 * @return a string of the file read
*/
string read_svg (string filename);


/**
 * Function that deallocate instances
*/
void destroyer(Pol_shaft * myshaft, Pol_squares * mysquares);



#endif