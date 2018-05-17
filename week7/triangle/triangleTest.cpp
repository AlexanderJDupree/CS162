/*******************************************************************************
* File: triangleTest.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#include <iostream>
#include <cassert>
#include "point.h"
#include "line.h"

void TEST_POINT();
void TEST_LINE();
void TEST_ALL();

int main()
{
    TEST_ALL();
    return 0;
}

void TEST_ALL()
{
    TEST_POINT();
    TEST_LINE();
}

void TEST_POINT()
{
    Point point;
    assert(point.x() == 0 && point.y() == 0);

    Point point2(-2, 5);
    assert(point2.x() == -2 && point2.y() == 5);

    point.x(-2)->y(5);
    assert(point == point2);
    return;
}

void TEST_LINE()
{
    Line line;
    Point point;
    Point point2;
    assert(point == line.point1() && point == line.point2());

    point = Point(4, 4);
    point2 = Point(7, 2);

    line = Line(point, point);
    assert(point == line.point1() && point == line.point2());

    line.point2(point2);
    line.point1(2, 2);
    assert(point2 == line.point2() && Point(2, 2) == line.point1());

    return;
}
