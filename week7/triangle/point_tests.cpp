/*******************************************************************************
* File: tests.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#include "catch.hpp"
#include "point.h"

////////////////////////////////POINT TESTS////////////////////////////////////

SCENARIO("Constructing point objects", "[point], [constructors]")
{
    GIVEN("A default Point")
    {
        Point point;
        
        THEN("The X and Y values are initialzed to 0")
        {
            REQUIRE(point.x() == 0);
            REQUIRE(point.y() == 0);
        }

    }

    GIVEN("A Point initialzed to specific values")
    {
        const int x = 5;
        const int y = 2;
        Point point(x, y);
        
        THEN("The X and Y values match the initializer values")
        {
            REQUIRE(point.x() == x);
            REQUIRE(point.y() == y);
        }
    }
}

SCENARIO("Using Inspectors to access points X and Y values", "[point], [inspectors]")
{
    GIVEN("A point initialized to (A, B)")
    {
        const int A = 6;
        const int B = 7;
        Point point(A, B);

        THEN("point.x() returns A")
        {
            REQUIRE(point.x() == A);
        }
        THEN("point.y() returns B")
        {
            REQUIRE(point.y() == B);
        }
    }

}

SCENARIO("Using Mutators to set the X and Y values for Point", "[point], [mutators]")
{
    Point point;

    GIVEN("A default point")
    {

        WHEN("the x value is set to A")
        {
            const int A = 8;
            point.x(A);

            THEN("point.x() returns A")
            {
                REQUIRE(point.x() == A);
            }
        }

        WHEN("The y value is set to B")
        {
            const int B = 9;
            point.y(B);

            THEN("point.y() returns B")
            {
                REQUIRE(point.y() == B);
            }
        }

        GIVEN("The values of A and B in sequence")
        {
            WHEN("Chained mutators are used to set X and Y to A and B")
            {
                const int A = 5;
                const int B = 4;
                point.x(5)->y(4);

                THEN("point.x() and point.y() equals A and B respectively")
                {
                    REQUIRE(point.x() == A);
                    REQUIRE(point.y() == B);
                }
            }
        }

    }
}

SCENARIO("Given two Point objects", "[point], [comparison], [equality]")
{
    Point point1;
    Point point2;

    GIVEN("Both points are initialized to the same values for X and Y")
    {
        THEN("point1 and point2 are equal to each other")
        {
            REQUIRE(point1 == point2);
        }
    }

    WHEN("Either points values are changed")
    {
        point1 = Point(4,17);

        THEN("The two points are no longer equal")
        {
            REQUIRE(point1 != point2);
        }
    }

}
///////////////////////////////// END POINT TESTS //////////////////////////////
