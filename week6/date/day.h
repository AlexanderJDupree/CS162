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

    Day(const unsigned short& day, const int& _max) : DateTime(day, 1, _max) {}

};

#endif // DAY_H
