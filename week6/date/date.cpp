#include "date.h"

Date::Date(const unsigned short& month, const unsigned short& day, 
     const unsigned short& year) 
    : m_month(new Month(month)), m_year(new Year(year))
{
    // TODO Data validation for days max parameter
    m_day = new Day(day, 30);
}

// Inspectors
const DateTime& Date::month() const
{
    return *this->m_month;
}

const DateTime& Date::day() const
{
    return *this->m_day;
}

const DateTime& Date::year() const
{
    return *this->m_year;
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

