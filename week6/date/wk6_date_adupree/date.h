/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

    Month* m_month - Pointer to Month object, represents the month
    Day* m_day - Pointer to Day object, represents the day of the month
    Year* m_year - Pointer to Year object, represents the year

    Date()
        - Precondition:
        - Postcondition: Default constructor sets date object to 1/1/1900

    Date(const unsigned short& month, const unsigned short& day, const unsigned 
         const unsigned short& year)
         -Precondition: month, day, year arguments values are within accepted
                        bounds
         -Postcondition: assigns arguments values to corresponding member 
                         variables

    ~Date() 
        - Precondition:
        - Postcondition: deletes m_month, m_day, m_year
 
    // Inspectors
    const unsigned short& month() const
        - Precondition:
        - Postcondition: returns const reference to m_month

    const unsigned short& day() const
        - Precondition:
        - Postcondition: returns const reference to m_day

    const unsigned short& year() const
        - Precondition:
        - Postcondition: returns const reference to m_year
    
    // Mutators
    Date& month(const unsigned short& month)
        - Precondition: month argument is an integer between 1-12
        - Postcondition: assigns value of month to Month objects unit member,
                         changes Day objects max value to reflect the number 
                         of days in the month

    Date& day(const unsigned short& day)
        - Precondition: day argument is an integer within the valid bounds
        - Postcondition: assigns value of day to Day objects unit member

    Date& year(const unsigned short& year);
        - Precondition: year is a integer within the valid bounds
        - Postcondition: assigns value of year to Year objects unit memeber

    // Member functions
    void addToDate(int days)
        - Precondition: days is a positive integer
        - Postcondition: adds Days to the current date, calls the setters of 
                         member objects to increment the change

    void adjustForLeapYear()
        - Precondition:
        - Postcondition: subroutine function that interacts with the Year and 
                         Month objects to adjust the max days of February to 
                         account for a leap year

    

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
