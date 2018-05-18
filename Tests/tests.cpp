/*******************************************************************************
* File: tests.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 17
*******************************************************************************/

#include "catch.hpp"

int add(const int& a, const int& b)
{
    return a + b;
}

TEST_CASE( "add sums a + b")
{
    REQUIRE(add(2,2) == 4);
}
