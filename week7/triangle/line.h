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
    float slope();
    
    // Operator Overloads
    bool operator == (const Line& line);

private:

    Point m_point1;
    Point m_point2;

};

#endif // LINE_H
