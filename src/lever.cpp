#include "lever.h"

using namespace std;


int my_set(double ShaftLength, double SquareSide1, double SquarePos1, double SquareSide2, double SquarePos2){
    
    if (ShaftLength==0 || SquareSide1==0 || SquareSide2==0 || SquarePos1==0 || SquarePos2==0){
        cout<<"\n Dimensions have to be different than 0!!!"<<endl;
        return 1;
    }
    
    if(ShaftLength>500){
        cout<<"\n Dimension of the shaft have to be SMALLER than 500!!!"<<endl;
        return 1;
    }

    if(SquarePos1>(ShaftLength/2) || SquarePos2>(ShaftLength/2)){
        cout<<"\n Position of the squares have to be SMALLER than HALF of the SHAFT's LENGTH"<<endl;
        return 1;
    }

    if(SquareSide1>(ShaftLength/2) || SquareSide2>(ShaftLength/2)){
        cout<<"\n Sides of the squares have to be SMALLER than HALF of the SHAFT's LENGTH"<<endl;
        return 1;
    }

    return 0;
}


Pol_shaft* shaft_init(float sLength){

    // Allocating a struct called "newshaft" like "Pol_shaft"
    Pol_shaft* newshaft = new Pol_shaft;

    // Size assignment
    newshaft->s_length = sLength;

    //Returning the object
    return newshaft;
}


Pol_squares* squares_init(float side1, float pos1, float side2, float pos2){

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
    float position1y= 250 - mysquares->sq1_side;
    float position2y= 250 - mysquares->sq2_side;

    svg= "<?xml version='1.0' encoding='UTF-8' standalone='no'?> \n";
    svg+= "<svg xmlns='http://www.w3.org/2000/svg' height='300' width='500'> \n" ;
    svg+= "<polygon points='200,300 250,250 300,300' style='fill:lime;stroke:purple;stroke-width:1' />\n";  
    svg+= "<line x1='"+ to_string(xline1) + "'" + " y1='250' x2='" + to_string(xline2)+ "' y2='250' style='stroke:rgb(255,0,0);stroke-width:2' />\n";
    svg+= "<rect x='"+ to_string(position1x) +"' y='"+ to_string(position1y) +"' width='"+ to_string(mysquares->sq1_side) +"' height='"+ to_string(mysquares->sq1_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
    svg+= "<rect x='"+ to_string(position2x) +"' y='"+ to_string(position2y) +"' width='"+ to_string(mysquares->sq2_side) +"' height='"+ to_string(mysquares->sq2_side) +"' style='fill:blue;stroke:black;stroke-width:1' />\n";
    svg+= "</svg> \n";
    
    return svg;
}


void svg_to_file(string filename, string str_svg){

    // Create and open a text file, writing to the file the string of the svg, closing the file
    ofstream MyFile(filename);
    MyFile << str_svg;
    MyFile.close();
}


string read_svg (string filename){

    // Read from the text file
    ifstream MyReadFile(filename);
    stringstream buffer;
    //Create a text string, which is used to output the text file
    string myText;

    if (MyReadFile.is_open()){
        buffer << MyReadFile.rdbuf();
        // Create a text string, which is used to output the text file
        myText = buffer.str();
    }else{
        cout << "Unable to open file, maybe the file's name is wrong!"<<endl;
        return "no";
    }

    return myText; 
}


// //check if number or string
// bool check_number(string str_ch) {
//     for (int i = 0; i < str_ch.length(); i++)
//     if (isdigit(str_ch[i]) == false){
//        return false;
//     }else{
//         return true;
//     }
// }


void destroyer(Pol_shaft * myshaft, Pol_squares * mysquares){
    if (myshaft != NULL && mysquares!=NULL){
        delete myshaft;
        delete mysquares;
    }

}

