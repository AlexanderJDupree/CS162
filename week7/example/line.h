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

    Line(Point point1, Point point2);

    Line(int x1, int y1, int x2, int y2);

    ~Line() {}
    
    //Accessors
    const Point& point1() const;
    const Point& point2() const;

    // Mutators
    Line* point1(Point point);
    Line* point1(int x, int y);
    Line* point2(Point point);
    Line* point2(int x, int y);

    // Member functions
    float slope();
    
    // Operator Overloads
    bool operator == (const Line& line);

private:

    Point m_point1;
    Point m_point2;

};

#endif // LINE_H
