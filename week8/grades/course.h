/*******************************************************************************
* File: Course.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 24
*******************************************************************************/

#ifndef Course_H
#define Course_H

#include <vector>

typedef std::vector<unsigned int> Gradebook;

class Course
{
public:
    // Constructors
    Course();

    Course(const char* course, const char* ident, const Gradebook& grades);

    Course(const Course& origin);

    // Destructor
    ~Course();

    // Inspectors
    const char* name() const; 
    const char* ID() const;
    const Gradebook& grades() const;

    // Mutators
    Course* name(const char* name);
    Course* ID(const char* ident);
    Course* grades(const Gradebook& courseGrades);

    // Operator Overloads
    Course& operator=(Course course);

    // Swap functionality for assignment operator
    friend void swap(Course& newCourse, Course& oldCourse) throw();

    // Friend functions
    friend unsigned int findHighest(const Course& course);
    friend double findMean(const Course& course);

private:

    char* courseName;
    char* courseID;
    Gradebook courseGrades;

};

#endif // Course_H
