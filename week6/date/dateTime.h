/******************************************************************************
* Class: DateTime

* Description: DateTime object is the abstract base class for the Day, Month, 
*              and Year children classes. The logic behind this architecture is
*              because of the relationship between days, months, and years as 
*              units of time the contain a min/max bound. Instead of writing 
*              the same validation logic and methods 3 times I decided to write
*              it once and inherit those methods with different parameters

* Attributes and Methods:
    const int _min - represents the minimum value the DateTime unit is allowed
    const int _max - represents the maximum value the DateTime unit is allowed

    unsigned short m_unit - represents the value of the DateTime unit. I.E. 
                            3 days or 11 months or 1920 years

    struct invalid_datetime - custom exception struct that inherits from std::
                              exception

    virtual bool validate(const unsigned short& unit)
        - Precondition: 
        - Postcondition: returns true if unit argument is within the inclusive
                         min/max range

    DateTime()
        - Precondition:
        - Postcondition: Instantiates a date time object with a min/max range 
                         of 1 and a unit of 1

    DateTime(const unsigned short& unit, const int& _min, const int& _max)
        - Precondition: unit argument must be within the inclusive min/max 
                        range. Throws invalid_datetime exception if condition
                        is not met
        - Postcondition: Instantiates a date time object with the values of the
                         provided arguments

    virtual ~DateTime()
        - Precondition: 
        - Postcondition: Default destructor used

    virtual const unsigned short& unit()
        - Precondition: valid DateTime object has been created
        - Postcondition: returns a const reference to m_unit

    virtual void unit(const unsigned short& unit)
        - Precondition: unit must be within the min/max range
        - Postcondition: sets m_unit = unit ONLY if unit arguement passes 
                         validation

    virtual bool add(const unsigned short& unit)
        - Precondition: unit must be a postivie integer
        - Postcondition: adds unit to current m_unit. If that sum is higher 
                         than _max we modulo the sum by the _max and return 
                         true to represent that the units have rolled over 
                         to the beginning. 



* Modifications:

******************************************************************************/

#ifndef DATETIME_H
#define DATETIME_H

#include <exception>

class DateTime
{
public:

    // Default constructor
    DateTime() : _min(1), _max(1), m_unit() {}

    // Overloaded constructor
    DateTime(const unsigned short& unit, const int& _min, const int& _max);

    // Destructor
    virtual ~DateTime() {}

    // Inspector
    virtual const unsigned short& unit();

    // Mutator
    virtual void unit(const unsigned short& unit);

    // Member functions
    virtual bool add(const unsigned short& unit);

protected:

    const int _min;
    const int _max;

    unsigned short m_unit;

    struct invalid_datetime : std::exception
    {
        const char* error;

        invalid_datetime() : error("Invalid data for time") {}

        invalid_datetime(const char* error) : error(error) {}

        const char* what() const throw()
        {
            return error;
        }

    };

    virtual bool validate(const unsigned short& unit);

};

/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

class Day : public DateTime
{

public:
    Day() : DateTime() {}

    Day(const unsigned short& day, const int& _max) : DateTime(day, 1, _max) {}

};

/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

class Month : public DateTime
{

public:
    Month() : DateTime() {}

    Month(const unsigned short& month) : DateTime(month, 1, 12) {};

    enum Lengths
    {
        STANDARD = 31,
        SHORT = 30,
        FEBRUARY = 28,
        FEBRUARY_LEAP = 29
    };

    const Lengths& getMaxDays();

    void leapYearAdjustment();

    void nonLeapYearAdjustment();

private:

    Lengths lengths[12] = {STANDARD, FEBRUARY, STANDARD, SHORT, STANDARD, SHORT, 
                          STANDARD, STANDARD, SHORT, STANDARD, SHORT, STANDARD};

};

/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

class Year : public DateTime
{

public:
    Year() : DateTime() {}

    // TODO parameterize min/max range. 1900 - 2100 was set for to satisfy the
    // assignment conditions
    Year(const unsigned short& year) : DateTime(year, 1900, 2100) {}

    bool isLeapYear() const;

};

#endif // DATETIME_H

