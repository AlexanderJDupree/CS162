/*******************************************************************************
* File: lineDriver.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#include <iostream>
#include "line.h"

int main(int argc, char const *argv[])
{
    Line line1;
    Line line2(1, 1, 2, 2);


    line1.point1(Point(4,8))->point2(6, 5);
    
    float slope = line1.slope();


    return 0;
}
