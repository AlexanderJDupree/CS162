// Implementation for Point class
#include "point.h"

Point::Point() : x1(0), y1(0) {}

Point::Point(const int& x, const int& y) : x1(x), y1(y) {}

const int& Point::x() const
{
    return x1;
}

const int& Point::y() const
{
    return y1;
}

Point* Point::x(int x)
{
    x1 = x;
    return this;
}

Point* Point::y(int y)
{
    y1 = y;
    return this;
}

// Operator Overloads
bool Point::operator == (const Point& point)
{
    return point.x() == x1 && point.y() == y1;
}