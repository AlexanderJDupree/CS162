/*******************************************************************************
* File: grades.h
*
* Description: 
*
* Author: Alexander DuPree
* 
* Compiler: GNU GCC 5.4.0
*
* Date: 2018 - 05 - 24
*******************************************************************************/

#ifndef GRADES_H
#define GRADES_H

class Grades
{
public:
    Grades();
    
    Grades(const char* courseName, const char* courseNumber, 
                                   const unsigned int grades[]);

    const char* getCourseName() const; 
    const char* getCourseNumber() const;
    const unsigned int* getGrades() const;


private:

    char* courseName;
    char* courseNumber;
    unsigned int* grades;

};

#endif // GRADES_H
