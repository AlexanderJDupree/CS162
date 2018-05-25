// Implementation for Grade class

#include "grades.h"

#define NULL 0

Grades::Grades() : courseName(NULL), courseNumber(NULL), grades(NULL) {}

const char* Grades::getCourseName() const
{
    return courseName;
}

const char* Grades::getCourseNumber() const
{
    return courseNumber;
}

const unsigned int* Grades::getGrades() const
{
    return grades;
}
