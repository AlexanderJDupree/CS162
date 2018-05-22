/*******************************************************************************
* File: point.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#ifndef POINT_H
#define POINT_H

class Point
{
public:
    // Default Constructor
    Point();

    // Overloaded Constructor
    Point(const int& x, const int& y);

    // Inspectors
    const int& getX() const;
    const int& getY() const;

    // Mutators
    Point* setX(int x);
    Point* setY(int y);

    // Operator Overloads
    bool operator==(const Point& point) const;
    bool operator!=(const Point& point) const;

private:

    int x;
    int y;

};

#endif // POINT_H
