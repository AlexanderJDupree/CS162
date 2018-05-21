/*******************************************************************************
* File: triangle.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 20
*******************************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <exception>
#include "line.h"


class Triangle
{
public:

    Triangle();

    Triangle(int x1, int y1, int x2, int y2, int x3, int y3);

    Triangle(const Point& pointA, const Point& pointB, const Point& pointC);

    // Accessors
    const Point& getPoint1() const;
    const Point& getPoint2() const;
    const Point& getPoint3() const;

    // Mutators
    Triangle* setPoint1(const int& x, const int& y);
    Triangle* setPoint2(const int& x, const int& y);
    Triangle* setPoint3(const int& x, const int& y);

private:

    Point point1;
    Point point2;
    Point point3;

    // Validators
    bool validate() const;

};




#endif // TRIANGLE_H