
#include "../include/catch2/catch2.hpp"
#include "../include/lever.h"
/**
 * Pol_shaft* myshaft= shaft_init(200);
 * Pol_squares* mysquares= squares_init(20 , 80 , 50 , 50);
*/

TEST_CASE("Shaft have to be bigger than 0", "[my_set constrains]") {
    REQUIRE( my_set(0,0,0,0,0) == 1);
    REQUIRE( my_set(1,0,1,0,1) == 1);   
    REQUIRE( my_set(0,1,0,1,0) == 1);  
}

TEST_CASE("Shaft smaller than 500 and Squares smaller than 300", "[my_set constrains]") {
    REQUIRE( my_set(501,301,301,301,301) == 1);
    REQUIRE( my_set(501,2,2,2,2) == 1); 
    REQUIRE( my_set(2,301,2,2,2) == 1);
    REQUIRE( my_set(2,301,301,301,301) == 1);
}

TEST_CASE("Position of the squares have to be smaller than the shaft's length / 2", "[my_set constrains]") {
    /**
     * The position of the squares have to be smaller than the shaft's length/2 otherwise the squares fall
    */
    REQUIRE(my_set(200,2,105,2,2)==1);
    REQUIRE(my_set(200,2,2,2,105)==1);
    REQUIRE(my_set(200,2,105,2,105)==1);
}

TEST_CASE("Trying correct dimensions", "[my_set constrains]") {
    /**
     * If the dimensions are inserted correctly my_set function have to return 0
    */
    REQUIRE(my_set(400,20,105,20,20)==0);
}

