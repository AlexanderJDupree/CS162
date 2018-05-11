/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

#ifndef DATE_H
#define DATE_H

#include "day.h"
#include "month.h"
#include "year.h"

class Date
{

public:

    // Default constructor
    Date() : m_month(Month(1)), m_day(1, 31), m_year(Year(1900)) {}

    // Overloaded constructor
    Date(const unsigned short& month, const unsigned short& day, 
         const unsigned short& year);
    
    // Inspectors
    const DateTime& month() const;
    const DateTime& day() const;
    const DateTime& year() const;
    
    // Mutators
    Date& month(const unsigned short& month);
    Date& day(const unsigned short& day);
    Date& year(const unsigned short& year);
    


private:
    
    DateTime* m_month;
    DateTime* m_day;
    DateTime* m_year;

};

#endif
