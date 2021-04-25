
#include "catch2/catch2.hpp"
#include "motrice.h"

/*
TEST_CASE("init should succeed with non-zero denominator", "[fraction]") {
        
    MyFraction* frac = my_init(3,1);
    REQUIRE( frac != NULL);

    REQUIRE( frac->a == 3);
    REQUIRE( frac->b == 1);

    my_destroy(frac);    
}


TEST_CASE("my_init on zero denominator should return NULL", "[fraction]") {
    
    REQUIRE( my_init(3,0) == NULL);        
}


TEST_CASE("my_square should return a new squared fraction", "[fraction]") {

    MyFraction* orig = my_init(2,3);

    MyFraction * squared = my_square(orig);
    
    REQUIRE(squared->a == 4);
    REQUIRE(squared->b == 9);

    REQUIRE(orig->a == 2);  // should preserve original
    REQUIRE(orig->b == 3);
    
    my_destroy(squared);
    my_destroy(orig);    
}

TEST_CASE("my_div should give fraction as double", "[fraction]") {
    MyFraction* frac = my_init(1,3);    
    REQUIRE(my_div(frac) == Approx(0.3333333333));
    my_destroy(frac);
    
}


#include "cxx_examples.h"
#include "catch2/catch2.hpp"


using namespace cxx_examples;

TEST_CASE("negative square_root should throw exception ", "[cxx_examples]") {
    

    // expects std::invalid_argument exception, if it is not thrown test fails        
    REQUIRE_THROWS_AS( square_root(-1.0), std::invalid_argument);

    REQUIRE(square_root(0.0) == Approx(0.0));
}


TEST_CASE("square_root >= 0 should give positive result ", "[cxx_examples]") {
                
    REQUIRE(square_root(4.0) == Approx(2.0));
}


TEST_CASE("say_hello should produce a string ", "[cxx_examples]") {
    
    REQUIRE( cxx_examples::say_hello("peppo") == std::string("hello peppo"));        
}



*/


TEST_CASE("init should give back a non NULL pointer", "[motrice]") {
        
    MeniniDevice* device = menini_init();

    REQUIRE( device != NULL);

    delete(device);    
}



