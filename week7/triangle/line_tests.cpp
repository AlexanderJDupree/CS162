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

#include <cmath>
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

        AND_THEN("Then point2 is equal to (0,0), a default Point object")
        {
            REQUIRE(line.point2() == point);
        }

    }

    GIVEN("Two initialized point objects, A and B")
    {
        const Point A(5,4);
        const Point B(18,-20);

        WHEN("A Line is constructed with A and B as arguments")
        {
            Line line(A, B);

            THEN("lines point1 member is equal to A")
            {
                REQUIRE(line.point1() == A);
            }

            AND_THEN("lines point2 member is equal to B")
            {
                REQUIRE(line.point2() == B);
            }

        }

    }

    GIVEN("Four Integers A, B and X, Y")
    {
        const int A = 80;
        const int B = 8;

        const int X = 7;
        const int Y = -9;

        WHEN("A line is constructed with A, B and X, Y as arguements")
        {
            Line line(A, B, X, Y);

            THEN("lines point1 member is equal to A,B")
            {
                REQUIRE(line.point1().x() == A);
                REQUIRE(line.point1().y() == B);
            }

            AND_THEN("lines point2 member is equal to X,Y")
            {
                REQUIRE(line.point2().x() == X);
                REQUIRE(line.point2().y() == Y);
            }
        }

    }
    
} 

SCENARIO("Using Inspectors to access lines point members", "[line], [inspectors]")
{
    GIVEN("A line initialized to Point A and Point B")
    {
        const Point A(-12345, 334566);
        const Point B(98767, 12345);

        Line line(A, B);

        WHEN("Lines inspector functions are called")
        {
            THEN("line.point1() is equal to A")
            {
                REQUIRE(line.point1() == A);
            }
            AND_THEN("line.point2() is equal to B")
            {
                REQUIRE(line.point2() == B);
            }
        }
    }
}

SCENARIO("Using Mutators to change the value of member Point objects", "[line], [mutators]")
{
    GIVEN("A default line and points A and B")
    {
        const Point A(234, 456);
        const Point B(4524, 459);

        Line line;

        WHEN("members point members are set to points A, B")
        {
            line.point1(A)->point2(B);

            THEN("point1 is equal to A and point2 is equal to B")
            {
                REQUIRE(line.point1() == A);
                REQUIRE(line.point2() == B);
            }
        }
    }
}

SCENARIO("Comparing two line objects for equality", "[line], [comparison], [equality]")
{
    GIVEN("two line objects initialized to equal points A and B")
    {
        const Point A(11, 22);
        const Point B(22, 33);

        Line line1(A, B);
        Line line2(A, B);

        THEN("line 1 is equal to line 2")
        {
            REQUIRE(line1 == line2);
        }

        WHEN("Either of line 1's member points are set to 0,0")
        {
            line1.point1(0,0)->point2(0,0);

            THEN("line 1 is no longer equal to line 2")
            {
                REQUIRE(line1 != line2);
            }
            AND_THEN("line 2 is greater than line 1")
            {
                REQUIRE(line2 > line1);
            }
        }

    }
}

SCENARIO("Evaluating the slope of a line", "[line], [slope]")
{
    GIVEN("A line object initialized to points A and B")
    {
        const float x1 = 15.0, y1 = 20.0, x2 = 20.0, y2 = 16.0;

        Line line(x1, y1, x2, y2);

        THEN("The slope of the line is y2 - y1 / x2 - x1")
        {
            float slope = (y2 - y1) / (x2 - x1);
            REQUIRE(line.slope() == slope);
        }

        WHEN("The slope of a line is undefined")
        {
            line.point1(x2, y2);

            THEN("slope member function returns the numeric limit for a double")
            {
                REQUIRE(line.slope() == std::numeric_limits<double>::max());
            }
        }

        AND_WHEN("The lines Y values for each point are the same")
        {
            line.point1(x1, y2);

            THEN("The slope member function returns 0 for the slope")
            {
                REQUIRE(line.slope() == 0.0);
            }
        }
    }
}

SCENARIO("Evaluating the length of a line", "[line], [length], [distance]")
{
    GIVEN("A line initialized to points A and B")
    {
        const int x1 = 5, y1 = 5, x2 = 2, y2 = 1;
        double distance = sqrt((pow((x2 - x1), 2) + pow((y2 - y1), 2)));

        Line line(x1, y1, x2, y2);

        THEN("The length of the line can be determined with Pythagoreas theorum")
        {
            REQUIRE(line.length() == distance);
            AND_WHEN("The points are switched")
            {
                line = Line(x2, y2, x1, y1);
                THEN("The distance will still be the same")
                {
                    REQUIRE(line.length() == distance);
                }
            }
        }
    }
    GIVEN("A line initialized to only one point, A")
    {
        const Point A(3, 3);
        Line line(A, A);
        THEN("The length of the line is 0")
        {
            REQUIRE(line.length() == 0);
        }
    }
}
