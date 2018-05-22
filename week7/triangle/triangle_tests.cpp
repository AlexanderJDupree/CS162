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
            Line oldSide1 = triangle.getSide1() ;
            Line oldSide3 = triangle.getSide3();
            triangle.setPoint1(A.x(), A.y());

            THEN("triangles point1 equals point A")
            {
                REQUIRE(triangle.getPoint1() == A);
            }
            AND_THEN("The lengths of side 1 and 3 have been adjusted")
            {
                REQUIRE(oldSide1 != triangle.getSide1());
                REQUIRE(oldSide3 != triangle.getSide3());
            }

        }
        WHEN("The mutator function is called to set point2 to Point B")
        {
            Line oldSide2 = triangle.getSide2() ;
            Line oldSide1 = triangle.getSide1();
            triangle.setPoint2(B.x(), B.y());

            THEN("triangles point2 equals point B")
            {
                REQUIRE(triangle.getPoint2() == B);
            }
            AND_THEN("The lengths of side 1 and 3 have been adjusted")
            {
                REQUIRE(oldSide2 != triangle.getSide2());
                REQUIRE(oldSide1 != triangle.getSide1());
            }


        }
        WHEN("The mutator function is called to set point2 to Point C")
        {
            Line oldSide2 = triangle.getSide2() ;
            Line oldSide3 = triangle.getSide3();
            triangle.setPoint3(C.x(), C.y());

            THEN("triangles point2 equals point B")
            {
                REQUIRE(triangle.getPoint3() == C);
            }
            AND_THEN("The lengths of side 1 and 3 have been adjusted")
            {
                REQUIRE(oldSide2 != triangle.getSide2());
                REQUIRE(oldSide3 != triangle.getSide3());
            }
        }
    }
}

SCENARIO("Comparing two triangle objects for equality", "[triangle], [comparison], [equality]")
{
    GIVEN("Two triangle objects with equal side lengths")
    {
        Triangle triangle1;
        Triangle triangle2;

        THEN("The triangles are equal")
        {
            REQUIRE(triangle1 == triangle2);
        }
    }
    GIVEN("Two triangle objects with different side lengths")
    {
        Triangle triangle1;
        Triangle triangle2(1, 3, 5, 4, 14, 11);

        THEN("The triangles are NOT equal")
        {
            REQUIRE(triangle1 != triangle2);
        }
    }
    GIVEN("Two congruent triangles")
    {
        Triangle triangle1(0, 2, 2, 0, 4, 0);

        WHEN("triangle 2 is reflected over the x axis")
        {
            Triangle triangle2(0, 2, -2, 0, -4, 0);
            THEN("The triangles are still equal")
            {
                REQUIRE(triangle1 == triangle2);
            }
        }
        WHEN("triangle 2 is reflected over the Y axis")
        {
            Triangle triangle2(0, -2, 2, 0, 4, 0);
            THEN("The triangles are still equal")
            {
                REQUIRE(triangle1 == triangle2);
            }
        }
        WHEN("triangle 2 is built in reverse order")
        {
            Triangle triangle2(4, 0, 2, 0, 0, 2);
            THEN("The triangles are still equal")
            {
                REQUIRE(triangle1 == triangle2);
            }
        }
    }
}

SCENARIO("Testing a triangle is a right triangle", "[triangle], [right], [bool]")
{
    GIVEN("An Isoceles Right Triangle")
    {
        Triangle triangle(0, 0, 0, 4, 4, 0);
        THEN("The triangle returns true because it is a right triangle")
        {
            REQUIRE(triangle.rightTriangle() == true);
        }
    }
    GIVEN("A non-right triangle")
    {
        Triangle triangle(0, 2, -2, 0, -4, 0);
        THEN("The triangle returns false, it is not a right triangle")
        {
            REQUIRE(triangle.rightTriangle() == false);
        }
    }
    GIVEN("A scalene right triangle")
    {
        Triangle triangle(20, 20, 32, 14, 40, 30);
        THEN("The triangle returns true, it is a right triangle")
        {
            REQUIRE(triangle.rightTriangle() == true);
        }
    }
}