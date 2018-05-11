/******************************************************************************
* Class: Date

* Description:

* Attributes and Methods:

* Modifications:

******************************************************************************/

#ifndef DAY_H
#define DAY_H

#include "dateTime.h"

class Day : public DateTime
{

public:
    Day() : DateTime() {}

    Day(const unsigned short& year, const int& _max) : DateTime(year, 1, _max) {}

};

#endif // DAY_H
