#include "lever.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>

using namespace std;

int main() {
    
    cout << "Inizialize a lever with" << endl;
    cout << "A Shaft with the following size:" << endl;
    cout << "- Length: 30"<< endl;
    cout << "And two squares with the following size and distance from the center of the shaft:" << endl;
    cout << "Square 1:" << endl;
    cout << "- side: 15"<< endl;
    cout << "- position: 15"<< endl;
    cout << "Square 2:" << endl;
    cout << "- side: 15"<< endl;
    cout << "- position: 15"<< endl;


    Pol_shaft* myshaft= shaft_init(200);
    Pol_squares* mysquares= squares_init(20 , 80 , 50 , 50);


    //Create a string in order to create a svg file, and this string is shown
    string svg2;
    svg2 = to_svg(myshaft, mysquares);
    cout << "Il codice svg creato è:" << endl;
    cout << svg2;


    // Create and open a text file, writing to the file the string of the svg, closing the file
    ofstream MyFile("filename.svg");
    MyFile << svg2;
    MyFile.close();



    
    //Destroy the objects
    destroyer(myshaft, mysquares);
    
    return EXIT_SUCCESS;
}