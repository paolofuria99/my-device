#include <iostream>
#include "lever.h"

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


    shaft_init(30);
    squares_init(15, 15, 15, 15);


    
    return 0;
}