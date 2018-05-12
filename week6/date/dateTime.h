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

    DateTime() : _min(1), _max(1), m_unit() {}

    DateTime(const unsigned short& unit, const int& _min, const int& _max);

    virtual ~DateTime() {}

    // Inspector
    virtual const unsigned short& unit();
    virtual const int& max();

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

private:

    virtual bool validate(const unsigned short& unit);

};

#endif // DATETIME_H
