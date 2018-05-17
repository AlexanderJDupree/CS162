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

    std::cout << line2.slope() << std::endl;
    
    return 0;
}
