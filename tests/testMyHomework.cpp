
#include "../include/catch2/catch2.hpp"
#include "../include/lever.h"
/**
 * Pol_shaft* myshaft= shaft_init(200);
 * Pol_squares* mysquares= squares_init(20 , 80 , 50 , 50);
*/

TEST_CASE("Shaft have to be bigger than 0", "[shaft]") {
    REQUIRE( shaft_init(0) == NULL);   
    REQUIRE( shaft_init(501) == NULL);  
}

TEST_CASE("Squares side bigger than 0 and smaller than 300", "[squares]") {
    REQUIRE( squares_init(0,0,0,0) == NULL);   
    REQUIRE( squares_init(301,0,301,0) == NULL);
    REQUIRE( squares_init(301,3,301,3) == NULL);        
}

TEST_CASE("Position of the squares have to be smaller than the shaft's length / 2", "[squares and shaft]") {
    /**
     * The position of the squares have to be smaller than the shaft's length/2 otherwise the squares fall
    */
    Pol_shaft* try_myshaft= shaft_init(200);
    Pol_squares* try_mysquares= squares_init(20 , 80 , 50 , 50);
    REQUIRE(try_mysquares->sq1_pos < ((try_myshaft->s_length)/2));
    REQUIRE(try_mysquares->sq2_pos < ((try_myshaft->s_length)/2));

    destroyer(try_myshaft,try_mysquares);
}

