#include "dateTime.h"

DateTime::DateTime(const unsigned short& unit, const int& _min, const int& max)
    : _min(_min), _max(max)
{
    if (!validate(unit))
    {
        throw invalid_datetime();
    }

    m_unit = unit;

}

// Inpsectors
const unsigned short& DateTime::unit()
{
    return m_unit;
}

// Mutators
void DateTime::unit(const unsigned short& unit)
{
    // TODO Exception maybe?
    if (validate(unit))
    {
        m_unit = unit;
    }
    return;
}

bool DateTime::add(const unsigned short& unit)
{
    if(validate(m_unit + unit))
    {
        m_unit += unit;
        return false;
    }
    
    // Rolls over m_unit to be in min/max range
    m_unit = (m_unit + unit) % _max;
    return true;
}

// Validators
bool DateTime::validate(const unsigned short& unit)
{
    return unit >= _min && unit <= _max;
}

//////////////////////////////////MONTH CLASS///////////////////////////////////

const Month::Lengths& Month::getMaxDays()
{
    return lengths[m_unit - 1];
}

void Month::leapYearAdjustment()
{
    lengths[1] = FEBRUARY_LEAP;
    return;
}

void Month::nonLeapYearAdjustment()
{
    lengths[1] = FEBRUARY;
    return;
}

//////////////////////////////////YEAR CLASS////////////////////////////////////

bool Year::isLeapYear() const
{
    return m_unit % 4 == 0 || m_unit % 400 == 0;
}
