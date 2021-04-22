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


string to_svg(Pol_shaft* myshaft, Pol_squares * mysquares){

    string svg;
    float xline1= 250 - myshaft->s_length;
    float xline2= 250 + myshaft->s_length;
    float position1x= 250 - (mysquares->sq1_pos + (mysquares->sq1_pos)/2);
    float position2x= 250 + (mysquares->sq2_pos - (mysquares->sq2_pos)/2);
    float position1y= 200 - mysquares->sq1_side;
    float position2y= 200 - mysquares->sq2_side;

    svg= "<?xml version='1.0' encoding='UTF-8' standalone='no'?> \n";
    svg+= "<svg xmlns='http://www.w3.org/2000/svg' height='300' width='500'> \n" ;
    svg+= "<polygon points='200,250 300,250 250,200' style='fill:lime;stroke:purple;stroke-width:1' />\n";  
    svg+= "<line x1='"+ to_string(xline1) + "'" + " y1='200' x2='" + to_string(xline2)+ "' y2='200' style='stroke:rgb(255,0,0);stroke-width:2' />\n";
    svg+= "<rect x='"+ to_string(position1x) +"' y='"+ to_string(position1y) +"' width='"+ to_string(mysquares->sq1_side) +"' height='"+ to_string(mysquares->sq1_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
    svg+= "<rect x='"+ to_string(position2x) +"' y='"+ to_string(position2y) +"' width='"+ to_string(mysquares->sq2_side) +"' height='"+ to_string(mysquares->sq2_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
    svg+= "</svg> \n";
    
    return svg;
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