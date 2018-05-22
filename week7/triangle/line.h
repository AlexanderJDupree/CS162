/*******************************************************************************
* File: line.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#ifndef LINE_H
#define LINE_H

#include <exception>
#include <limits>
#include <cmath>
#include "point.h"

class Line
{
public:

    Line();

    Line(const Point& point1, const Point& point2);

    Line(const int& x1, const int& y1, const int& x2, const int& y2);
    
    //Accessors
    const Point& point1() const;
    const Point& point2() const;

    // Mutators
    Line* point1(const Point& point);
    Line* point2(const Point& point);

    Line* point1(const int& x, const int& y);
    Line* point2(const int& x, const int& y);

    // Member functions
    double slope() const;
    double length() const;

    
    // Operator Overloads
    bool operator == (const Line& line) const;
    bool operator != (const Line& line) const;
    bool operator < (const Line& line) const;
    bool operator > (const Line& line) const;

private:

    Point m_point1;
    Point m_point2;

    static const double UNDEFINED;

};

#endif // LINE_H
