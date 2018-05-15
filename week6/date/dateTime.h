/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

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

