/*******************************************************************************
* File: testCourse.cpp
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
#include <iostream>
#include <numeric>
#include "catch.hpp"
#include "course.h"

SCENARIO("Test Course class constructors", "[course], [constructors]")
{
    GIVEN("A default Course object")
    {
        Course course;

        THEN("Its members are initialized to null values")
        {
            REQUIRE(course.grades().empty());
            REQUIRE_FALSE(course.name());
            REQUIRE_FALSE(course.ID());
        }
    }
    GIVEN("Arguments for course number, name and an array of Course")
    {
        const char* COURSE_NAME = "Computer Science II";
        const char* COURSE_ID = "CS-162";
        const Gradebook SCORES = {1, 2, 3, 4, 5};

        WHEN("A course object is initialized to the provided arguments")
        {
            Course course(COURSE_NAME, COURSE_ID, SCORES);

            THEN("Its members are equal to the provided arguments")
            {
                REQUIRE(strcmp(course.name(), COURSE_NAME) == 0);
                REQUIRE(strcmp(course.ID(), COURSE_ID) == 0);
                REQUIRE(course.grades() == SCORES);
            }
        }
    }
}

SCENARIO("Test Course class mutators to change member variables", "[course], [mutators]")
{
    GIVEN("A default Course object, and constant values for a course")
    {
        Course course;
        const char* COURSE_NAME = "Integral Calculus";
        const char* COURSE_ID = "MTH-252";
        const Gradebook SCORES = {2, 3, 4, 5, 6};

        WHEN("We use a mutator to assign COURSE_NAME to courseName member")
        {
            course.name(COURSE_NAME);
            
            THEN("The course's name is equal to COURSE_NAME")
            {
                REQUIRE(strcmp(course.name(), COURSE_NAME) == 0);
            }
        }
        WHEN("We use a mutator to assign COURSE_ID to courseID member")
        {
            course.ID(COURSE_ID);

            THEN("The course's ID is equal to COURSE_ID")
            {
                REQUIRE(strcmp(course.ID(), COURSE_ID) == 0);
            }
        }
        WHEN("We use a mutator to assign SCORES to courseGrades member")
        {
            course.grades(SCORES);

            THEN("The courseGrades member reflect the SCORES vector")
            {
                REQUIRE(course.grades() == SCORES);
            }
        }
    }
}

SCENARIO("Test Course class mutators for edge cases", "[course], [mutators], [edge case]")
{
    GIVEN("An initialized Course object")
    {
        Course course("General Physics", "PH-211", Gradebook(5,100));

        WHEN("We assign an empty string to course name and ID")
        {
            course.name("");
            course.ID("");

            THEN("The course's name and ID will be empty strings")
            {
                REQUIRE(std::strlen(course.name()) == 0);
                REQUIRE(std::strlen(course.ID()) == 0);
            }
        }
        WHEN("We assign an empty vector to courseGrades")
        {
            course.grades(Gradebook());

            THEN("The course grades vector is empty")
            {
                REQUIRE(course.grades().empty());
            }
        }
    }
    // Compiler prevents assigning unitialized pointers to the constructor no need to test
}

SCENARIO("Test Course class assignment operators")
{
    GIVEN("A default Course object and an initialized Course object")
    {
        Course courseDefault;
        Course courseExplicit("Biology", "BI-121", Gradebook(4, 100));

        WHEN("The default Course object is assigned the initialized object")
        {
            courseDefault = courseExplicit;
            
            THEN("The two course objects are equal")
            {
                REQUIRE(strcmp(courseDefault.name(), courseExplicit.name()) == 0);
                REQUIRE(strcmp(courseDefault.ID(), courseExplicit.ID()) == 0);
                REQUIRE(courseDefault.grades() == courseExplicit.grades());
            }

            AND_WHEN("We reassign the initialized object to the new courseDefault")
            {
                courseExplicit = courseDefault;

                THEN("The data is not changed")
                {
                    REQUIRE(strcmp(courseDefault.name(), courseExplicit.name()) == 0);
                    REQUIRE(strcmp(courseDefault.ID(), courseExplicit.ID()) == 0);
                    REQUIRE(courseDefault.grades() == courseExplicit.grades());
                }
            }
        }
    }
    GIVEN("An initialized Course object")
    {
        Course course("Pre-Calculus", "MTH112", Gradebook(6, 100));

        WHEN("The initialized object is reassigned to a default object")
        {
            course = Course();

            THEN("course now mirrors the defaults values")
            {
                REQUIRE(course.grades().empty());
                REQUIRE_FALSE(course.name());
                REQUIRE_FALSE(course.ID());
            }
        }
    }
}

SCENARIO("Testing Friend functions for highest and averages for the grades", "[course], [friend]")
{
    GIVEN("A Course object initialized to an array of grades")
    {
        Gradebook grades = {25, 35, 45, 55, 66, 88, 99};
        Course course("Calculus", "MTH251", grades);

        THEN("The findHighest friend function returns the highest value")
        {
            REQUIRE(findHighest(course) == 99);
        }
        THEN("The average grade will be the sum of the array / number of grades")
        {
            double sum = std::accumulate(grades.begin(), grades.end(), 0.0);
            double average = sum / grades.size();

            REQUIRE(findMean(course) == average);

        }
    }
}