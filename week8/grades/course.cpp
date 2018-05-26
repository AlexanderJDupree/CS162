// Implementation for Grade class

#include <cstring>
#include "course.h"

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
    /*Copy and swap idiom is used for defining our copy assignment. Heres a link
      to a great write up about why we need to define assignment like this
     https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom*/

    swap(*this, course);

    return *this;
}

void swap(Course& newCourse, Course& oldCourse) throw() // nothrow
{
        // Enables Argument dependent lookup
        using std::swap;

        // Swaps pointers, reassigns ownership
        swap(newCourse.courseName, oldCourse.courseName);
        swap(newCourse.courseID, oldCourse.courseID);
        newCourse.courseGrades.swap(oldCourse.courseGrades);
        return;
}

// Friend functions
unsigned int findHighest(const Course& course)
{
    unsigned int highest = 0;
    Gradebook::const_iterator it;
    for (it = course.courseGrades.begin(); it != course.courseGrades.end(); ++it)
    {
        if(*it > highest)
        {
            highest = *it;
        }
    }
    return highest;
}

double findMean(const Course& course)
{
    double sum = 0;
    Gradebook::const_iterator it;
    for (it = course.courseGrades.begin(); it != course.courseGrades.end(); ++it)
    {
        sum += *it;
    }
    return sum / course.courseGrades.size();
}