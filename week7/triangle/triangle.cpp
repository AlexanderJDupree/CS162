// Implementation for Triangle class

#include "triangle.h"

Triangle::Triangle() 
    : point1(Point(0,0)), point2(Point(0,1)), point3(Point(1,0)) {}

Triangle::Triangle(int x1, int y1, int x2, int y2, int x3, int y3)
    : point1(Point(x1, y1)), point2(Point(x2, y2)), point3(Point(x3, y3)) {}

Triangle::Triangle(const Point& pointA, const Point& pointB, const Point& pointC)
    : point1(pointA), point2(pointB), point3(pointC) {}

// Inspectors
const Point& Triangle::getPoint1() const
{
    return point1;
}

const Point& Triangle::getPoint2() const
{
    return point2;
}

const Point& Triangle::getPoint3() const
{
    return point3;
}

// Mutators
Triangle* Triangle::setPoint1(const int& x, const int& y)
{
    point1.x(x)->y(y);
    return this;
}

Triangle* Triangle::setPoint2(const int& x, const int& y)
{
    point2.x(x)->y(y);
    return this;
}

Triangle* Triangle::setPoint3(const int& x, const int& y)
{
    point3.x(x)->y(y);
    return this;
}

// Validators
bool Triangle::validate() const
{
    return true;
}