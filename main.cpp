#include "lever.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>



using namespace std;

int main() {
    Pol_shaft* myshaft;
    Pol_squares* mysquares;

    float ShaftLength ;
    float SquareSide1 ;
    float SquarePos1 ;
    float SquareSide2 ;
    float SquarePos2 ;

    //Name of the svg file that you want to create, is the same file that is read
    string svgfilename= "filename.svg";

    //String that will contain the file svg readed
    string svg_readed;

    //Create a new string in order to create the new svg file with parameters selected, and this string is shown in terminal
    string svg_created;

    int c;
    int fine=1;
    do {
        cout<<"\n Choose a command. Do you want change the default sizes? Type a number :"<<endl;
        cout<< "1 - No" <<endl;
        cout<< "2 - Yes" <<endl;
        cout<< "3 - Read sizes from an already existing file" << endl;
        cout<< "Insert the option here: ";
        cin>> c;
        cout<<endl;
        switch (c) 
        {
            case 1:
                ShaftLength = 200;
                SquareSide1 = 20;
                SquarePos1 = 80;
                SquareSide2 = 50;
                SquarePos2 = 50;

                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                break;
            case 2:
                cout << "Inizialize a lever" << endl;
                cout << "A Shaft with the following size: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 500!!)" << endl;
                cout << "- Length: "<< endl;
                cin >> ShaftLength;
                cout << "The FIRST square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 300!!)" << endl;
                cin >> SquareSide1;
                cout << "The FIRST square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos1;
                cout << "The SECOND square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 300!!)" << endl;
                cin >> SquareSide2;
                cout << "The SECOND square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos2;
                
                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                break;
            case 3:
                svg_readed=read_svg (svgfilename);
                if (svg_readed=="no"){
                    cout<<"something goes wrong"<<endl;
                    fine=1;
                    break;                    
                }else{
                    cout<<"The svg file readed is:"<<endl;
                    cout<<svg_readed<<endl;
                    svg_created=svg_readed;
                    fine=0;
                    break;
                }
            default:
                cout<<"Please, enter a correct option!\n";
            break;
        }
      
    }while(fine==1);


    //The dimensions checked are now associated to the objects, creating objects
    myshaft= shaft_init(ShaftLength);
    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);



    svg_created = to_svg(myshaft, mysquares);
    cout << "The new svg code created is:" << endl;
    cout << svg_created;


    //Prints the svg string to a file called as specified in the variable svgfilename
    cout<<"The new svg string with the parameters selected is created and is now saved into a file"<<endl;
    svg_to_file(svgfilename,svg_created);
    
    
    //Destroy the objects
    destroyer(myshaft, mysquares);
    
    return EXIT_SUCCESS;
}