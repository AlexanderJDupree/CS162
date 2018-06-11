/*******************************************************************************
* File: intSetDriver.cpp
*
* Description: Driver program tests the methods and constructors of the 
               intSet data type. Prints what test is being performed to the 
               console, performs the test, prints result. If a test fails the
               program exits.
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 06 - 11
*******************************************************************************/

#include <iostream>
#include <cassert>
#include "intSet.h"

#define LOG(x) std::cout << x << std::endl;

int main() 
{

    LOG("Default Construction")

    IntSet intset;

    LOG("\nDefault Construction complete")

    LOG("\nOverloaded Construction")

    IntSet intset2(20);

    assert(intset2.used() == 20);
    assert(intset2[19] == 20);

    LOG("\nOverloaded Construction complete")

    LOG("\nAdd element to empty intset")

    assert(intset.addElement(3));
    assert(intset[0] == 3);

    LOG("\nAdd element successful")

    LOG("\nAdd multiple elements to intset")

    assert(intset.addElement(5, 15) == 5);
    assert(intset[5] == 15);

    LOG("\nAdd multiple elements successful")

    LOG("\nRemove last element")

    assert(intset.removeLast());
    assert(intset[5] == -1);

    LOG("\nRemove last successful")

    LOG("\nRemove first element")

    assert(intset[0] == 3);
    assert(intset.removeFirst());
    assert(intset[0] == 15);

    LOG("\nRemove first successful")

    LOG("\nFind value")

    assert(intset.findValue(15));

    LOG("\nValue found")

    LOG("\nCopy intsets")

    intset2 = intset;

    assert(intset2 == intset);

    LOG("\nintset copied")

    return 0;
}