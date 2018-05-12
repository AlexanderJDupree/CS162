/*******************************************************************************
* File: testDate.cpp
* Description:  
* Author: Alexander DuPree
* Compiler:  GNU GCC 5.4.0
* Date: 2018-05-10
*******************************************************************************/

#include <iostream>
#include "date.h"

void printDate(const Date& date);

int main()
{
    Date date(9, 11, 1991);

    printDate(date);

    date.addToDate(2);

    printDate(date);
 
    date.addToDate(20);

    printDate(date);
 
    date.addToDate(100);

    printDate(date);
     
    return 0;
}

void printDate(const Date& date)
{
    std::cout << date.month() << '/' << date.day() << '/' << date.year()
              << std::endl;
    return;

}
