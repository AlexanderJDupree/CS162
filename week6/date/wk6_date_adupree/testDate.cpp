/*******************************************************************************
* File: testDate.cpp
*
* Description: Program uses assert to test that the date object has valid 
*              constructors, getters, setters, and member functions
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 16
*******************************************************************************/

#include <iostream>
#include <cassert>
#include "date.h"

void printDate(const Date& date);

int main()
{
    const int MONTH = 9;
    const int DAY = 11; 
    const int YEAR = 1991;
    const int LEAP_MONTH = 2;
    const int LEAP_DAY = 20;
    const int LEAP_YEAR = 2000;

    Date date(MONTH, DAY, YEAR);

    // test construction was succesfull and getters
    assert(date.month() == MONTH);
    assert(date.day() == DAY);
    assert(date.year() == YEAR);

    printDate(date);

    date.addToDate(150);

    // test addToDate(), 2/8/1992 is 150 days from 9/11/91
    assert(date.month() == 2);
    assert(date.day() == 8);
    assert(date.year() == 1992);

    printDate(date);

    // Use setters
    date.month(LEAP_MONTH).day(LEAP_DAY).year(LEAP_YEAR);

    // test setters
    assert(date.month() == LEAP_MONTH);
    assert(date.day() == LEAP_DAY);
    assert(date.year() == LEAP_YEAR);

    printDate(date);

    date.addToDate(9);

    // Leap year test
    assert(date.day() == LEAP_DAY + 9);

    printDate(date);

    date.addToDate(365);

    // test leap year and rollover properties of day,month and year class
    assert(date.day() == LEAP_DAY + 8);
    assert(date.month() == LEAP_MONTH);
    assert(date.year() == LEAP_YEAR + 1);

    printDate(date);
     
    return 0;
}

void printDate(const Date& date)
{
    std::cout << date.month() << '/' << date.day() << '/' << date.year()
              << std::endl;
    return;

}
