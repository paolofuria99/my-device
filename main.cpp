#include "lever.h"

#include <iostream>
#include <fstream>
#include <streambuf>
#include <string>
#include <sstream>



using namespace std;

int main() {
    
    //Objects that are checked. 
    Pol_shaft* myshaft = new Pol_shaft;
    Pol_squares* mysquares= new Pol_squares;


    //Objects that have to be checked. Object not checked
    Pol_shaft* tryshaft= new Pol_shaft;
    Pol_squares* trysquares= new Pol_squares;


    //Default parameters
    float ShaftLength=200 ;
    float SquareSide1=20 ;
    float SquarePos1=80 ;
    float SquareSide2=50 ;
    float SquarePos2=50;

    //Name of the svg file that you want to create, is the same file that is read
    string svgfilename= "filename.svg";

    //String that will contain the file svg readed
    string svg_readed;

    //Create a new string in order to create the new svg file with parameters selected, and this string is shown in terminal
    string svg_created;

    int c;
    int fine=2;
    do {
        cout<<"\n Choose a command. Do you want change the default sizes? Type a number :"<<endl;
        cout<< "1 - No" <<endl;
        cout<< "2 - Yes" <<endl;
        cout<< "3 - Read sizes from an already existing file and storing them" << endl;
        cout<< "9 - to quit/end the program"<<endl;
        cout<< "Insert the option here: ";
        
        /**I found online this formula that checks if the input is correct.. 
         * example, it will fail if the input is a letter or not an integer (float, double..)
        */
        while(!(cin>> c)){
            cout<<"\n ERROR: an integer must be entered:";
            cin.clear();
            cin.ignore(132, '\n');
        }
        cout<<endl;
        cout<<"DEBUG:" << c << "\n" << endl;
        
        switch (c) 
        {
            case 1:
                //Parameters are sets to default
                ShaftLength=200 ;
                SquareSide1=20 ;
                SquarePos1=80 ;
                SquareSide2=50 ;
                SquarePos2=50;

                //Checking dimensions
                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                    
                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
                break;

            case 2:
                cout << "Inizialize a lever" << endl;
                cout << "A Shaft with the following size: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN 500!!)" << endl;
                cout << "- Length: "<< endl;
                cin >> ShaftLength;
                cout << "The FIRST square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide1;
                cout << "The FIRST square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos1;
                cout << "The SECOND square SIDE: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquareSide2;
                cout << "The SECOND square POSITION: (HAVE TO BE BIGGER THAN 0 AND SMALLER THAN THE HALF LENGTH OF THE SHAFT!!)" << endl;
                cin >> SquarePos2;
                
                //Dimensions are checked
                fine=my_set(ShaftLength, SquareSide1, SquarePos1, SquareSide2, SquarePos2);
                if (fine==0){
                    cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;
                    //The dimensions checked are now associated to the objects, creating objects
                    myshaft= shaft_init(ShaftLength);
                    mysquares= squares_init(SquareSide1 , SquarePos1 , SquareSide2 , SquarePos2);
                }
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
                    
                    //New objects, NOT checked, that are created from the file readed
                    tryshaft= shaft_from_svg(svg_readed);
                    trysquares= squares_from_svg(svg_readed);

                    //Check of variables readed
                    fine=my_set(tryshaft->s_length, trysquares->sq1_side, trysquares->sq1_pos, trysquares->sq2_side, trysquares->sq2_pos);
                    if(fine==0){ 
                        cout<<"\n DEBUG: Dimensions checked.. Creating objects.."<<endl;           
                        //New objects, checked, that are created from the file readed
                        myshaft=tryshaft;
                        mysquares=trysquares;
                    }
                    
                    break;
                }
            case 9:
                fine=0;
                return EXIT_SUCCESS;
            default:
                cout<<"\n Please, enter a correct option!\n";
                fine=1;
                break;
        }
      
    }while(fine==1);

    //Is now created a string for a svg file with the dimesions that are given
    svg_created = to_svg(myshaft, mysquares);
    cout << "\n The new svg code created is:" << endl;
    cout << svg_created;


    //Prints the svg string to a file called as specified in the variable svgfilename
    cout<<"\nThe new svg string with the parameters selected is created and is now saved into a file\n"<<endl;
    svg_to_file(svgfilename,svg_created);
    
    
    //Destroy the objects
    destroyer(myshaft, mysquares);
    
    return EXIT_SUCCESS;
}