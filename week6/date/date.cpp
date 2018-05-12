#include "date.h"

Date::Date(const unsigned short& month, const unsigned short& day, 
     const unsigned short& year) 
    : m_month(new Month(month)), m_year(new Year(year))
{
    // TODO Data validation for days max parameter
    m_day = new Day(day, offsets[month - 1] + STANDARD_MONTH);
}

Date::~Date()
{
    delete m_month;
    delete m_day;
    delete m_year;
}

// Inspectors
const unsigned short& Date::month() const
{
    return m_month->unit();
}

const unsigned short& Date::day() const
{
    return m_day->unit();
}

const unsigned short& Date::year() const
{
    return m_year->unit();
}

// Mutators
Date& Date::month(const unsigned short& month)
{
    m_month->unit(month);
    return *this;
}

Date& Date::day(const unsigned short& day)
{
    m_day->unit(day);
    return *this;
}

Date& Date::year(const unsigned short& year)
{
    m_year->unit(year);
    return *this;
}

void Date::addToDate(int days)
{
    while (days > 0)
    {
        if (m_day->add(1))
        {
            delete m_day;
            m_day = new Day(1, offsets[m_month->unit()] + STANDARD_MONTH);
                
            // Only executes if days has rolled over
            if (m_month->add(1))
            {
                // Only executes if months has rolled over
                if (m_year->add(1))
                {
                    // TODO modify offsets for leap years
                    // TODO, year is out of bounds and has reset
                }
            }
        }

        --days;

    }
    return;
}


