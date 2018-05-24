/*******************************************************************************
* File: testGrades.cpp
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 24
*******************************************************************************/

#include "catch.hpp"
#include "grades.h"

SCENARIO("Test Grade class objects constructors")
{
    GIVEN("A default Grade object")
    {
        Grades grades;
        THEN("Its members are initialized to null values")
        {
            REQUIRE(grades.getCourseName == NULL);
            //REQUIRE(grades.courseNumber == "");
            //REQUIRE(grades.getGrades == NULL);


        }
    }
}