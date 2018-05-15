/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

#ifndef DATE_H
#define DATE_H

#include "dateTime.h"

class Date
{

public:

    // Default constructor
    Date() : m_month(new Month(1)), m_day(new Day(1, 31)), m_year(new Year(1900)) {}

    // Overloaded constructor
    Date(const unsigned short& month, const unsigned short& day, 
         const unsigned short& year);

    // Destructor
    ~Date();
    
    // Inspectors
    const unsigned short& month() const;
    const unsigned short& day() const;
    const unsigned short& year() const;
    
    // Mutators
    Date& month(const unsigned short& month);
    Date& day(const unsigned short& day);
    Date& year(const unsigned short& year);

    // Member functions
    void addToDate(int days);

private:
    
    Month* m_month;
    Day* m_day;
    Year* m_year;

    void adjustForLeapYear();
};

#endif
