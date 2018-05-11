/*******************************************************************************
* File: testDate.cpp
* Description:  
* Author: Alexander DuPree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-05-10
*******************************************************************************/

#include <iostream>
#include "month.h"
#include "year.h"

int main()
{
    
    DateTime* month = new Month(10);

    std::cout << month->unit() << std::endl;

    month->unit(2);

    std::cout << month->unit() << std::endl;

    month->add(31);

    std::cout << month->unit() << std::endl;

    
    return 0;
}
