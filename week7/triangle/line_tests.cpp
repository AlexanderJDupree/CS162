/*******************************************************************************
* File: line_tests.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 18
*******************************************************************************/

#include "catch.hpp"
#include "line.h"

////////////////////////////////////// LINE TESTS //////////////////////////////

SCENARIO("Constructing Line objects", "[line], [constructors]")
{
    GIVEN("A default line")
    {
        Line line;
        Point point;
 
        THEN("Then point1 is equal to (0,0), a default Point object")
        {
            REQUIRE(line.point1() == point);

        }

        THEN("Then point2 is equal to (0,0), a default Point object")
        {
            REQUIRE(line.point2() == point);
        }

    }
    
}
