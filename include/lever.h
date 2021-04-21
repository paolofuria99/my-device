#ifndef LEVER_H
#define LEVER_H



/*
    Initialize the isosceles triangle that lifts the shaft
    @param t_base: Base of the triangle
    @param t_height: height of the triangle
*/
struct Pol_triangle {
    double t_base;
    double t_height;
};




/*
    Initialize the shaft
    @param s_length : Length of the length of the shaft
*/
struct Pol_shaft{
    double s_length;
};




/*
    Initialize the squares
    @param sq1_side: Side of the first square 
    @param sq1_pos: Position of the first square object from the center of the shaft
    
    @param sq2_side: Side of the second square 
    @param sq2_pos: Position of the second square object from the center of the shaft
*/
struct Pol_squares{
    double sq1_side;
    double sq1_pos;
    double sq2_side;
    double sq2_pos;
};

/*
    For now the triangle lenghts are alredy give, and cannot be modified
*/



/*
    Function that initialize the shaft
    @param sLength
*/
Pol_shaft * shaft_init(double sLength);



/*
    Function that initialize the shaft
    @param sLength
*/
Pol_squares * squares_init(double side1, double pos1, double side2, double pos2);




/*
    Functin that deallocate instances
*/
void destroyer(Pol_shaft * shaft, Pol_squares * squares);



#endif