/*******************************************************************************
* File: triangleDriver.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#include "triangle.h"
#include <iostream>
using namespace std;

int main()
{
    Triangle myTri;
    Triangle yourTri(3,4,8,4,3,9);

    myTri.setPoint1(3,4);
    myTri.setPoint2(5,6);
    myTri.setPoint3(3,9);

    cout << "The triangle is drawn from:\n";
    cout << '(' << myTri.getPoint1().getX() << ','
         << myTri.getPoint1().getY() << ')' << " to "
         << '(' << myTri.getPoint2().getX() << ','
         << myTri.getPoint2().getY() << ')' << " to "
         << '(' << myTri.getPoint3().getX() << ','
         << myTri.getPoint3().getY() << ')' << endl << endl;

    if (myTri.rightTriangle() == true)
        cout << "That is a right triangle.\n\n";
    else
        cout << "That is not a right triangle.\n\n";

    if (yourTri.rightTriangle() == true)
        cout << "That is a right triangle.\n\n";
    else
        cout << "That is not a right triangle.\n\n";

    if (myTri == yourTri)
        cout << "The triangles are the same.\n\n";
    else
        cout << "The triangles are not the same.\n\n";

    return 0;
}