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
    Point();

    Point(const int& x, const int& y);

    const int& x();
    const int& y();

    Point* x(int x);
    Point* y(int y);

private:

    int x1;
    int y1;
};

#endif // POINT_H
