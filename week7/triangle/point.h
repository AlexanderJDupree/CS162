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
    const int& x() const;
    const int& y() const;

    // Mutators
    Point* x(int x);
    Point* y(int y);

    // Operator Overloads
    bool operator==(const Point& point);

private:

    int x1;
    int y1;

};

#endif // POINT_H
