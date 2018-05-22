// Implementation for Point class
#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(const int& x, const int& y) : x(x), y(y) {}

const int& Point::getX() const
{
    return x;
}

const int& Point::getY() const
{
    return y;
}

Point* Point::setX(int x)
{
    this->x = x;
    return this;
}

Point* Point::setY(int y)
{
    this->y = y;
    return this;
}

// Operator Overloads
bool Point::operator==(const Point& point) const
{
    return x == point.getX() && y == point.getY();
}

bool Point::operator!=(const Point& point) const
{
    return !(*this == point);
}