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

#include <cstring>
#include "catch.hpp"
#include "grades.h"

SCENARIO("Test Grade class objects constructors", "[grades], [constructors]")
{
    GIVEN("A default Grade object")
    {
        Grades grades;

        THEN("Its members are initialized to null values")
        {
            REQUIRE(grades.getCourseName() == NULL);
            REQUIRE(grades.getCourseNumber() == NULL);
            REQUIRE(grades.getGrades() == NULL);
        }
    }
    GIVEN("Arguments for course number, name and an array of grades")
    {
        const char* courseName = "Computer Science II";
        const char* courseNumber = "CS-162";
        const unsigned int scores[] = {1, 2, 3, 4, 5};

        WHEN("A grade object is initialized to the provided arguments")
        {
            Grades grades(courseName, courseNumber, scores);

            THEN("Its members are equal to the provided arguments")
            {
                REQUIRE(strcmp(grades.getCourseName(), courseName));
            }
        }
    }
}