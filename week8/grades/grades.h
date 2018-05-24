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

    const char* getCourseName() const { return courseName; } 

private:

    const char* courseName;

};

#endif // GRADES_H