/*******************************************************************************
* File: wk3_pointersArea_adupree.cpp
*
* Description: 
*   Write a program that computes the area of a rectangle, using only pointer 
*   variables.
*
*   The program should declare pointers for the width, length and area. The user
*   should input the values for width and length. After computing the area, the 
*   program should output the area.
*
*   DO NOT USE ANY "regular" variables.
*
*   There should be separate functions for sideInput (called twice), 
*   computeArea, and showArea.
*
* Author: Alexander DuPree

* Compiler:  GNU GCC 5.4.0
*
* Date: 2018-04-19
*
* Modifications:
*******************************************************************************/

#include <iostream>

struct Rectangle
{
    int* base;
    int* height;
    int* Area;

    // Default Constructor
    Rectangle() : base(NULL), height(NULL) {
        Area = NULL;
    }

    // Initializer Constructor
    Rectangle(int x, int y) 
    {
        base = new int;
        height = new int;
        Area = new int;

        *base = x;
        *height = y;
        *Area = (*base) * (*height);
    }
};

void resetInputStream();

int main()
{
    return 0;
}

void resetInputStream()
{
    // clears failure state
    std::cin.clear();
    // discard bad characters 
    std::cin.ignore(100, '\n');

    return;
}

