// Implementation for Grade class

#include <cstring>
#include "Course.h"



Course::Course() : courseName(NULL), courseID(NULL) {}

Course::Course(const char* course, const char* ident, const Gradebook& grades)
{
    courseName = new char[sizeof(course) + 1];
    std::strcpy(courseName, course);

    courseID = new char[sizeof(ident) + 1];
    std::strcpy(courseID, ident);

    courseGrades = grades;
}

Course::Course(const Course& origin)
{
    // See comments under the assignment operator overload for justification
    if(origin.courseName)
    {
        courseName = new char[sizeof(origin.courseName) + 1];
        std::strcpy(courseName, origin.courseName);
    }
    if(origin.courseID)
    {
        courseID = new char[sizeof(origin.courseID) + 1];
        std::strcpy(courseID, origin.courseID);
    }
    courseGrades = origin.courseGrades;
}

Course::~Course()
{
    delete [] courseName;
    delete [] courseID;
}

// Inspectors
const char* Course::name() const
{
    return courseName;
}

const char* Course::ID() const
{
    return courseID;
}

const Gradebook& Course::grades() const
{
    return courseGrades;
}

// Mutators
Course* Course::name(const char* name)
{
    delete [] courseName;
    courseName = new char[sizeof(name) + 1];
    std::strcpy(courseName, name);
    return this;
}

Course* Course::ID(const char* ident)
{
    delete [] courseID;
    courseID = new char[sizeof(ident) + 1];
    std::strcpy(courseID, ident);
    return this;
}

Course* Course::grades(const Gradebook& courseGrades)
{
    this->courseGrades = courseGrades;
    return this;
}

// Operator Overloads
Course& Course::operator=(Course course)
{
    /* There is a whole story behind the justification for this method in this 
     fashion. After intense research behind dynamic memory and the copy-and-swap
     idiom I found this to be best practice for dealing with Classes that handle 
     dynamic memory. 
     https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom */

    swap(*this, course);

    return *this;
}