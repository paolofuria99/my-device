#include "lever.h"

using namespace std;


int my_set(double ShaftLength, double SquareSide1, double SquarePos1, double SquareSide2, double SquarePos2){
    
    if (ShaftLength==0 || SquareSide1==0 || SquareSide2==0 || SquarePos1==0 || SquarePos2==0){
        cout<<"Dimensions have to be different than 0!!!"<<endl;
        return 1;
    }
    
    if(ShaftLength>500 || SquareSide1>300 || SquareSide2>300 || SquarePos1>300 || SquarePos2>300){
        cout<<"Dimensions have to be SMALLER than 500 for the SHAFT and SMALLER than 300 for the SQUARES!!!"<<endl;
        return 1;
    }

    if(SquarePos1>(ShaftLength/2) || SquarePos2>(ShaftLength/2)){
        cout<<"Position of the squares have to be SMALLER than HALF of the SHAFT's LENGTH"<<endl;
        return 1;
    }

    return 0;
}


Pol_shaft* shaft_init(float sLength){

    //I suppose that the shaft with length 0 can't exist; and have to be smaller than 500, in order to fit the image's width
    if(sLength==0||sLength>500){
        return NULL;
    }

    // Allocating a struct called "newshaft" like "Pol_shaft"
    Pol_shaft* newshaft = new Pol_shaft;

    // Size assignment
    newshaft->s_length = sLength;

    //Returning the object
    return newshaft;
}

Pol_squares* squares_init(float side1, float pos1, float side2, float pos2){

    //I suppose that the squares' side and position 0 or bigger than 300 can't exist in order to fit the image's width
    if(side1==0 || side2==0 ||pos1==0 || pos2==0|| side1>300 || side2>300){
        return NULL;
    }

    // Allocating a struct called "newsquares" like "Pol_squares"
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