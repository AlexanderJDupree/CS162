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

const int& DateTime::max()
{
    return _max;
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

bool DateTime::validate(const unsigned short& unit)
{
    return unit >= _min && unit <= _max;
}
