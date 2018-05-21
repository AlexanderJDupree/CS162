/*******************************************************************************
* File: triangle_tests.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 20
*******************************************************************************/

#include "catch.hpp"
#include "triangle.h"

SCENARIO("Constructing Triangle objects", "[triangle], [constructors]")
{
    GIVEN("A default triangle")
    {
        Triangle triangle;
        THEN("Its points are (0,0), (0,1), (1,0)")
        {
            REQUIRE(triangle.getPoint1() == Point(0,0));
            REQUIRE(triangle.getPoint2() == Point(0,1));
            REQUIRE(triangle.getPoint3() == Point(1, 0));
        }
    }

    GIVEN("6 integers")
    {
        int x1 = 3, y1 = 4, x2 = 8, y2 = 4, x3 = 3, y3 = 9;
    
        WHEN("A triangle is constructed from those points")
        {
            Triangle triangle(x1, y1, x2, y2, x3, y3);
            THEN("The triangles points are equal to (x1,y1)(x2,y2)(x3,y3)")
            {
                REQUIRE(triangle.getPoint1() == Point(x1, y1));
                REQUIRE(triangle.getPoint2() == Point(x2, y2));
                REQUIRE(triangle.getPoint3() == Point(x3, y3));
            }
        }
    }

    GIVEN("3 points A, B, C")
    {
        const Point A(4, 4);
        const Point B(5, 4);
        const Point C(0,0);

        WHEN("A triangle is constructed form those points")
        {
            Triangle triangle(A, B, C);
            THEN("The triangles points are equal to A, B, and C")
            {
                REQUIRE(triangle.getPoint1() == A);
                REQUIRE(triangle.getPoint2() == B);
                REQUIRE(triangle.getPoint3() == C);
            }
        }
    }
}

SCENARIO("Using Triangles mutator functions to modify member values", "[triangle], [mutators]")
{
    GIVEN("A default Triangle object and three Points A, B, C")
    {
        Triangle triangle;
        Point A(5, 4), B(6, 8), C(4, 17);

        WHEN("The mutator function is called to set point1 to Point A")
        {
            triangle.setPoint1(A.x(), A.y());

            THEN("triangles point1 equals point A")
            {
                REQUIRE(triangle.getPoint1() == A);
            }

        }
        WHEN("The mutator function is called to set point2 to Point B")
        {
            triangle.setPoint2(B.x(), B.y());

            THEN("triangles point2 equals point B")
            {
                REQUIRE(triangle.getPoint2() == B);
            }

        }
        WHEN("The mutator function is called to set point2 to Point C")
        {
            triangle.setPoint3(C.x(), C.y());

            THEN("triangles point2 equals point B")
            {
                REQUIRE(triangle.getPoint3() == C);
            }
        }
    }
}

SCENARIO("Comparing two triangle objects for equality")
{
    GIVEN("Two triangle objects with equal side lengths")
    {

    }
}